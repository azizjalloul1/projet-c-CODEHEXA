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
#include "sms.h"
#include <QtCharts>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chargerListeIDs(); //Charge les ID au démarrage

  /*  smtp = new SmtpClient(
        "smtp.gmail.com", 587,
        "molkaomrani1412@gmail.com",       // remplacez par votre adresse
        "zylg lvby xvvb opwh",          // mot de passe d’application Google
        true, this
        );*/

    // 2) Pour voir le dialogue SMTP dans la console
   // connect(smtp, &SmtpClient::statusMessage,
         //   this, &MainWindow::onSmtpStatus);

    Connexion c;
    if (!c.ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
        qDebug() << "Connexion à la base échouée: " << c.getDatabase().lastError().text();
    } else {
        qDebug() << "Connexion à la base réussie !";
    }


    genererIDFournisseur();
    afficherFournisseurs();
    chargerListeIDs();

    // Connexion des boutons aux fonctions correspondantes
    //connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    //connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    //connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->comboBox_IdModif, &QComboBox::currentIndexChanged, this, &MainWindow::remplirChampsFournisseur);
    connect(ui->comboBox_Tri, &QComboBox::currentIndexChanged, this, &MainWindow::trierParCommande);
    connect(ui->btnMeilleurFournisseur, &QPushButton::clicked, this, &MainWindow::on_btnMeilleurFournisseur_clicked);

    connect(ui->btnExporterPDF, &QPushButton::clicked, this, &MainWindow::exporterEnPDF);
    connect(ui->btnEnvoyerSMS, &QPushButton::clicked, this, &MainWindow::envoyerSMS);
    connect(ui->btnStatistiques, &QPushButton::clicked, this, &MainWindow::afficherStatistiques);
    connect(ui->btnRechercher, &QLineEdit::textChanged, this, &MainWindow::onRechercherClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}









void MainWindow::on_btnMeilleurFournisseur_clicked()
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT ID_FOURNISSEUR,
               NOM,
               TYPE_SERVICE,
               TOTAL_COMMANDES
        FROM (
          SELECT F.ID_FOURNISSEUR,
                 F.NOM,
                 F.TYPE_SERVICE,
                 SUM(C.QUANTITE_COMMANDE) AS TOTAL_COMMANDES
            FROM FOURNISSEUR F
            JOIN COMMANDE C
              ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR
           GROUP BY F.ID_FOURNISSEUR, F.NOM, F.TYPE_SERVICE
           ORDER BY TOTAL_COMMANDES DESC
        )
        WHERE ROWNUM = 1
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL",
                              query.lastError().text());
        return;
    }
    if (!query.next()) {
        QMessageBox::information(this, "Info",
                                 "Aucun fournisseur trouvé.");
        return;
    }

    // Extraction
    QString id    = query.value(0).toString();
    QString nom   = query.value(1).toString();
    QString type  = query.value(2).toString();
    int     total = query.value(3).toInt();

    // Affichage unique
    auto *model = new QSqlQueryModel(this);
    model->setQuery(std::move(query));  // Qt6 move
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Type Service");
    model->setHeaderData(3, Qt::Horizontal, "Total Cmds");
    ui->tableView_Fournisseurs->setModel(model);

    // Préparer et envoyer l'email à moi-même
    const QString destinataire = "molkaomrani1412@gmail.com";
    QString sujet = QString("Meilleur fournisseur : %1").arg(nom);
    QString corps = QString(
                        "Détails du fournisseur n°1 :\n\n"
                        "• ID           : %1\n"
                        "• Nom          : %2\n"
                        "• Type service : %3\n"
                        "• Total        : %4 commandes\n"
                        ).arg(id, nom, type)
                        .arg(QString::number(total));

    envoyerEmailSMTP(destinataire, sujet, corps);
}

