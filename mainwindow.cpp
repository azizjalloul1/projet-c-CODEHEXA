#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "examen.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <utility>
#include <QtCharts>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->matmod->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivmod->addItems({"Primaire", "Collège", "Lycée", "Université"});

    ui->matajout->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivajout->addItems({"Primaire", "Collège", "Lycée", "Université"});


    ui->triComboBox->addItem("Trier par ID croissant");
    ui->triComboBox->addItem("Trier par ID décroissant");
    ui->triComboBox->addItem("Trier par Date");



    remplirCombo();


    afficherExamens();


    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::ajouterExamen);


    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::modifierExamen);
    connect(ui->codemod, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &MainWindow::modif);

    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::supprimerExamen);


    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::ExporterPDF);

    connect(ui->upload, &QPushButton::clicked, this, &MainWindow::uploadPDF);

    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::CHERCHER);

    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::Statistiques);


    connect(ui->codebar, &QPushButton::clicked, this, &MainWindow::QRCode);

    connect(ui->triComboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&MainWindow::TriCombo);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//AFFICHER

void MainWindow::afficherExamens()
{
    QList<Examen> examens = Examen::afficherExamens();
    ui->tabaffiche->setRowCount(0);

    ui->tabaffiche->setColumnCount(7);
    ui->tabaffiche->setHorizontalHeaderLabels({"Code", "Matière", "Niveau", "Date", "Heure", "Quantité", "PDF"});

    for (int i = 0; i < examens.size(); ++i) {
        ui->tabaffiche->insertRow(i);
        ui->tabaffiche->setItem(i, 0, new QTableWidgetItem(examens[i].getCodeExamen()));
        ui->tabaffiche->setItem(i, 1, new QTableWidgetItem(examens[i].getMatiere()));
        ui->tabaffiche->setItem(i, 2, new QTableWidgetItem(examens[i].getNiveau()));
        ui->tabaffiche->setItem(i, 3, new QTableWidgetItem(examens[i].getDate()));
        ui->tabaffiche->setItem(i, 4, new QTableWidgetItem(examens[i].getHeure()));
        ui->tabaffiche->setItem(i, 5, new QTableWidgetItem(QString::number(examens[i].getQuantite())));
        ui->tabaffiche->setItem(i, 6, new QTableWidgetItem(examens[i].getFichierPdf()));

    }
}

//AJOUTER
void MainWindow::ajouterExamen()
{
    QString code = ui->codeajout->text().trimmed();
    QString matiere = ui->matajout->currentText();
    QString niveau = ui->nivajout->currentText();
    QString date = ui->datajout->date().toString("yyyy-MM-dd");
    QString time = ui->herajout->text();
    QString pdfPath = ui->upload->property("selectedPdfPath").toString();

    // controle de saisir
    bool ok;
    int codeInt = code.toInt(&ok);
    if (!ok || codeInt <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un code valide.");
        return;
    }


    QDate selectedDate = ui->datajout->date();
    QDate currentDate = QDate::currentDate();
    if (selectedDate < currentDate) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une date valide.");
        return;
    }


    QTime selectedTime = QTime::fromString(time, "HH:mm");
    if (!selectedTime.isValid() || selectedTime < QTime(8, 0) || selectedTime > QTime(20, 0)) {
        QMessageBox::warning(this, "Erreur", "L'heure doit être entre 08:00 et 20:00.");
        return;
    }

    int quantite = ui->quantiteajout->text().toInt(&ok);
    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Quantité invalide.");
        return;
    }

    Examen examen(code, matiere, niveau, date, time, quantite);
    if (pdfPath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fichier PDF avant d’ajouter l’examen.");
        return;
    }
    examen.setFichierPdf(pdfPath);

    //confirmation de l'ajout
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment ajouter cet examen ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;


    // Ajout
    if (examen.ajouterExamen()) {
        QMessageBox::information(this, "Succès", "Examen ajouté !");
        afficherExamens();
        remplirCombo();//MODIF
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout , l'examen existe déjà  !");
    }
}


