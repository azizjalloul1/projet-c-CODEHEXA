#include "mainwindowE.h"
#include "ui_mainwindowE.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QDateTime>
#include <QSqlQuery>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include "statswindow.h"
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>         // pour rootContext()
#include <QQmlEngine>          // pour QQmlEngine
#include <QtQuickWidgets/QQuickWidget>  // pour QQuickWidget
#include "PathWindow.h"
#include <QGeoCoordinate>

MainWindowE::MainWindowE(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowE) {
    ui->setupUi(this);
    currentPosition = QGeoCoordinate(36.899, 10.19); // ✔️ ESPRIT Petite Ariana

    qDebug() << "Position fixe définie :" << currentPosition;




    // Chargement dynamique des établissements pour la carte
    afficherCarteEtablissements();

    this->setStyleSheet(R"(
        QWidget {
            font-family: 'Segoe UI', sans-serif;
            font-size: 14px;
            background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #dbeeff, stop:1 #eaf6ff);
        }
        QPushButton {
            background-color: #0078d7;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 6px;
        }
        QPushButton:hover {
            background-color: #005fa1;
        }
        QLineEdit, QComboBox {
            background-color: white;
            border: 1px solid #ccc;
            padding: 6px;
            border-radius: 4px;
        }
        QTableView {
            background-color: white;
            border: 1px solid #ccc;
            gridline-color: #e0e0e0;
            selection-background-color: #a6d5ff;
            selection-color: black;
        }
        QHeaderView::section {
            background-color: #004b91;
            color: white;
            font-weight: bold;
            padding: 6px;
            border: 1px solid #ddd;
        }
        QGroupBox {
            border: 1px solid #9fbcd9;
            border-radius: 8px;
            margin-top: 12px;
        }
        QLabel {
            font-weight: bold;
            color: #333;
        }
        QComboBox {
            background-color: #0078d7;
            color: white;
            border: none;
            padding: 6px 12px;
            border-radius: 6px;
            font-weight: bold;
            min-width: 160px;
        }
        QComboBox:hover {
            background-color: #005fa1;
        }
        QComboBox::drop-down {
            border: none;
            background: transparent;
        }
        QComboBox QAbstractItemView {
            background-color: white;
            selection-background-color: #0078d7;
            selection-color: white;
            font-weight: normal;
        }
    )");

    // Connexion du changement d'onglet
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index){
        if (index == 1) {
            afficherEtablissement();
        }
    });

    // Validateurs
    QIntValidator *idValidator = new QIntValidator(0, 99999999, this);
    QIntValidator *contactValidator = new QIntValidator(10000000, 99999999, this);
    QRegularExpression regex("^[A-Za-zÀ-ÿ\\s]+$");
    QRegularExpressionValidator *lettreValidator = new QRegularExpressionValidator(regex, this);

    ui->ajout_id->setValidator(idValidator);
    ui->mod_id->setValidator(idValidator);
    ui->SuppID->setValidator(idValidator);
    ui->ajout_contact->setValidator(contactValidator);
    ui->mod_contact->setValidator(contactValidator);
    ui->ajout_nom->setValidator(lettreValidator);
    ui->mod_nom->setValidator(lettreValidator);
    ui->ajout_adresse->setValidator(lettreValidator);
    ui->mod_adresse->setValidator(lettreValidator);

    // Connexions des boutons
    connect(ui->ajout_button, &QPushButton::clicked, this, &MainWindowE::on_addButton_clicked);
    connect(ui->SuppButton, &QPushButton::clicked, this, &MainWindowE::on_SuppButton_clicked);
    connect(ui->mod_button, &QPushButton::clicked, this, &MainWindowE::on_mod_button_clicked);
    connect(ui->aff_pdf, &QPushButton::clicked, this, &MainWindowE::on_aff_pdf_clicked);
    connect(ui->aff_rech, &QLineEdit::textChanged, this, &MainWindowE::on_aff_rech_clicked);
    connect(ui->triComboBox, &QComboBox::currentTextChanged, this, &MainWindowE::on_triComboBox_currentTextChanged);
    connect(ui->mod_id, &QLineEdit::textChanged, this, &MainWindowE::remplirChampsModification);
    connect(ui->btn_stats, &QPushButton::clicked, this, &MainWindowE::on_btn_stats_clicked);
    connect(ui->tableView_Etablissements, &QTableView::clicked,
            this, &MainWindowE::on_tableView_Etablissements_clicked);
    connect(ui->btn_path, &QPushButton::clicked, this, &MainWindowE::on_btn_path_clicked);



}

