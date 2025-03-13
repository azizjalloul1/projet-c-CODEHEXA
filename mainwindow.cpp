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
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QPainter>
#include <QPdfWriter>
#include <QImage>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chargerListeIDs(); //Charge les ID au démarrage

    Connexion c;
    if (!c.ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
        qDebug() << "Connexion à la base échouée: " << c.getDatabase().lastError().text();
    } else {
        qDebug() << "Connexion à la base réussie !";
    }

    afficherFournisseurs();

    // Connexion des boutons aux fonctions correspondantes
    //connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    //connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    //connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->comboBox_IdModif, &QComboBox::currentIndexChanged, this, &MainWindow::remplirChampsFournisseur);
    connect(ui->triButton, &QPushButton::clicked, this, &MainWindow::trierParCommande);
    connect(ui->btnExporterPDF, &QPushButton::clicked, this, &MainWindow::exporterEnPDF);

    connect(ui->btnRechercher, &QLineEdit::textChanged, this, &MainWindow::onRechercherClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}



// Ajouter un fournisseur
void MainWindow::on_btnAjouter_clicked() {
    QString id_fournisseur = ui->lineEdit_Id->text().trimmed();
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString num_tel = ui->lineEdit_NumTel->text().trimmed();
    QString type_service = ui->comboBox_TypeService_2->currentText().trimmed();

    // **Vérification des champs vides**
    if (id_fournisseur.isEmpty() || nom.isEmpty() || num_tel.isEmpty() || type_service.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // **Validation de l'ID Fournisseur : uniquement des chiffres**
    static const QRegularExpression idRegex("^[0-9]+$");
    if (!idRegex.match(id_fournisseur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID Fournisseur doit contenir uniquement des chiffres !");
        return;
    }

    // **Validation du nom : seulement des lettres (majuscules ou minuscules)**
    static const QRegularExpression nomRegex("^[a-zA-Z]+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres !");
        return;
    }

    // **Validation du numéro de téléphone : exactement 8 chiffres**
    static const QRegularExpression telRegex("^[0-9]{8}$");
    if (!telRegex.match(num_tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return;
    }

    // **Générer une quantité aléatoire entre 10 et 200**
    int quantiteAleatoire = QRandomGenerator::global()->bounded(10, 201);

    Fournisseur f(id_fournisseur, nom, num_tel, type_service);
    if (f.ajouterFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");

        // **Insérer la quantité de commande aléatoire dans COMMANDE**
        QSqlQuery query;
        query.prepare("INSERT INTO COMMANDE (ID_COMMANDE, ID_FOURNISSEUR, QUANTITE_COMMANDE) "
                      "VALUES ((SELECT COALESCE(MAX(ID_COMMANDE), 0) + 1 FROM COMMANDE), :id_fournisseur, :quantite)");

        query.bindValue(":id_fournisseur", id_fournisseur);
        query.bindValue(":quantite", quantiteAleatoire);

        if (query.exec()) {
            qDebug() << "Quantité de commande aléatoire ajoutée: " << quantiteAleatoire;
        } else {
            qDebug() << "Erreur lors de l'insertion de la quantité: " << query.lastError().text();
        }

        afficherFournisseurs();

        // **Réinitialisation des champs**
        ui->lineEdit_Id->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_NumTel->clear();
        ui->comboBox_TypeService_2->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du fournisseur !");
    }
}


void MainWindow::remplirChampsFournisseur() {
    QString id_fournisseur = ui->comboBox_IdModif->currentText().trimmed();
    if (id_fournisseur.isEmpty()) return; // Si aucun ID sélectionné, ne rien faire

    QSqlQuery query;
    query.prepare("SELECT NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    query.bindValue(":id", id_fournisseur);

    if (!query.exec()) {
        qDebug() << "Erreur lors du chargement du fournisseur:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données du fournisseur !");
        return;
    }

    if (query.next()) {
        ui->lineEdit_NomModif->setText(query.value(0).toString());
        ui->lineEdit_NumTelModif->setText(query.value(1).toString());

    }QString typeService = query.value(2).toString();
    int index = ui->comboBox_TypeServiceModif->findText(typeService);

    if (index != -1) {
        ui->comboBox_TypeServiceModif->setCurrentIndex(index);
    } else {
        qDebug() << "Type de service introuvable dans le ComboBox :" << typeService;
    }

}



// Modifier un fournisseur
void MainWindow::on_btnModifier_clicked() {
    // Récupération
    QString id_fournisseur = ui->comboBox_IdModif->currentText().trimmed();
    QString nom = ui->lineEdit_NomModif->text().trimmed();
    QString num_tel = ui->lineEdit_NumTelModif->text().trimmed();
    QString type_service = ui->comboBox_TypeServiceModif->currentText().trimmed();

    qDebug() << "Modification du fournisseur avec ID: " << id_fournisseur;

    //Vérification si l'ID est sélectionné
    if (id_fournisseur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fournisseur !");
        return;
    }

    // Vérifier si l'ID existe dans la base
    Fournisseur f;
    if (!f.idExisteDeja(id_fournisseur)) {
        QMessageBox::critical(this, "Erreur", "Aucun fournisseur trouvé avec cet ID !");
        return;
    }

    // Récupérer les anciennes valeurs si les champs sont vides
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

    // Utiliser les anciennes valeurs si les nouvelles sont vides
    if (nom.isEmpty()) nom = old_nom;
    if (num_tel.isEmpty()) num_tel = old_num_tel;
    if (type_service.isEmpty()) type_service = old_type_service;

    // **Validation du nom : seulement des lettres (majuscules ou minuscules)**
     static const QRegularExpression nomRegex("^[a-zA-Z]+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres !");
        return;
    }

    // **Validation du numéro de téléphone : exactement 8 chiffres**
     static const QRegularExpression telRegex("^[0-9]{8}$");
    if (!telRegex.match(num_tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return;
    }

    qDebug() << "Nouvelle modification - Nom:" << nom << ", Numéro:" << num_tel << ", Service:" << type_service;

    // **Mettre à jour le fournisseur avec les nouvelles valeurs**
    Fournisseur fournisseur(id_fournisseur, nom, num_tel, type_service);
    if (fournisseur.modifierFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur modifié avec succès !");

        afficherFournisseurs(); // Rafraîchir l'affichage
        chargerListeIDs(); // Mettre à jour la liste des IDs dans le ComboBox

        // **Réinitialisation des champs**
        ui->comboBox_IdModif->setCurrentIndex(0);
        ui->lineEdit_NomModif->clear();
        ui->lineEdit_NumTelModif->clear();
        ui->comboBox_TypeServiceModif->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}

void MainWindow::chargerListeIDs() {
    ui->comboBox_IdModif->clear(); // Nettoyer le comboBox avant de recharger

    QSqlQuery query;
    query.prepare("SELECT ID_FOURNISSEUR FROM FOURNISSEUR");

    if (!query.exec()) {
        qDebug() << "Erreur lors du chargement des   IDs :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de charger les IDs !");
        return;
    }

    while (query.next()) { //parcourt les résultats de la requête ligne par ligne
        QString id = query.value(0).toString();
        ui->comboBox_IdModif->addItem(id);
    }

    qDebug() << "Chargement des IDs terminé.";
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
        chargerListeIDs();
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

    // Requête SQL pour récupérer les fournisseurs et la quantité de commande
    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "NVL(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                  "FROM FOURNISSEUR F "
                  "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR");

    if (query.exec()) {
        model->setQuery(std::move(query));

        // Définir les en-têtes des colonnes
        model->setHeaderData(0, Qt::Horizontal, "ID FOURNISSEUR");
        model->setHeaderData(1, Qt::Horizontal, "NOM");
        model->setHeaderData(2, Qt::Horizontal, "NUMÉRO TÉLÉPHONE");
        model->setHeaderData(3, Qt::Horizontal, "TYPE DE SERVICE");
        model->setHeaderData(4, Qt::Horizontal, "QUANTITÉ COMMANDE");

        ui->tableView_Fournisseurs->setModel(model);
        qDebug() << "Nombre de fournisseurs trouvés :" << model->rowCount();
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible d'afficher les fournisseurs !");
        delete model;
    }
}

void MainWindow::trierParCommande() {
 QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour trier par quantité de commande en croissant
    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "NVL(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                  "FROM FOURNISSEUR F "
                  "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR "
                  "ORDER BY QUANTITE_COMMANDE DESC");  //Cela permet de récupérer tous les fournisseurs, même ceux qui n'ont pas encore de commande.

    if (query.exec()) {
        model->setQuery(std::move(query));


        // Définir les en-têtes des colonnes
        model->setHeaderData(0, Qt::Horizontal, "ID FOURNISSEUR");
        model->setHeaderData(1, Qt::Horizontal, "NOM");
        model->setHeaderData(2, Qt::Horizontal, "NUMÉRO TÉLÉPHONE");
        model->setHeaderData(3, Qt::Horizontal, "TYPE DE SERVICE");
        model->setHeaderData(4, Qt::Horizontal, "QUANTITÉ COMMANDE");

        ui->tableView_Fournisseurs->setModel(model);
        qDebug() << "Tri effectué, meilleur fournisseur en premier.";
    } else {
        qDebug() << "Erreur SQL lors du tri :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de trier les fournisseurs !");
        delete model;
    }
}


