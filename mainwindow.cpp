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

void MainWindow::importerid()
{
    ui->codemod->clear();

    QList<Examen> exams = Examen::afficherExamens();

    for (const Examen &exam : std::as_const(exams)) {
        ui->codemod->addItem(exam.getCodeExamen());
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->matmod->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivmod->addItems({"Primaire", "Collège", "Lycée", "Université"});

    ui->matajout->addItems({"Mathématiques", "Physique", "Chimie", "Informatique", "Biologie", "Anglais"});

    ui->nivajout->addItems({"Primaire", "Collège", "Lycée", "Université"});

    importerid();

    afficherExamens();

    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::ajouterExamen);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::modifierExamen);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::supprimerExamen);
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::ExporterPDF);
    connect(ui->trierc, &QPushButton::clicked, this, &MainWindow::TRIC);
    connect(ui->trierd, &QPushButton::clicked, this, &MainWindow::TRID);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::CHERCHER);
    connect(ui->codemod, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::modif);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherExamens()
{
    QList<Examen> examens = Examen::afficherExamens();
    ui->tabaffiche->setRowCount(0);

    for (int i = 0; i < examens.size(); ++i) {
        ui->tabaffiche->insertRow(i);
        ui->tabaffiche->setItem(i, 0, new QTableWidgetItem(examens[i].getCodeExamen()));
        ui->tabaffiche->setItem(i, 1, new QTableWidgetItem(examens[i].getMatiere()));
        ui->tabaffiche->setItem(i, 2, new QTableWidgetItem(examens[i].getNiveau()));
        ui->tabaffiche->setItem(i, 3, new QTableWidgetItem(examens[i].getDate()));
        ui->tabaffiche->setItem(i, 4, new QTableWidgetItem(examens[i].getHeure()));
        ui->tabaffiche->setItem(i, 5, new QTableWidgetItem(QString::number(examens[i].getQuantite())));
        ui->tabaffiche->setColumnCount(6);
        ui->tabaffiche->setHorizontalHeaderLabels({"Code", "Matière", "Niveau", "Date", "Heure", "Quantité"});

    }
}

void MainWindow::ajouterExamen()
{
    QString code = ui->codeajout->text().trimmed();
    QString matiere = ui->matajout->currentText();
    QString niveau = ui->nivajout->currentText();
    QString date = ui->datajout->date().toString("yyyy-MM-dd");
    QString time = ui->herajout->text();


    //Vérification des entrées
    bool ok;
    int codeInt = code.toInt(&ok);

    if (!ok || codeInt <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un code valide (numérique et positif).");
        return;
    }
    QDate selectedDate = ui->datajout->date();
    QDate currentDate = QDate::currentDate();

    if (selectedDate < currentDate) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une date égale ou postérieure à la date d'aujourd'hui.");
        return;
    }

    QTime selectedTime = QTime::fromString(time, "HH:mm");

    if (!selectedTime.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une heure valide.");
        return;
    }

    QTime minTime(8, 0);
    QTime maxTime(20, 0);

    if (selectedTime < minTime || selectedTime > maxTime) {
        QMessageBox::warning(this, "Erreur", "L'heure doit être entre 08:00 et 20:00.");
        return;
    }


    int quantite = ui->quantiteajout->text().toInt(&ok);

    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantité valide (numérique et positive).");
        return;
    }

    Examen examen(code, matiere, niveau, date, time, quantite);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment ajouter cet examen ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }
    if (examen.ajouterExamen()) {
        QMessageBox::information(this, "Succès", "Examen ajouté avec succès");
        afficherExamens();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'examen . l'examen existe déjà !");
    }

}

