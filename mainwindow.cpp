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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Id->setReadOnly(true);

    Connexion c;
    if (!c.ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
        return;
    }

    genererIDFournisseur();
    afficherFournisseurs();
    chargerListeIDs();

    connect(ui->comboBox_IdModif, &QComboBox::currentIndexChanged, this, &MainWindow::remplirChampsFournisseur);
    connect(ui->triButton, &QPushButton::clicked, this, &MainWindow::trierParCommande);
    connect(ui->btnExporterPDF, &QPushButton::clicked, this, &MainWindow::exporterEnPDF);
    connect(ui->btnRechercher, &QLineEdit::textChanged, this, &MainWindow::onRechercherClicked);
}

MainWindow::~MainWindow() {
    delete ui;
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

void MainWindow::on_btnAjouter_clicked() {
    QString id_fournisseur = ui->lineEdit_Id->text().trimmed();
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString num_tel = ui->lineEdit_NumTel->text().trimmed();
    QString type_service = ui->comboBox_TypeService_2->currentText().trimmed();

    if (nom.isEmpty() || num_tel.isEmpty() || type_service.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    static const QRegularExpression nomRegex("^[a-zA-Z]+$");
    static const QRegularExpression telRegex("^[0-9]{8}$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres !");
        return;
    }
    if (!telRegex.match(num_tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir 8 chiffres !");
        return;
    }

    Fournisseur f(id_fournisseur, nom, num_tel, type_service);
    if (f.ajouterFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");

        SMS sms("AC1e7459302a1e433b4038abaf76edf9d2", "9c77cae2b4092b860ab82e54cca0c8e5", "+13156448652");
        sms.envoyerSMS("+21694321511", "Fournisseur ajouté avec ID: " + id_fournisseur);

        int quantite = QRandomGenerator::global()->bounded(10, 201);
        QSqlQuery query;
        query.prepare("INSERT INTO COMMANDE (ID_COMMANDE, ID_FOURNISSEUR, QUANTITE_COMMANDE) "
                      "VALUES ((SELECT COALESCE(MAX(ID_COMMANDE), 0) + 1 FROM COMMANDE), :id, :qte)");
        query.bindValue(":id", id_fournisseur);
        query.bindValue(":qte", quantite);
        query.exec();

        afficherFournisseurs();
        chargerListeIDs();

        ui->lineEdit_Nom->clear();
        ui->lineEdit_NumTel->clear();
        ui->comboBox_TypeService_2->setCurrentIndex(0);

        genererIDFournisseur(); // re-générer un ID disponible
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du fournisseur !");
    }
}

// Ajoute aussi la déclaration suivante dans mainwindow.h :
// void genererIDFournisseur();

void MainWindow::afficherStatistiques() {
    QSqlQuery query("SELECT TYPE_SERVICE, COUNT(*) FROM FOURNISSEUR GROUP BY TYPE_SERVICE");

    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(type, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par service");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->resize(500, 400);
    dialog->setWindowTitle("Statistiques Fournisseurs");
    dialog->exec();
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
    if (fileName.isEmpty()) return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);

    // 📷 Logo
    QImage image("C:/Users/ASUS/Desktop/Projet_QT/FOURNISSEURS/mm.png");
    if (!image.isNull()) {
        QRect imgRect((pdfWriter.width() - 250) / 2, 40, 250, 100);
        painter.drawImage(imgRect, image);
    }

    // 🏷️ Titre
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(QRect(0, 150, pdfWriter.width(), 50), Qt::AlignCenter, "📋 Liste des Fournisseurs");

    // 🔍 Requête SQL
    QSqlQuery query;
    query.prepare("SELECT F.ID_FOURNISSEUR, F.NOM, F.NUM_TEL, F.TYPE_SERVICE, "
                  "COALESCE(C.QUANTITE_COMMANDE, 0) AS QUANTITE_COMMANDE "
                  "FROM FOURNISSEUR F "
                  "LEFT JOIN COMMANDE C ON F.ID_FOURNISSEUR = C.ID_FOURNISSEUR");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exportation des données !");
        return;
    }

    // 📊 Table Configuration
    int rowHeight = 60;
    int colWidths[] = {80, 180, 180, 220, 120};
    int totalWidth = 0;
    for (int w : colWidths) totalWidth += w;
    int startX = (pdfWriter.width() - totalWidth) / 2;
    int startY = 230;

    QStringList headers = {"ID", "Nom", "Téléphone", "Service", "Quantité"};

    // 🧾 En-têtes
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setBrush(QColor(220, 220, 220));
    int xPos = startX;

    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(xPos, startY, colWidths[i], rowHeight);
        painter.drawText(QRect(xPos, startY, colWidths[i], rowHeight),
                         Qt::AlignCenter, headers[i]);
        xPos += colWidths[i];
    }

    // 🧾 Données
    painter.setBrush(Qt::NoBrush);
    painter.setFont(QFont("Arial", 11));
    startY += rowHeight;

    while (query.next()) {
        xPos = startX;
        for (int i = 0; i < headers.size(); ++i) {
            painter.drawRect(xPos, startY, colWidths[i], rowHeight);
            painter.drawText(QRect(xPos + 5, startY + 5, colWidths[i] - 10, rowHeight - 10),
                             Qt::AlignLeft | Qt::AlignVCenter,
                             query.value(i).toString());
            xPos += colWidths[i];
        }
        startY += rowHeight;
    }

    painter.end();
    QMessageBox::information(this, "PDF Exporté", "📄 Le fichier a été exporté avec succès !");
}


void MainWindow::remplirChampsFournisseur() {
    QString id_fournisseur = ui->comboBox_IdModif->currentText().trimmed();
    if (id_fournisseur.isEmpty()) return;

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
        QString typeService = query.value(2).toString();
        int index = ui->comboBox_TypeServiceModif->findText(typeService);
        if (index != -1) {
            ui->comboBox_TypeServiceModif->setCurrentIndex(index);
        } else {
            qDebug() << "Type de service introuvable dans le ComboBox :" << typeService;
        }
    }
}




