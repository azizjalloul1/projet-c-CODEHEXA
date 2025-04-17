#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

)");
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index){
        // index 1 correspond à l’onglet Affichage (à vérifier dans ton ordre d’onglets)
        if (index == 1) {
            afficherEtablissement();
        }
    });





    //  Contrôle ID & Contact
    QIntValidator *idValidator = new QIntValidator(0, 99999999, this);
    QIntValidator *contactValidator = new QIntValidator(10000000, 99999999, this);

    ui->ajout_id->setValidator(idValidator);
    ui->mod_id->setValidator(idValidator);
    ui->SuppID->setValidator(idValidator);
    ui->ajout_contact->setValidator(contactValidator);
    ui->mod_contact->setValidator(contactValidator);

    //  Contrôle Nom & Adresse = lettres uniquement
    QRegularExpression regex("^[A-Za-zÀ-ÿ\\s]+$");
    QRegularExpressionValidator *lettreValidator = new QRegularExpressionValidator(regex, this);
    ui->ajout_nom->setValidator(lettreValidator);
    ui->mod_nom->setValidator(lettreValidator);
    ui->ajout_adresse->setValidator(lettreValidator);
    ui->mod_adresse->setValidator(lettreValidator);

    // 🔗 Connexions
    connect(ui->ajout_button, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->SuppButton, &QPushButton::clicked, this, &MainWindow::on_SuppButton_clicked);
    connect(ui->mod_button, &QPushButton::clicked, this, &MainWindow::on_mod_button_clicked);
    connect(ui->aff_pdf, &QPushButton::clicked, this, &MainWindow::on_aff_pdf_clicked);
    connect(ui->aff_rech, &QLineEdit::textChanged, this, &MainWindow::on_aff_rech_clicked);
    connect(ui->aff_tri, &QPushButton::clicked, this, &MainWindow::on_aff_tri_clicked);
    connect(ui->mod_id, &QLineEdit::textChanged, this, &MainWindow::remplirChampsModification);
    connect(ui->btn_stats, &QPushButton::clicked, this, &MainWindow::on_btn_stats_clicked);
    connect(ui->btn_geo, &QPushButton::clicked, this, &MainWindow::on_btn_geo_clicked);
    connect(ui->btn_path, &QPushButton::clicked, this, &MainWindow::on_btn_path_clicked);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::afficherEtablissement() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT");
    ui->tableView_Etablissements->setModel(model);
}

void MainWindow::clearInputs() {
    ui->ajout_id->clear();
    ui->ajout_nom->clear();
    ui->ajout_adresse->clear();
    ui->ajout_contact->clear();
    ui->ajout_type->setCurrentIndex(0);
    ui->mod_id->clear();
    ui->mod_nom->clear();
    ui->mod_adresse->clear();
    ui->mod_contact->clear();
    ui->mod_type->setCurrentIndex(0);
    ui->SuppID->clear();
    ui->aff_rech->clear();
}

