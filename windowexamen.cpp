#include "windowexamen.h"
#include "ui_windowexamen.h"

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
#include <QHostInfo>
#include <QNetworkInterface>
#include <QSqlQueryModel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QSqlQuery>
#include <QRandomGenerator>
#include "accueil.h"


WindowExamen::WindowExamen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowExamen)
{
    ui->setupUi(this);

    ui->matmod->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivmod->addItems({"Primaire", "Collège", "Lycée", "Université"});

    ui->matajout->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivajout->addItems({"Primaire", "Collège", "Lycée", "Université"});


    ui->triComboBox->addItem("Trier par ID croissant");
    ui->triComboBox->addItem("Trier par ID décroissant");
    ui->triComboBox->addItem("Trier par Date");


    //ALERT
    arduino = new QSerialPort(this);
    arduino->setPortName("COM6");
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if (arduino->open(QIODevice::ReadOnly)) {
        connect(arduino, &QSerialPort::readyRead, this, &WindowExamen::lireDonneesArduino);
        qDebug() << " Arduino connecté.";
    } else {
        qDebug() << " Erreur de connexion Arduino:" << arduino->errorString();
    }

    //


    remplirCombo();


    afficherExamens();


    connect(ui->ajouter, &QPushButton::clicked, this, &WindowExamen::ajouterExamen);
    connect(ui->modifier, &QPushButton::clicked, this, &WindowExamen::modifierExamen);
    connect(ui->codemod, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &WindowExamen::modif);
    connect(ui->supprimer, &QPushButton::clicked, this, &WindowExamen::supprimerExamen);
    connect(ui->exporter, &QPushButton::clicked, this, &WindowExamen::ExporterPDF);
    connect(ui->upload, &QPushButton::clicked, this, &WindowExamen::uploadPDF);
    connect(ui->recherche, &QLineEdit::textChanged, this, &WindowExamen::CHERCHER);
    connect(ui->stat, &QPushButton::clicked, this, &WindowExamen::Statistiques);
    connect(ui->codebar, &QPushButton::clicked, this, &WindowExamen::QRCode);
    connect(ui->triComboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&WindowExamen::TriCombo);
    connect(ui->r4, &QPushButton::clicked, this, &WindowExamen::retour);




}

WindowExamen::~WindowExamen()
{
    delete ui;
}


void WindowExamen::setAccueil(Accueil *accueilWindow) {
    this->accueil = accueilWindow;
}

void WindowExamen::retour()
{
    this->hide();           // cacher MainWindow
    if (accueil) {
        accueil->show();    // montrer Accueil
    }
}

//AFFICHER

void WindowExamen::afficherExamens()
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
void WindowExamen::ajouterExamen()
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
void WindowExamen::remplirCombo()
{
    ui->codemod->clear();
    QList<Examen> examens = Examen::afficherExamens();
    for (const Examen &exam : std::as_const(examens)) {
        ui->codemod->addItem(exam.getCodeExamen());
    }
}
void WindowExamen::modif(int i)
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
void WindowExamen::modifierExamen() {
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
void WindowExamen::supprimerExamen()
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
void WindowExamen::ExporterPDF() {
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

    pdfContent += "<img src=\"C:\\2A12\\2\\projet c++\\Gstion-examen\\img.png\" width=\"80\" style=\"float: left; margin-top: -20px; margin-left: 10px;\" />";
    pdfContent += "<h1>Liste des Examens</h1>";

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
    pdfContent += QString("<p class='date'>Date d'export : %1</p>").arg(currentDate);

    QTextDocument document;
    document.setHtml(pdfContent);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);

    QMessageBox::information(this, "Succès", "Exportation en PDF réussie !");
}


//TRI
void WindowExamen::TRIC()
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

void WindowExamen::TRID()
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


void WindowExamen::TRIDATE()
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

void WindowExamen::TriCombo(int i) {
    switch (i) {
    case 0: TRIC(); break;
    case 1: TRID(); break;
    case 2: TRIDATE(); break;
    default: break;
    }
}




//RECHERCHE
void WindowExamen::CHERCHER(const QString &texte)
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
void WindowExamen::Statistiques() {
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
void WindowExamen::uploadPDF()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier PDF", "", "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }
    ui->upload->setText("PDF Sélectionné");
    ui->upload->setProperty("selectedPdfPath", filePath);
}



//QRCODE
QPixmap WindowExamen::QRCodeImage(const QString &text)
{
    qDebug() << "Texte à encoder dans le QR:" << text;

    QString encodedText = QUrl::toPercentEncoding(text);
    QString url = "https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=" + encodedText;

    QUrl qurl(url);
    QNetworkRequest request(qurl);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QPixmap pix;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        pix.loadFromData(data);
    } else {
        qDebug() << " Erreur de requête:" << reply->errorString();
    }

    reply->deleteLater();
    manager->deleteLater();

    return pix;
}