void MainWindow::envoyerEmailSMTP(const QString &to,
                                  const QString &subject,
                                  const QString &body)
{
    // 1) Crée un client SMTP neuf pour cet envoi
    auto *client = new SmtpClient(
        "smtp.gmail.com", 587,
        "molkaomrani1412@gmail.com",   // votre adresse expéditrice
        "<zylg lvby xvvb opwh>",       // mot de passe d’application
        true,
        this                       // parent = MainWindow → auto delete
        );

    // 2) Logguez le dialogue SMTP
    connect(client, &SmtpClient::statusMessage,
            this, &MainWindow::onSmtpStatus);

    // 3) Lance l’envoi
    client->sendMail("votre.email@gmail.com",
                     to,
                     subject,
                     body);

    // 4) Quand le client a fini (221 Bye), on peut le supprimer.
    //    Ajoutez un signal dans SmtpClient émis après le QUIT, ou
    //    supprimez après un court délai :
    connect(client, &SmtpClient::statusMessage, client, [client](const QString &msg){
        if (msg.startsWith("221")) { client->deleteLater(); }
    });
}



void MainWindow::onSmtpStatus(const QString &msg)
{
    qDebug() << "[SMTP]" << msg;
    // Optionnel : pop-up utilisateur quand le mail est vraiment parti
    if (msg.startsWith("250 ")) {
        QMessageBox::information(this, "Email",
                                 "Le message a été envoyé avec succès !");
    }
}