void MainWindow::on_addButton_clicked() {
    QString id_E = ui->ajout_id->text().trimmed();
    QString nom = ui->ajout_nom->text().trimmed();
    QString adresse = ui->ajout_adresse->text().trimmed();
    QString contact = ui->ajout_contact->text().trimmed();
    QString type_etablissement = ui->ajout_type->currentText().trimmed();

    // 🔒 Vérification d'abord : tous les champs remplis
    if (id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // 📌 Regex de validation
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

    // ✅ Si tout est OK, on ajoute
    Etablissement e(id_E, nom, adresse, contact, type_etablissement);
    if (e.ajouterEtablissement()) {
        QMessageBox::information(this, "Succès", "Établissement ajouté avec succès !");
        afficherEtablissement();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
    }
}

void MainWindow::on_mod_button_clicked() {
    QString id_E = ui->mod_id->text().trimmed();
    QString nom = ui->mod_nom->text().trimmed();
    QString adresse = ui->mod_adresse->text().trimmed();
    QString contact = ui->mod_contact->text().trimmed();
    QString type_etablissement = ui->mod_type->currentText().trimmed();

    // Regex
    QRegularExpression regexLettre("^[A-Za-zÀ-ÿ\\s]+$");  // Lettres avec accents
    QRegularExpression regexChiffre("^[0-9]+$");          // Chiffres uniquement

    // ✅ Vérifications
    if (id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty()) {
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

    // ✅ Si tout est bon, on modifie
    Etablissement e(id_E, nom, adresse, contact, type_etablissement);
    if (e.modifierEtablissement(id_E, nom, adresse, contact, type_etablissement)) {
        QMessageBox::information(this, "Succès", "Modification réussie !");
        afficherEtablissement();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur de modification !");
    }
}


void MainWindow::remplirChampsModification(const QString& id_E) {
    QSqlQuery query;
    query.prepare("SELECT NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E);

    if (query.exec() && query.next()) {
        ui->mod_nom->setText(query.value(0).toString());
        ui->mod_adresse->setText(query.value(1).toString());
        ui->mod_contact->setText(query.value(2).toString());
        ui->mod_type->setCurrentText(query.value(3).toString());
    } else {
        ui->mod_nom->clear();
        ui->mod_adresse->clear();
        ui->mod_contact->clear();
        ui->mod_type->setCurrentIndex(0);
    }
}
void MainWindow::on_aff_rech_clicked() {
    QString rech_nom = ui->aff_rech->text().trimmed();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    if (rech_nom.isEmpty()) {
        afficherEtablissement();
        return;
    }

    query.prepare("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT WHERE NOM LIKE :nom");
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

    ui->tableView_Etablissements->setModel(model);
}


void MainWindow::on_SuppButton_clicked() {
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

void MainWindow::on_aff_pdf_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QSqlQuery query("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT");
    QString html = R"(
        <html><head><style>
        h1 { text-align: center; font-weight: bold; }
        table { width: 100%; border-collapse: collapse; margin-top: 20px; }
        th, td { border: 1px solid black; padding: 6px; text-align: center; }
        th { background-color: #002366; color: white; }
        footer { margin-top: 20px; font-size: 10pt; text-align: right; }
        </style></head><body>
        <h1>Rapport des Établissements</h1>
        <table><tr>
        <th>ID</th><th>Nom</th><th>Adresse</th><th>Contact</th><th>Type</th>
        </tr>
    )";

    while (query.next()) {
        html += "<tr><td>" + query.value(0).toString() + "</td>"
                                                         "<td>" + query.value(1).toString() + "</td>"
                                              "<td>" + query.value(2).toString() + "</td>"
                                              "<td>" + query.value(3).toString() + "</td>"
                                              "<td>" + query.value(4).toString() + "</td></tr>";
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

void MainWindow::on_aff_tri_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT ORDER BY TYPE_ETABLISSEMENT ASC");
    model->setQuery(std::move(query));
    ui->tableView_Etablissements->setModel(model);
}

void MainWindow::on_btn_stats_clicked() {
    StatsWindow *stats = new StatsWindow(this);
    stats->exec();
}

void MainWindow::on_btn_geo_clicked() {
    QModelIndex index = ui->tableView_Etablissements->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Aucun établissement sélectionné", "Veuillez sélectionner un établissement.");
        return;
    }

    QString nom = ui->tableView_Etablissements->model()->data(ui->tableView_Etablissements->model()->index(index.row(), 1)).toString();
    QString adresse = ui->tableView_Etablissements->model()->data(ui->tableView_Etablissements->model()->index(index.row(), 2)).toString();

    if (nom.isEmpty() || adresse.isEmpty()) {
        QMessageBox::warning(this, "Données manquantes", "Nom ou adresse de l’établissement manquant.");
        return;
    }

    QString recherche = nom + ", " + adresse;
    QString url = "https://www.google.com/maps/search/?api=1&query=" + QUrl::toPercentEncoding(recherche);
    QDesktopServices::openUrl(QUrl(url));
}


void MainWindow::on_btn_path_clicked() {
    QModelIndex index = ui->tableView_Etablissements->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Sélection invalide", "Veuillez sélectionner un établissement dans le tableau.");
        return;
    }

    // Récupérer le nom et l'adresse de l'établissement sélectionné
    QString nom = ui->tableView_Etablissements->model()->data(ui->tableView_Etablissements->model()->index(index.row(), 1)).toString();
    QString adresse = ui->tableView_Etablissements->model()->data(ui->tableView_Etablissements->model()->index(index.row(), 2)).toString();

    if (nom.isEmpty() || adresse.isEmpty()) {
        QMessageBox::warning(this, "Données manquantes", "Nom ou adresse manquant(e) pour l’établissement sélectionné.");
        return;
    }

    QString destination = nom + ", " + adresse;

    // Utilise la position actuelle automatiquement détectée par le navigateur
    QString url = "https://www.google.com/maps/dir/?api=1"
                  "&origin=My+Location"
                  "&destination=" + QUrl::toPercentEncoding(destination);

    QDesktopServices::openUrl(QUrl(url));
}