//MODIFIER
void MainWindow::remplirCombo()
{
    ui->codemod->clear();
    QList<Examen> examens = Examen::afficherExamens();
    for (const Examen &exam : std::as_const(examens)) {
        ui->codemod->addItem(exam.getCodeExamen());
    }
}
void MainWindow::modif(int i)
{
    QString code = ui->codemod->itemText(i);

    if (code.isEmpty()) {
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE FROM EXAMEN WHERE ID_EXAMEN = :code");
    query.bindValue(":code", code);

    if (query.exec() && query.next()) {

        ui->matmod->setCurrentText(query.value(0).toString());
        ui->nivmod->setCurrentText(query.value(1).toString());
        ui->datmod->setDate(query.value(2).toDate());
        ui->hermod->setTime(QTime::fromString(query.value(3).toString(), "HH:mm"));
        ui->quantitemod->setText(query.value(4).toString());
        afficherExamens();

    } else {
        qDebug() << "Erreur lors de la récupération des données : " << query.lastError().text();
    }
}
void MainWindow::modifierExamen() {
    QString code = ui->codemod->currentText().trimmed();
    QString matiere = ui->matmod->currentText().trimmed();
    QString niveau = ui->nivmod->currentText().trimmed();
    QString date = ui->datmod->date().toString("yyyy-MM-dd");
    QString time = ui->hermod->text().trimmed();

    //controle de saisir
    QDate selectedDate = ui->datmod->date();
    QDate currentDate = QDate::currentDate();

    if (selectedDate < currentDate) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une date valide.");
        return;
    }

    QTime selectedTime = QTime::fromString(time, "HH:mm");
    QTime minTime(8, 0);
    QTime maxTime(20, 0);

    if (selectedTime < minTime || selectedTime > maxTime) {
        QMessageBox::warning(this, "Erreur", "L'heure doit être entre 08:00 et 20:00.");
        return;
    }
    bool ok;
    int quantite = ui->quantitemod->text().toInt(&ok);
    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantité valide.");
        return;
    }

    //confirmation
    if (QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment modifier cet examen ?") == QMessageBox::No)
        return;

    //modification
    Examen exam(code, matiere, niveau, date, time, quantite);

    if (exam.modifierExamen(code)) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
        afficherExamens();
        remplirCombo();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }

    ui->codemod->setCurrentIndex(0);
    ui->matmod->setCurrentIndex(0);
    ui->nivmod->setCurrentIndex(0);
    ui->datmod->clear();
    ui->hermod->clear();
    ui->quantitemod->clear();
}



//SUPPRIMER
void MainWindow::supprimerExamen()
{
    QString code = ui->codesup->text().trimmed();

    //controle de saisir
    bool ok;
    int codeInt = code.toInt(&ok);

    if (!ok || codeInt <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un code valide (numérique et positif).");
        return;
    }

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer le code de l'examen à supprimer.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EXAMEN WHERE ID_EXAMEN = :code");
    query.bindValue(":code", code);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur de la requête pour vérifier l'existence de l'examen.");
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun examen trouvé avec ce code.");
        return;
    }

    //confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimé cet examen ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    //supp
    Examen examen;
    if (examen.supprimerExamen(code)) {
        QMessageBox::information(this, "Succès", "Examen supprimé avec succès");
        afficherExamens();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'examen");
    }
}