MainWindowE::~MainWindowE() {
    delete ui;
}
void MainWindowE::afficherEtablissement() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT");
    ui->tableView_Etablissements->setModel(model);
}

void MainWindowE::afficherCarteEtablissements() {
    QList<Etablissement> etablissements = Etablissement::afficherEtablissement();

    QVariantList markers;
    for (const Etablissement &e : etablissements) {
        QVariantMap marker;
        marker["latitude"] = e.getLatitude().toDouble();
        marker["longitude"] = e.getLongitude().toDouble();
        marker["nom"] = e.getNOM();
        markers.append(marker);
    }

    ui->quickWidget_MapView->engine()->rootContext()->setContextProperty("etabModel", QVariant::fromValue(markers));
    ui->quickWidget_MapView->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget_MapView->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->quickWidget_MapView->show();
}


void MainWindowE::clearInputs() {
    ui->ajout_id->clear();
    ui->ajout_nom->clear();
    ui->ajout_adresse->clear();
    ui->ajout_contact->clear();
    ui->ajout_type->setCurrentIndex(0);
    ui->ajout_latitude->clear();
    ui->ajout_longitude->clear();
    ui->mod_id->clear();
    ui->mod_nom->clear();
    ui->mod_adresse->clear();
    ui->mod_contact->clear();
    ui->mod_type->setCurrentIndex(0);
    ui->mod_latitude->clear();
    ui->mod_longitude->clear();
    ui->SuppID->clear();
    ui->aff_rech->clear();
}

void MainWindowE::on_addButton_clicked() {
    QString id_E = ui->ajout_id->text().trimmed();
    QString nom = ui->ajout_nom->text().trimmed();
    QString adresse = ui->ajout_adresse->text().trimmed();
    QString contact = ui->ajout_contact->text().trimmed();
    QString type_etablissement = ui->ajout_type->currentText().trimmed();
    QString latitude = ui->ajout_latitude->text().trimmed();
    QString longitude = ui->ajout_longitude->text().trimmed();



    if (id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty() || latitude.isEmpty() || longitude.isEmpty() ) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }


    QRegularExpression regexLettre("^[A-Za-zÀ-ÿ\\s]+$");
    QRegularExpression regexChiffre("^[0-9]+$");

    if (!regexChiffre.match(id_E).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir uniquement des chiffres !");
        return;
    }

    if (!regexLettre.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom doit contenir uniquement des lettres !");
        return;
    }

    if (!regexLettre.match(adresse).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'adresse doit contenir uniquement des lettres !");
        return;
    }

    if (!regexChiffre.match(contact).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le contact doit contenir uniquement des chiffres !");
        return;
    }


    Etablissement e(id_E, nom, adresse, contact, type_etablissement, latitude, longitude);
    if (e.ajouterEtablissement()) {
        QMessageBox::information(this, "Succès", "Établissement ajouté avec succès !");
        afficherEtablissement();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
    }
}