void MainWindow::modifierExamen() {
    QString code = ui->codemod->currentText().trimmed();



    qDebug() << "Code to modify: [" << code << "]";
    QSqlQuery query;
    query.prepare("SELECT MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE FROM EXAMEN WHERE ID_EXAMEN = :code");
    query.bindValue(":code", code);

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données de l'examen ! Erreur: " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        qDebug() << "No records found for code: [" << code << "]";
        QMessageBox::critical(this, "Erreur", "Aucun examen trouvé avec ce code !");
        return;
    }

    QString old_matiere = query.value(0).toString();
    QString old_niveau = query.value(1).toString();
    QString old_date = query.value(2).toString();
    QString old_heure = query.value(3).toString();
    int old_quantite = query.value(4).toInt();

    QString matiere = ui->matmod->currentText().trimmed();
    QString niveau = ui->nivmod->currentText().trimmed();
    QString date = ui->datmod->date().toString("yyyy-MM-dd");
    QString time = ui->hermod->text().trimmed();

    //Vérification des entrées
    QDate selectedDate = ui->datmod->date();
    QDate currentDate = QDate::currentDate();

    if (selectedDate < currentDate) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une date égale ou postérieure à la date d'aujourd'hui.");
        return;
    }

    QTime selectedTime = QTime::fromString(time, "HH:mm");

    if (!selectedTime.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une heure valide.");
        return;
    }

    QTime minTime(8, 0);
    QTime maxTime(20, 0);

    if (selectedTime < minTime || selectedTime > maxTime) {
        QMessageBox::warning(this, "Erreur", "L'heure doit être entre 08:00 et 20:00.");
        return;
    }

     bool ok;
    int quantite = ui->quantitemod->text().toInt(&ok);

    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantité valide (positive et numérique).");
        return;
    }



    if (matiere.isEmpty()) matiere = old_matiere;
    if (niveau.isEmpty()) niveau = old_niveau;
    if (date.isEmpty()) date = old_date;
    if (time.isEmpty()) time = old_heure;
    if (quantite == 0) quantite = old_quantite;

    qDebug() << "Modifying exam with the following details: ";
    qDebug() << "Matière:" << matiere << ", Niveau:" << niveau << ", Date:" << date << ", Heure:" << time << ", Quantité:" << quantite;



    query.prepare("UPDATE EXAMEN SET "
                  "MATIERE = :matiere, "
                  "NIVEAU = :niveau, "
                  "DATE_EXAMEN = TO_DATE(:exam_date, 'YYYY-MM-DD'), "
                  "HEURE = :heure, "
                  "QUANTITE = :quantite "
                  "WHERE ID_EXAMEN = :code");

    query.bindValue(":code", code);
    query.bindValue(":matiere", matiere);
    query.bindValue(":niveau", niveau);
    query.bindValue(":exam_date", date);
    query.bindValue(":heure", time);
    query.bindValue(":quantite", quantite);

    //confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment modifier cet examen ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'examen !");
        return;
    }

    QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
    afficherExamens();
    ui->codemod->setCurrentIndex(0);
    ui->matmod->setCurrentIndex(0);
    ui->nivmod->setCurrentIndex(0);
    ui->datmod->clear();
    ui->hermod->clear();
    ui->quantitemod->clear();
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
    } else {
        qDebug() << "Erreur lors de la récupération des données : " << query.lastError().text();
    }
}




void MainWindow::supprimerExamen()
{
    QString code = ui->codesup->text().trimmed();

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

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimé cet examen ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }
    Examen examen;
    if (examen.supprimerExamen(code)) {
        QMessageBox::information(this, "Succès", "Examen supprimé avec succès");
        afficherExamens();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'examen");
    }
}





void MainWindow::ExporterPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données : " + db.lastError().text());
            return;
        }
    }

    QSqlQuery query;
    query.prepare("SELECT ID_EXAMEN, MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE FROM EXAMEN");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    QString pdfContent = "<html><head><style>"
                         "table {width: 100%; border-collapse: collapse;}"
                         "th, td {border: 1px solid black; padding: 8px; text-align: center;}"
                         "th {background-color: #f2f2f2; font-weight: bold;}"
                         "h1 {text-align: center; color: #333;}"
                         "</style></head><body>";

    pdfContent += "<h1>Liste des Examens</h1><table><tr>"
                  "<th>ID Examen</th><th>Matière</th><th>Niveau</th><th>Date</th><th>Heure</th><th>Quantité</th></tr>";

    while (query.next()) {
        pdfContent += "<tr><td>" + query.value(0).toString() + "</td>"
                      + "<td>" + query.value(1).toString() + "</td>"
                      + "<td>" + query.value(2).toString() + "</td>"
                      + "<td>" + query.value(3).toString() + "</td>"
                      + "<td>" + query.value(4).toString() + "</td>"
                      + "<td>" + query.value(5).toString() + "</td></tr>";
    }

    pdfContent += "</table></body></html>";

    QTextDocument document;
    document.setHtml(pdfContent);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);

    QMessageBox::information(this, "Succès", "Exportation en PDF réussie !");
}


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







void MainWindow::CHERCHER(const QString &id)
{
    for (int row = 0; row < ui->tabaffiche->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tabaffiche->item(row, 0);
        if (item && item->text().contains(id, Qt::CaseInsensitive)) {
            ui->tabaffiche->setRowHidden(row, false);
        } else {
            ui->tabaffiche->setRowHidden(row, true);
        }
    }
}