//PDF
void MainWindow::ExporterPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données : " + db.lastError().text());
            return;
        }
    }

    QSqlQuery query("SELECT ID_EXAMEN, MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE FROM EXAMEN");

    if (!query.isActive()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'exécution de la requête : " + query.lastError().text());
        return;
    }


    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    QString pdfContent = "<html><head><style>"
                         "body { font-family: 'Arial'; }"
                         "h1 { text-align: center; color: #2c3e50; margin-bottom: 30px; }"
                         "p.date { text-align: right; font-size: 12px; margin-bottom: 20px; }"
                         "table { width: 100%; border-collapse: collapse; margin-bottom: 30px; }"
                         "th, td { border: 1px solid #888; padding: 10px; text-align: center; font-size: 12px; }"
                         "th { background-color: #3498db; color: white; font-weight: bold; }"
                         "footer { text-align: center; font-size: 10px; color: #888; margin-top: 30px; }"
                         "</style></head><body>";

    pdfContent += "<h1>Liste des Examens</h1>";
    pdfContent += QString("<p class='date'>Date d'export : %1</p>").arg(currentDate);

    pdfContent += "<table><tr>"
                  "<th>ID Examen</th><th>Matière</th><th>Niveau</th><th>Date</th><th>Heure</th><th>Quantité</th></tr>";

    while (query.next()) {
        QString cleanDate = query.value(3).toDate().toString("yyyy-MM-dd");

        pdfContent += "<tr><td>" + query.value(0).toString() + "</td>"
                      + "<td>" + query.value(1).toString() + "</td>"
                      + "<td>" + query.value(2).toString() + "</td>"
                      + "<td>" + cleanDate + "</td>"
                      + "<td>" + query.value(4).toString() + "</td>"
                      + "<td>" + query.value(5).toString() + "</td></tr>";
    }


    pdfContent += "</table>";
    pdfContent += "<footer></footer>";
    pdfContent += "</body></html>";

    QTextDocument document;
    document.setHtml(pdfContent);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);

    QMessageBox::information(this, "Succès", "Exportation en PDF réussie !");
}

//TRI
void MainWindow::TRIC()
{
    int rowCount = ui->tabaffiche->rowCount();

    QVector<int> rowIndices(rowCount);
    for (int row = 0; row < rowCount; ++row) {
        rowIndices[row] = row;
    }

    std::sort(rowIndices.begin(), rowIndices.end(), [this](int a, int b) {
        int valueA = ui->tabaffiche->item(a, 0)->text().toInt();
        int valueB = ui->tabaffiche->item(b, 0)->text().toInt();
        return valueA < valueB;
    });

    QVector<QVector<QTableWidgetItem*>> rows(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int col = 0; col < ui->tabaffiche->columnCount(); ++col) {
            rows[i].append(ui->tabaffiche->takeItem(rowIndices[i], col));
        }
    }


    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < ui->tabaffiche->columnCount(); ++j) {
            ui->tabaffiche->setItem(i, j, rows[i][j]);
        }
    }
}

void MainWindow::TRID()
{
    int rowCount = ui->tabaffiche->rowCount();

    QVector<int> rowIndices(rowCount);
    for (int row = 0; row < rowCount; ++row) {
        rowIndices[row] = row;
    }

    std::sort(rowIndices.begin(), rowIndices.end(), [this](int a, int b) {
        int valueA = ui->tabaffiche->item(a, 0)->text().toInt();
        int valueB = ui->tabaffiche->item(b, 0)->text().toInt();
        return valueA > valueB;
    });

    QVector<QVector<QTableWidgetItem*>> rows(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int col = 0; col < ui->tabaffiche->columnCount(); ++col) {
            rows[i].append(ui->tabaffiche->takeItem(rowIndices[i], col));
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < ui->tabaffiche->columnCount(); ++j) {
            ui->tabaffiche->setItem(i, j, rows[i][j]);
        }
    }
}


void MainWindow::TRIDATE()
{
    int rowCount = ui->tabaffiche->rowCount();

    QVector<int> rowIndices(rowCount);
    for (int i = 0; i < rowCount; ++i) rowIndices[i] = i;

    std::sort(rowIndices.begin(), rowIndices.end(), [this](int a, int b) {
        QDate dateA = QDate::fromString(ui->tabaffiche->item(a, 3)->text(), "yyyy-MM-dd");
        QDate dateB = QDate::fromString(ui->tabaffiche->item(b, 3)->text(), "yyyy-MM-dd");
        return dateA < dateB;
    });

    QVector<QVector<QTableWidgetItem*>> rows(rowCount);
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < ui->tabaffiche->columnCount(); ++j)
            rows[i].append(ui->tabaffiche->takeItem(rowIndices[i], j));

    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < ui->tabaffiche->columnCount(); ++j)
            ui->tabaffiche->setItem(i, j, rows[i][j]);
}