// Rechercher un fournisseur par nom
void MainWindow::onRechercherClicked() {
    QString nom = ui->btnRechercher->text().trimmed();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "COALESCE(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                  "FROM FOURNISSEUR F "
                  "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR "
                  "WHERE F.NOM LIKE :nom");

    query.bindValue(":nom", "%" + nom + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche !");
        delete model;
        return;
    }

    model->setQuery(std::move(query));

    // **Définir les en-têtes pour bien afficher les colonnes**
    model->setHeaderData(0, Qt::Horizontal, "ID FOURNISSEUR");
    model->setHeaderData(1, Qt::Horizontal, "NOM");
    model->setHeaderData(2, Qt::Horizontal, "NUMÉRO TÉLÉPHONE");
    model->setHeaderData(3, Qt::Horizontal, "TYPE DE SERVICE");
    model->setHeaderData(4, Qt::Horizontal, "QUANTITÉ COMMANDE");

    ui->tableView_Fournisseurs->setModel(model);

    qDebug() << "Recherche effectuée avec succès.";
}


// Exporter en PDF
void MainWindow::exporterEnPDF() {

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return; // L'utilisateur a annulé

    // Configurer le PDF**
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));  // Taille A4
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);

    //  Ajouter une image
    QImage image("C:/Users/ASUS/Desktop/Projet_QT/FOURNISSEURS/mm.png");  //chemin
    if (!image.isNull()) {
        QRect imgRect((pdfWriter.width() - 250) / 2, 50, 250, 120);
        painter.drawImage(imgRect, image);
    } else {
        qDebug() << "Image introuvable ! Vérifiez le chemin.";
    }

    // **4️⃣ Ajouter un titre plus visible**
    painter.setFont(QFont("Arial", 18, QFont::Bold));  // Plus grand titre
    painter.drawText(QRect(0, 200, pdfWriter.width(), 50), Qt::AlignCenter, "Liste des Fournisseurs");

    // **5️⃣ Récupérer les données des fournisseurs**
    QSqlQuery query;
    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "COALESCE(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                  "FROM FOURNISSEUR F "
                  "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'exporter les données !");
        return;
    }

    // **6️⃣ Configurer le tableau**
    int startY = 280;  //
    int rowHeight = 300;
    int colWidths[] = {100, 200, 300, 240, 200};  // Largeur augmentée

    // **7️⃣ En-têtes du tableau**
    QStringList headers = {"ID", "Nom", "Téléphone", "Service", "Quantité"};
    painter.setFont(QFont("Arial", 12, QFont::Bold));

    int xPos = 50;
    painter.setBrush(QColor(200, 200, 200));  // Fond gris pour les en-têtes

    for (int i = 0; i < headers.size(); i++) {
        painter.drawRect(xPos, startY, colWidths[i], rowHeight);
        painter.drawText(xPos + 10, startY + 30, headers[i]);
        xPos += colWidths[i];
    }

    painter.setBrush(Qt::NoBrush);  // Supprimer le fond pour les cellules

    //  Remplir le tableau avec les données**
    startY += rowHeight;
    painter.setFont(QFont("Arial", 11));  // Texte plus grand

    while (query.next()) {
        xPos = 50;
        for (int i = 0; i < headers.size(); i++) {
            painter.drawRect(xPos, startY, colWidths[i], rowHeight);
            painter.drawText(xPos + 10, startY + 30, query.value(i).toString());
            xPos += colWidths[i];
        }
        startY += rowHeight;
    }


    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}