void MainWindowE::on_mod_button_clicked() {
    QString id_E = ui->mod_id->text().trimmed();
    QString nom = ui->mod_nom->text().trimmed();
    QString adresse = ui->mod_adresse->text().trimmed();
    QString contact = ui->mod_contact->text().trimmed();
    QString type_etablissement = ui->mod_type->currentText().trimmed();
    QString latitude = ui->mod_latitude->text().trimmed();
    QString longitude = ui->mod_longitude->text().trimmed();



    QRegularExpression regexLettre("^[A-Za-zÀ-ÿ\\s]+$");
    QRegularExpression regexChiffre("^[0-9]+$");


    if (id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty() || latitude.isEmpty() || longitude.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    if (!regexChiffre.match(id_E).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir uniquement des chiffres !");
        return;
    }

    if (!regexLettre.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom doit contenir uniquement des lettres !");
        return;
    }

    if (!regexLettre.match(adresse).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'adresse doit contenir uniquement des lettres !");
        return;
    }

    if (!regexChiffre.match(contact).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le contact doit contenir uniquement des chiffres !");
        return;
    }

    if (!Etablissement::idExisteDeja(id_E)) {
        QMessageBox::critical(this, "Erreur", "Aucun établissement avec cet ID.");
        return;
    }


    Etablissement e(id_E, nom, adresse, contact, type_etablissement, latitude, longitude);
    if (e.modifierEtablissement(id_E, nom, adresse, contact, type_etablissement, latitude, longitude)) {
        QMessageBox::information(this, "Succès", "Modification réussie !");
        afficherEtablissement();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur de modification !");
    }
}


void MainWindowE::remplirChampsModification(const QString& id_E) {
    QSqlQuery query;
    query.prepare("SELECT NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E);

    if (query.exec() && query.next()) {
        ui->mod_nom->setText(query.value(0).toString());
        ui->mod_adresse->setText(query.value(1).toString());
        ui->mod_contact->setText(query.value(2).toString());
        ui->mod_type->setCurrentText(query.value(3).toString());
        ui->mod_latitude->setText(query.value(4).toString());
        ui->mod_longitude->setText(query.value(5).toString());

    } else {
        ui->mod_nom->clear();
        ui->mod_adresse->clear();
        ui->mod_contact->clear();
        ui->mod_type->setCurrentIndex(0);
        ui->mod_latitude->clear();
        ui->mod_longitude->clear();
    }
}
void MainWindowE::on_aff_rech_clicked() {
    QString rech_nom = ui->aff_rech->text().trimmed();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    if (rech_nom.isEmpty()) {
        afficherEtablissement();
        return;
    }

    query.prepare("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + rech_nom + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche !");
        return;
    }

    model->setQuery(std::move(query));
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Adresse");
    model->setHeaderData(3, Qt::Horizontal, "Contact");
    model->setHeaderData(4, Qt::Horizontal, "Type");
    model->setHeaderData(5, Qt::Horizontal, "Latitude");
    model->setHeaderData(6, Qt::Horizontal, "Longitude");

    ui->tableView_Etablissements->setModel(model);
}


void MainWindowE::on_SuppButton_clicked() {
    QString id_E = ui->SuppID->text().trimmed();
    if (id_E.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID.");
        return;
    }

    if (etablissement.supprimerEtablissement(id_E)) {
        QMessageBox::information(this, "Succès", "Établissement supprimé.");
        afficherEtablissement();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}
void MainWindowE::on_aff_pdf_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QSqlQuery query("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT");

    QString imagePath = "file:///C:/Users/khemi/Desktop/etablissements/logo.png";


    QString html = R"(
        <html>
        <head>
        <style>
            h1 {
                text-align: center;
                font-weight: bold;
                color: #002366;
                margin-top: 10px;
            }
            table {
                width: 95%;
                border-collapse: collapse;
                margin: 30px auto;
            }
            th, td {
                border: 1px solid black;
                padding: 6px;
                text-align: center;
            }
            th {
                background-color: #002366;
                color: white;
            }
            footer {
                margin-top: 20px;
                font-size: 10pt;
                text-align: right;
            }
        </style>
        </head>
        <body>
    )";

    html += "<img src=\"" + imagePath + "\" width=\"80\" style=\"float: left; margin: 10px;\" />";
    html += "<h1>Rapport des Établissements</h1><br><br><br>";

    html += R"(
        <table>
        <tr>
            <th>ID</th><th>Nom</th><th>Adresse</th><th>Contact</th><th>Type</th>
        </tr>
    )";

    while (query.next()) {
        html += "<tr><td>" + query.value(0).toString() + "</td>"
                                                         "<td>" + query.value(1).toString() + "</td>"
                                              "<td>" + query.value(2).toString() + "</td>"
                                              "<td>" + query.value(3).toString() + "</td>"
                                              "<td>" + query.value(4).toString() + "</td>"
                                              "<td>" + query.value(5).toString() + "</td>"
                                              "<td>" + query.value(6).toString() + "</td></tr>";
    }

    html += "</table><footer>Généré le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss") + "</footer></body></html>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);

    QMessageBox::information(this, "Succès", "Export PDF réussi !");
}