void MainWindow::genererIDFournisseur() {
    int generatedID = 1;
    QSqlQuery query;
    query.prepare("SELECT MIN(t1.ID_FOURNISSEUR + 1) "
                  "FROM FOURNISSEUR t1 "
                  "WHERE NOT EXISTS (SELECT 1 FROM FOURNISSEUR t2 WHERE t2.ID_FOURNISSEUR = t1.ID_FOURNISSEUR + 1)");

    if (query.exec() && query.next()) {
        QVariant val = query.value(0);
        if (val.isValid() && !val.isNull())
            generatedID = val.toInt();
    }

    QSqlQuery checkEmpty;
    checkEmpty.exec("SELECT COUNT(*) FROM FOURNISSEUR");
    if (checkEmpty.next() && checkEmpty.value(0).toInt() == 0)
        generatedID = 1;

    ui->lineEdit_Id->setText(QString::number(generatedID));
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


void MainWindow::afficherHistoriqueCommandes(const QString &fournisseurId)
{
    QSqlQueryModel *histModel = new QSqlQueryModel(this);
    QSqlQuery query;
    query.prepare(
        "SELECT ID_COMMANDE, DATE_COMMANDE, QUANTITE_COMMANDE, MONTANT_TOTAL "
        "FROM COMMANDE "
        "WHERE ID_FOURNISSEUR = :id "
        "ORDER BY DATE_COMMANDE DESC"
        );
    query.bindValue(":id", fournisseurId);

    if (!query.exec()) {
        qDebug() << "Erreur SQL historique commandes :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de charger l'historique.");
        return;
    }

    histModel->setQuery(std::move(query));
    histModel->setHeaderData(0, Qt::Horizontal, "ID Commande");
    histModel->setHeaderData(1, Qt::Horizontal, "Date");
    histModel->setHeaderData(2, Qt::Horizontal, "Quantité");
    histModel->setHeaderData(3, Qt::Horizontal, "Montant (€)");

    ui->tableView_Historique->setModel(histModel);
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
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour récupérer les fournisseurs, quantité de commande et fréquence de commande
    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "NVL(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE, C.FREQUENCE_COMMANDE "
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
        model->setHeaderData(5, Qt::Horizontal, "Fréquence Commande");

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

    // Convertir le texte en index pour le switch
    QString selectedText = ui->comboBox_Tri->currentText();
    int orderIndex = (selectedText == "tri croissant") ? 1 : (selectedText == "tri décroissant") ? 2 : 0;

    // Variable pour le tri
    QString order;
    QString message;

    switch (orderIndex) {
    case 1: // tri croissant
        order = "ASC";
        message = "Tri effectué, résultats triés par quantité croissante.";
        break;
    case 2: // tri décroissant
        order = "DESC";
        message = "Tri effectué, résultats triés par quantité décroissante.";
        break;
    default:
        order = "ASC"; // Par défaut, tri croissant
        message = "Tri effectué, résultats triés par quantité croissante.";
        break;
    }

    // Requête SQL pour trier par quantité de commande
    query.prepare(QString("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                          "NVL(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                          "FROM FOURNISSEUR F "
                          "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR "
                          "ORDER BY QUANTITE_COMMANDE %1").arg(order));

    if (query.exec()) {
        model->setQuery(std::move(query));  // Effectuer la requête avec les nouvelles données triées

        // Définir les en-têtes des colonnes
        model->setHeaderData(0, Qt::Horizontal, "ID FOURNISSEUR");
        model->setHeaderData(1, Qt::Horizontal, "NOM");
        model->setHeaderData(2, Qt::Horizontal, "NUMÉRO TÉLÉPHONE");
        model->setHeaderData(3, Qt::Horizontal, "TYPE DE SERVICE");
        model->setHeaderData(4, Qt::Horizontal, "QUANTITÉ COMMANDE");

        // Appliquer le modèle au tableau pour afficher les résultats triés
        ui->tableView_Fournisseurs->setModel(model);

        // Afficher le message adapté au type de tri
        QMessageBox::information(this, "Tri effectué", message);
        qDebug() << message;
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







void MainWindow::envoyerSMS() {
    // Vérifier si un fournisseur est sélectionné dans le tableau
    int row = ui->tableView_Fournisseurs->currentIndex().row(); // Récupère la ligne sélectionnée

    if (row == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fournisseur !");
        return;
    }

    // Récupérer l'ID et la quantité du fournisseur sélectionné
    QString id_fournisseur = ui->tableView_Fournisseurs->model()->data(ui->tableView_Fournisseurs->model()->index(row, 0)).toString();
    QString quantite = ui->tableView_Fournisseurs->model()->data(ui->tableView_Fournisseurs->model()->index(row, 4)).toString();  // La quantité est dans la 5ème colonne (index 4)

    // Construire le message à envoyer
    QString message = "Fournisseur ID: " + id_fournisseur + " - Quantité de commande: " + quantite;

    // Paramètres Twilio pour l'envoi du SMS
    const QString TWILIO_ACCOUNT_SID = "AC1e7459302a1e433b4038abaf76edf9d2";
    const QString TWILIO_AUTH_TOKEN = "9c77cae2b4092b860ab82e54cca0c8e5";
    const QString TWILIO_PHONE = "+13156448652";

    // Créer un objet SMS et envoyer le message
    SMS sms(TWILIO_ACCOUNT_SID, TWILIO_AUTH_TOKEN, TWILIO_PHONE);
    bool success = sms.envoyerSMS("+21694321511", message); // Utiliser un numéro de téléphone valide

    if (success) {
        QMessageBox::information(this, "Succès", "Le SMS a été envoyé avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'envoi du SMS a échoué !");
    }
}




















void MainWindow::afficherStatistiques() {
    QSqlQuery query("SELECT TYPE_SERVICE, COUNT(*) FROM FOURNISSEUR GROUP BY TYPE_SERVICE");

    QPieSeries *series = new QPieSeries();

    // Total count to calculate percentage
    int totalCount = 0;

    // First, calculate the total number of suppliers
    while (query.next()) {
        totalCount += query.value(1).toInt();
    }

    // Reset query to loop through again to add slices to the pie chart
    query.first();  // Reset the query to the first row after calculation

    // Add the data to the pie chart
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();

        // Add slice to the pie series
        QPieSlice *slice = series->append(type, count);

        // Calculate the percentage for each slice
        double percentage = (count * 100.0) / totalCount;

        // Set label with the count and percentage
        slice->setLabel(QString("%1: %2 (%3%)").arg(type).arg(count).arg(QString::number(percentage, 'f', 1)));  // Example: "logistique: 15 (25.0%)"
        slice->setLabelVisible(true);  // Make sure labels are visible on the pie slices
    }

    // Create the chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par service");

    // Create the chart view and set rendering hint for anti-aliasing
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a dialog to display the chart
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->resize(600, 400);
    dialog->setWindowTitle("Statistiques Fournisseurs");

    // Execute the dialog
    dialog->exec();
}