void WindowExamen::QRCode()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter le PDF avec les QR codes", "", "Fichier PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QList<Examen> examens = Examen::afficherExamens();
    if (examens.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun examen trouvé !");
        return;
    }

    QString htmlContent = "<html><head><style>"
                          "body { font-family: Arial; padding: 30px; color: #222; }"
                          "h1 { text-align: center; color: #1a73e8; }"
                          "table { width: 100%; border-collapse: collapse; }"
                          "td { text-align: center; padding: 20px; border-bottom: 1px solid #ddd; }"
                          "</style></head><body>";
    htmlContent += "<h1>Codes QR des Examens</h1><table>";


    for (const Examen &e : examens) {
        QString id = e.getCodeExamen();

        QString qrText =
            "EXAMEN INFO:\n"
            "ID: " + id +
            " | Matiere: " + e.getMatiere().simplified().replace("é", "e").replace("è", "e") +
            " | Niveau: " + e.getNiveau() +
            " | Date: " + e.getDate() +
            " | Heure: " + e.getHeure() +
            " | Quantite: " + QString::number(e.getQuantite());

        QPixmap pix = QRCodeImage(qrText);
        if (pix.isNull()) continue;

        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        pix.save(&buffer, "PNG");
        QString base64 = QString::fromLatin1(ba.toBase64());

        htmlContent += "<tr><td><b>ID:</b> " + id + "</td></tr>";
        htmlContent += "<tr><td><img src='data:image/png;base64," + base64 + "'/></td></tr>";
    }

    htmlContent += "</table></body></html>";

    QTextDocument doc;
    doc.setHtml(htmlContent);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF avec QR codes exporté avec succès !");
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

//ALERTE
void WindowExamen::ValeurSuperieuregaz(int valeurGaz) {
    qDebug() << " Valeur reçue : " << valeurGaz;

    int etat = (valeurGaz > 400) ? 1 : 0;



    QStringList types = {"stylo", "feuille", "souris", "cahier", "clavier"};
    QString type = types.at(QRandomGenerator::global()->bounded(0, types.size()));
    double prix = QRandomGenerator::global()->bounded(100, 1000) / 10.0;

    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM STOCK");

    int count = 0;
    if (countQuery.next()) {
        count = countQuery.value(0).toInt();
    }

    if (count > 0) {
        int refToUpdate = -1;
        QSqlQuery select;
        if (select.exec("SELECT REF FROM STOCK WHERE ROWNUM = 1")) {
            if (select.next()) {
                refToUpdate = select.value(0).toInt();
            }
        }

        if (refToUpdate != -1) {
            QSqlQuery update;
            update.prepare("UPDATE STOCK SET PRIX_UNITAIRE = :prix, TYPE = :type, GAZ = :gaz, ETAT = :etat WHERE REF = :ref");
            update.bindValue(":prix", prix);
            update.bindValue(":type", type);
            update.bindValue(":gaz", valeurGaz);
            update.bindValue(":etat", etat);
            update.bindValue(":ref", refToUpdate);

            if (update.exec()) {
                qDebug() << " Ligne REF = " << refToUpdate << " mise à jour.";
            } else {
                qDebug() << " Erreur UPDATE : " << update.lastError().text();
            }
        }
    } else {
        QSqlQuery insert;
        insert.prepare("INSERT INTO STOCK (PRIX_UNITAIRE, TYPE, GAZ, ETAT) "
                       "VALUES (:prix, :type, :gaz, :etat)");
        insert.bindValue(":prix", prix);
        insert.bindValue(":type", type);
        insert.bindValue(":gaz", valeurGaz);
        insert.bindValue(":etat", etat);

        if (insert.exec()) {
            qDebug() << " Première ligne insérée.";
        } else {
            qDebug() << " Erreur INSERT : " << insert.lastError().text();
        }
    }


}


void WindowExamen::lireDonneesArduino()
{
    QByteArray data = arduino->readAll();
    QString ligne = QString::fromUtf8(data).trimmed();

    qDebug() << " Donnée reçue : " << ligne;

    if (ligne.contains("Gaz")) {
        QRegularExpression regex("Gaz\\s*=\\s*(\\d+)");
        QRegularExpressionMatch match = regex.match(ligne);
        if (match.hasMatch()) {
            int valGaz = match.captured(1).toInt();
            qDebug() << " Valeur Gaz détectée : " << valGaz;
            ValeurSuperieuregaz(valGaz);


        }
    }
}