void MainWindowE::on_triComboBox_currentTextChanged(const QString &text) {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    if (text == "Trier par ID croissant") {
        query.prepare("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT ORDER BY ID_E ASC");
    } else if (text == "Trier par ID décroissant") {
        query.prepare("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT ORDER BY ID_E DESC");
    }

    if (query.exec()) {
        model->setQuery(std::move(query));
        ui->tableView_Etablissements->setModel(model);
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de trier les données !");
    }
}


void MainWindowE::on_btn_stats_clicked() {
    StatsWindow *stats = new StatsWindow(this);
    stats->exec();
}
void MainWindowE::on_tableView_Etablissements_clicked(const QModelIndex &index) {
    int row = index.row();

    QString nom = ui->tableView_Etablissements->model()->index(row, 1).data().toString();
    QString latitudeStr = ui->tableView_Etablissements->model()->index(row, 5).data().toString();
    QString longitudeStr = ui->tableView_Etablissements->model()->index(row, 6).data().toString();

    // Nettoyage : supprimer les caractères non numériques, points ou tirets
    latitudeStr.remove(QRegularExpression("[^\\d\\.-]"));
    longitudeStr.remove(QRegularExpression("[^\\d\\.-]"));

    bool okLat, okLon;
    double latitude = latitudeStr.toDouble(&okLat);
    double longitude = longitudeStr.toDouble(&okLon);

    if (okLat && okLon) {
        QObject *qmlRoot = ui->quickWidget_MapView->rootObject();

        if (qmlRoot) {
            QMetaObject::invokeMethod(qmlRoot, "addSingleMarker",
                                      Q_ARG(QVariant, latitude),
                                      Q_ARG(QVariant, longitude),
                                      Q_ARG(QVariant, nom));
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de convertir les coordonnées.");
    }
}
void MainWindowE::calculerCheminVersEtablissement(double destLat, double destLon) {
    if (!currentPosition.isValid()) {
        QMessageBox::warning(this, "Erreur", "Position actuelle invalide.");
        return;
    }

    double userLat = currentPosition.latitude();
    double userLon = currentPosition.longitude();

    QVariantList coords;
    QVariantMap from, to;

    from["latitude"] = userLat;
    from["longitude"] = userLon;
    to["latitude"] = destLat;
    to["longitude"] = destLon;

    coords.append(from);
    coords.append(to);

    QMetaObject::invokeMethod(
        ui->quickWidget_MapView->rootObject(),
        "setRoute",
        Q_ARG(QVariant, QVariant::fromValue(coords))
        );
}

void MainWindowE::mettreAJourPositionUtilisateur(const QGeoPositionInfo &info) {
    if (info.isValid()) {
        currentPosition = info.coordinate();
        qDebug() << "Position actuelle mise à jour :" << currentPosition;
    }
}
Etablissement MainWindowE::getSelectedEtablissement() {
    QModelIndex index = ui->tableView_Etablissements->currentIndex();
    if (!index.isValid()) return Etablissement();

    int row = index.row();
    QString id = ui->tableView_Etablissements->model()->index(row, 0).data().toString();
    QString nom = ui->tableView_Etablissements->model()->index(row, 1).data().toString();
    QString adresse = ui->tableView_Etablissements->model()->index(row, 2).data().toString();
    QString contact = ui->tableView_Etablissements->model()->index(row, 3).data().toString();
    QString type = ui->tableView_Etablissements->model()->index(row, 4).data().toString();
    QString lat = ui->tableView_Etablissements->model()->index(row, 5).data().toString();
    QString lon = ui->tableView_Etablissements->model()->index(row, 6).data().toString();

    return Etablissement(id, nom, adresse, contact, type, lat, lon);
}
void MainWindowE::on_btn_path_clicked()
{
    Etablissement selected = getSelectedEtablissement();

    if (selected.getLatitude().isEmpty() || selected.getLongitude().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un établissement avec des coordonnées valides.");
        return;
    }

    double destLat = selected.getLatitude().toDouble();
    double destLon = selected.getLongitude().toDouble();

    // ✅ Position fixe : Esprit Ariana
    QGeoCoordinate from(36.8625, 10.1956);  // Fixé
    QGeoCoordinate to(destLat, destLon);

    PathWindow *window = new PathWindow(from, to);
    window->show();
}