void MainWindow::TriCombo(int i) {
    switch (i) {
    case 0: TRIC(); break;
    case 1: TRID(); break;
    case 2: TRIDATE(); break;
    default: break;
    }
}




//RECHERCHE
void MainWindow::CHERCHER(const QString &texte)
{
    for (int row = 0; row < ui->tabaffiche->rowCount(); ++row) {
        QTableWidgetItem *itemId = ui->tabaffiche->item(row, 0);
        QTableWidgetItem *itemMatiere = ui->tabaffiche->item(row, 1);

        bool matchId = itemId && itemId->text().contains(texte, Qt::CaseInsensitive);
        bool matchMatiere = itemMatiere && itemMatiere->text().contains(texte, Qt::CaseInsensitive);

        if (matchId || matchMatiere) {
            ui->tabaffiche->setRowHidden(row, false);
        } else {
            ui->tabaffiche->setRowHidden(row, true);
        }
    }
}


//STAT
void MainWindow::Statistiques() {
    QSqlQuery query("SELECT NIVEAU, SUM(QUANTITE) FROM EXAMEN GROUP BY NIVEAU");

    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString niveau = query.value(0).toString();
        int totalQuantite = query.value(1).toInt();
        QPieSlice *slice = series->append(niveau, totalQuantite);
        slice->setLabelVisible(false);
    }

    const auto slices = series->slices();
    for (int i = 0; i < slices.size(); ++i) {
        QPieSlice *slice = slices.at(i);
        double percent = slice->percentage() * 100.0;
        QString niveau = slice->label();
        slice->setLabel(QString("%1 - %2%").arg(niveau, QString::number(percent, 'f', 1)));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des examens par niveau");
    chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::NoAnimation);


    if (chartView) {
        ui->chartLayout->removeWidget(chartView);
        delete chartView;
        chartView = nullptr;
        return;
    }

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600, 400);
    ui->chartLayout->addWidget(chartView);
}



//UPLOAD PDF
void MainWindow::uploadPDF()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier PDF", "", "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }
    ui->upload->setText("PDF Sélectionné");
    ui->upload->setProperty("selectedPdfPath", filePath);
}



//CODE A BARRES
QPixmap MainWindow::QRCodeImage(const QString &text)
{
    QString url = "https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=" + text;

    QNetworkAccessManager manager;
    QNetworkRequest request((QUrl(url)));
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QPixmap pix;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        pix.loadFromData(data);
    }

    reply->deleteLater();
    return pix;
}



void MainWindow::QRCode()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter les codes-barres en PDF", "", "Fichier PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QList<Examen> examens = Examen::afficherExamens();
    QString htmlContent = "<html><head><style>"
                          "h1 {text-align: center; color: #333;}"
                          "table {width: 100%; border-collapse: collapse;}"
                          "td {text-align: center; padding: 10px;}"
                          "</style></head><body>";
    htmlContent += "<h1>Codes à Barres des Examens</h1><table>";


    for (int i = 0; i < examens.size(); ++i) {
        const Examen &e = examens[i];

        QString qrText = " Examen Info:\n"
                         "• ID : " + e.getCodeExamen() + "\n"
                                               "• Matière : " + e.getMatiere() + "\n"
                                            "• Niveau : " + e.getNiveau() + "\n"
                                           "• Date : " + e.getDate() + "\n"
                                         "• Heure : " + e.getHeure() + "\n"
                                          "• Quantité : " + QString::number(e.getQuantite()) + " copies";


        QPixmap pix = QRCodeImage(qrText);
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        pix.save(&buffer, "PNG");
        QString base64 = QString::fromLatin1(ba.toBase64());

        htmlContent += "<tr><td><b>ID:</b> " + e.getCodeExamen() + "</td></tr>";
        htmlContent += "<tr><td><img src='data:image/png;base64," + base64 + "'/></td></tr>";
    }


    htmlContent += "</table></body></html>";

    QTextDocument doc;
    doc.setHtml(htmlContent);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "Les codes-barres ont été exportés en PDF avec succès !");
}
