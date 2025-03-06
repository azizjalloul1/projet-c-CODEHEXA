#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QDebug>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Connexion c;
    if (!c.ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
        qDebug() << "Connexion à la base échouée: " << c.getDatabase().lastError().text();
    } else {
        qDebug() << "Connexion à la base réussie !";
    }

    afficherFournisseurs();

    // Connexion des boutons aux fonctions correspondantes
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->btnRechercher, &QLineEdit::textChanged, this, &MainWindow::onRechercherClicked);
    connect(ui->btnExporterPDF, &QPushButton::clicked, this, &MainWindow::onExporterPDFClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Ajouter un fournisseur
void MainWindow::on_btnAjouter_clicked() {
    QString id_fournisseur = ui->lineEdit_Id->text().trimmed();
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString num_tel = ui->lineEdit_NumTel->text().trimmed();
    QString type_service = ui->comboBox_TypeService_2->currentText().trimmed(); // Assure-toi que c'est bien un comboBox !


    qDebug() << "ID Fournisseur: " << id_fournisseur;
    qDebug() << "Nom: " << nom;
    qDebug() << "Numéro de téléphone: " << num_tel;
    qDebug() << "Type de service: " << type_service;

    // **Vérification correcte des champs vides**
    if (id_fournisseur.isEmpty() || nom.isEmpty() || num_tel.isEmpty() || type_service.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    Fournisseur f(id_fournisseur, nom, num_tel, type_service);
    if (f.ajouterFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");
        afficherFournisseurs();
        ui->lineEdit_Id->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_NumTel->clear();
        ui->comboBox_TypeService_2->setCurrentIndex(0); //  Réinitialise le comboBox
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du fournisseur !");
    }
}


// Modifier un fournisseur
void MainWindow::on_btnModifier_clicked() {
    QString id_fournisseur = ui->lineEdit_IdModif->text().trimmed();
    QString nom = ui->lineEdit_NomModif->text().trimmed();
    QString num_tel = ui->lineEdit_NumTelModif->text().trimmed();
    QString type_service = ui->comboBox_TypeServiceModif->currentText().trimmed();


    qDebug() << "Modification du fournisseur avec ID: " << id_fournisseur;

    // **Seul l'ID est obligatoire**
    if (id_fournisseur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID du fournisseur est obligatoire pour modifier !");
        return;
    }

    // **Vérifier si l'ID existe dans la base**
    Fournisseur f;
    if (!f.idExisteDeja(id_fournisseur)) {
        QMessageBox::critical(this, "Erreur", "Aucun fournisseur trouvé avec cet ID !");
        return;
    }

    // **Récupérer les anciennes valeurs si les champs sont vides**
    QSqlQuery query;
    query.prepare("SELECT NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    query.bindValue(":id", id_fournisseur);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données du fournisseur !");
        return;
    }

    QString old_nom = query.value(0).toString();
    QString old_num_tel = query.value(1).toString();
    QString old_type_service = query.value(2).toString();

    // **Utiliser les anciennes valeurs si les nouvelles sont vides**
    if (nom.isEmpty()) nom = old_nom;
    if (num_tel.isEmpty()) num_tel = old_num_tel;
    if (type_service.isEmpty()) type_service = old_type_service;


    qDebug() << "Nouvelle modification - Nom:" << nom << ", Numéro:" << num_tel << ", Service:" << type_service;

    // **Mettre à jour le fournisseur avec les nouvelles valeurs**
    Fournisseur fournisseur(id_fournisseur, nom, num_tel, type_service);
    if (fournisseur.modifierFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur modifié avec succès !");
        afficherFournisseurs(); // Met à jour l'affichage
        ui->lineEdit_IdModif->clear();
        ui->lineEdit_NomModif->clear();
        ui->lineEdit_NumTelModif->clear();
        ui->comboBox_TypeServiceModif->setCurrentIndex(0); // Réinitialise le comboBox
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}


// Supprimer un fournisseur
void MainWindow::on_btnSupprimer_clicked() {
    QString id_fournisseur = ui->lineEdit_SuppID->text().trimmed();

    if (id_fournisseur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID à supprimer.");
        return;
    }

    Fournisseur fournisseur;
    if (fournisseur.supprimerFournisseur(id_fournisseur)) {
        QMessageBox::information(this, "Succès", "Le fournisseur a été supprimé avec succès.");
        afficherFournisseurs();
        ui->lineEdit_SuppID->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression du fournisseur a échoué.");
    }
}

// Afficher les fournisseurs
void MainWindow::afficherFournisseurs() {
    // Vérifier si la base de données est bien ouverte
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée !");
        qDebug() << "Erreur : Connexion à la base de données fermée.";
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_FOURNISSEUR, NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR");

    if (query.exec()) {
        model->setQuery(std::move(query));

        ui->tableView_Fournisseurs->setModel(model);
        qDebug() << "Nombre de fournisseurs trouvés :" << model->rowCount();
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible d'afficher les fournisseurs !");
        delete model;
    }
}


// Rechercher un fournisseur par nom
void MainWindow::onRechercherClicked() {
    QString nom = ui->btnRechercher->text().trimmed();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_FOURNISSEUR, NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche !");
        delete model;
        return;
    }

    model->setQuery(std::move(query));
    ui->tableView_Fournisseurs->setModel(model);
}

// Exporter en PDF
void MainWindow::onExporterPDFClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    QSqlQuery query("SELECT ID_FOURNISSEUR, NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR");
    QString pdfContent = "<h1>Liste des Fournisseurs</h1><table border='1'><tr><th>ID</th><th>Nom</th><th>Téléphone</th><th>Service</th></tr>";

    while (query.next()) {
        pdfContent += "<tr><td>" + query.value(0).toString() + "</td>"
                      + "<td>" + query.value(1).toString() + "</td>"
                      + "<td>" + query.value(2).toString() + "</td>"
                      + "<td>" + query.value(3).toString() + "</td></tr>";
    }

    pdfContent += "</table>";

    QTextDocument document;
    document.setHtml(pdfContent);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);

    QMessageBox::information(this, "Succès", "Exportation en PDF réussie !");
}
