#include "mainwindowF.h"
#include "ui_mainwindowF.h"
#include "fournisseur.h"
#include "connexion.h"
#include "sms.h"
#include <QImage>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPageSize>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFileDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QPainter>
#include <QPdfWriter>
#include <QImage>
#include <QSslSocket>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QByteArray>
#include "accueil.h"


MainWindowF::MainWindowF(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowF)
    , m_sms(new SMS(
          "AC1e7459302a1e433b4038abaf76edf9d2",  // votre Account SID
          "9c77cae2b4092b860ab82e54cca0c8e5",     // votre Auth Token
          "+13156448652",                        // votre numéro Twilio
          this                                   // parent
          ))
{
    ui->setupUi(this);


    // Vérifie SSL
    qDebug() << "SSL supporté ? " << QSslSocket::supportsSsl();
    qDebug() << "SSL build version : " << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "SSL runtime version : " << QSslSocket::sslLibraryVersionString();

    // Ouvre la connexion à la BDD
    Connexion c;
    if (!c.ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la BDD !");
        //qDebug() << c.ouvrirConnexion().lastError().text();
    }

    // Initialisation
    genererIDFournisseur();
    afficherFournisseurs();
    chargerListeIDs();

    // Signaux / slots
    connect(ui->comboBox_IdModif, &QComboBox::currentIndexChanged,
            this, &MainWindowF::remplirChampsFournisseur);
    connect(ui->comboBox_Tri, &QComboBox::currentIndexChanged,
            this, &MainWindowF::trierParCommande);
    connect(ui->btnExporterPDF, &QPushButton::clicked,
            this, &MainWindowF::exporterEnPDF);
    connect(ui->btnEnvoyerSMS, &QPushButton::clicked,
            this, &MainWindowF::envoyerSMS);
    connect(ui->btnStatistiques, &QPushButton::clicked,
            this, &MainWindowF::afficherStatistiques);
    connect(ui->btnRechercher, &QLineEdit::textChanged,
            this, &MainWindowF::onRechercherClicked);

    connect(ui->r1, &QPushButton::clicked, this, &::MainWindowF::retour);
}

MainWindowF::~MainWindowF()
{
    delete ui;
}

void MainWindowF::setAccueil(Accueil *accueilWindow) {
    this->accueil = accueilWindow;
}

void MainWindowF::retour()
{
    this->hide();           // cacher MainWindow
    if (accueil) {
        accueil->show();    // montrer Accueil
    }
}

void MainWindowF::on_btnMeilleurFournisseur_clicked()
{
    // Requête pour trouver le fournisseur avec le plus de quantités fournies
    static const QString sql = R"(
        SELECT
            F.ID_FOURNISSEUR,
            F.NOM,
            F.TYPE_SERVICE,
            NVL(S.QUANTITE_TOTALE, 0) AS TOTAL_QUANTITE
        FROM FOURNISSEUR F
        LEFT JOIN (
            SELECT
                ID_FOURNISSEUR,
                SUM(QUANTITE) AS QUANTITE_TOTALE
            FROM FOURNIR
            GROUP BY ID_FOURNISSEUR
        ) S
          ON F.ID_FOURNISSEUR = S.ID_FOURNISSEUR
        ORDER BY TOTAL_QUANTITE DESC
    )";

    // Affichage dans le tableau
    auto *model = new QSqlQueryModel(this);
    model->setQuery(sql);
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Info", "Aucun fournisseur trouvé.");
        return;
    }
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Service");
    model->setHeaderData(3, Qt::Horizontal, "Total fournis");
    ui->tableView_Fournisseurs->setModel(model);

    // Récupère la première ligne (le meilleur)
    QString id       = model->data(model->index(0, 0)).toString();
    QString nom      = model->data(model->index(0, 1)).toString();
    QString type     = model->data(model->index(0, 2)).toString();
    int     totalQty = model->data(model->index(0, 3)).toInt();

    // Prépare et envoie l'email
    const QString to      = "molkaomrani1412@gmail.com";
    QString sujet         = QString("Meilleur fournisseur : %1").arg(nom);
    QString corps         = QString(R"(
Détails du fournisseur ayant fourni le plus :

• ID              : %1
• Nom             : %2
• Service         : %3
• Total fourni    : %4 unités
)").arg(id, nom, type).arg(QString::number(totalQty));

    envoyerEmailSMTP(to, sujet, corps);
}

void MainWindowF::envoyerEmailSMTP(const QString &to,
                                   const QString &subject,
                                   const QString &body)
{
    auto *client = new SmtpClient(
        "smtp.gmail.com", 465,
        "molkaomrani1412@gmail.com",
        "ZylgLvByXVvbOpWh",
        true,
        this
        );
    connect(client, &SmtpClient::statusMessage,
            this, &MainWindowF::onSmtpStatus);

    client->sendMail(
        "molkaomrani1412@gmail.com",
        to,
        subject,
        body
        );
    connect(client, &SmtpClient::statusMessage, client,
            [client](const QString &msg) {
                if (msg.startsWith("221"))
                    client->deleteLater();
            });
}

void MainWindowF::onSmtpStatus(const QString &msg)
{
    qDebug() << "[SMTP]" << msg;
    if (msg.startsWith("250 "))
        QMessageBox::information(this, "Email", "Email envoyé avec succès !");
}

void MainWindowF::genererIDFournisseur()
{
    QSqlQuery q;
    q.prepare(R"(
        SELECT MIN(t1.ID_FOURNISSEUR + 1)
          FROM FOURNISSEUR t1
         WHERE NOT EXISTS (
               SELECT 1 FROM FOURNISSEUR t2
                WHERE t2.ID_FOURNISSEUR = t1.ID_FOURNISSEUR + 1
         )
    )");
    int nextId = 1;
    if (q.exec() && q.next()) {
        auto v = q.value(0);
        if (v.isValid() && !v.isNull())
            nextId = v.toInt();
    }
    q.exec("SELECT COUNT(*) FROM FOURNISSEUR");
    if (q.next() && q.value(0).toInt() == 0)
        nextId = 1;

    ui->lineEdit_Id->setText(QString::number(nextId));
}

void MainWindowF::on_btnAjouter_clicked()
{
    QString id   = ui->lineEdit_Id->text().trimmed();
    QString nom  = ui->lineEdit_Nom->text().trimmed();
    QString tel  = ui->lineEdit_NumTel->text().trimmed();
    QString svc  = ui->comboBox_TypeService_2->currentText().trimmed();

    // Validations
    if (id.isEmpty() || nom.isEmpty() || tel.isEmpty() || svc.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }
    if (!QRegularExpression("^[0-9]+$").match(id).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être numérique !");
        return;
    }
    if (!QRegularExpression("^[a-zA-Z]+$").match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom doit être lettres uniquement !");
        return;
    }
    if (!QRegularExpression("^[0-9]{8}$").match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le téléphone doit faire 8 chiffres !");
        return;
    }

    // Ajoute le fournisseur
    Fournisseur f(id, nom, tel, svc);
    if (!f.ajouterFournisseur()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
        return;
    }

    // Insère une commande aléatoire
    int qte = QRandomGenerator::global()->bounded(10, 201);
    QSqlQuery qc;
    qc.prepare(R"(
        INSERT INTO COMMANDE(ID_COMMANDE, ID_FOURNISSEUR, QUANTITE_COMMANDE)
        VALUES((SELECT COALESCE(MAX(ID_COMMANDE),0)+1 FROM COMMANDE), :id, :qte)
    )");
    qc.bindValue(":id", id);
    qc.bindValue(":qte", qte);
    qc.exec();

    QMessageBox::information(this, "Succès", "Fournisseur ajouté !");
    genererIDFournisseur();
    afficherFournisseurs();
}

void MainWindowF::remplirChampsFournisseur()
{
    QString id = ui->comboBox_IdModif->currentText().trimmed();
    if (id.isEmpty()) return;

    QSqlQuery q;
    q.prepare("SELECT NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    q.bindValue(":id", id);
    if (!q.exec() || !q.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger le fournisseur !");
        return;
    }

    ui->lineEdit_NomModif->setText(q.value(0).toString());
    ui->lineEdit_NumTelModif->setText(q.value(1).toString());

    QString svc = q.value(2).toString();
    int idx = ui->comboBox_TypeServiceModif->findText(svc);
    if (idx >= 0) ui->comboBox_TypeServiceModif->setCurrentIndex(idx);
}

void MainWindowF::on_btnModifier_clicked()
{
    QString id   = ui->comboBox_IdModif->currentText().trimmed();
    QString nom  = ui->lineEdit_NomModif->text().trimmed();
    QString tel  = ui->lineEdit_NumTelModif->text().trimmed();
    QString svc  = ui->comboBox_TypeServiceModif->currentText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un fournisseur !");
        return;
    }

    Fournisseur f;
    if (!f.idExisteDeja(id)) {
        QMessageBox::critical(this, "Erreur", "ID introuvable !");
        return;
    }

    // Applique les modifications
    Fournisseur fm(id, nom, tel, svc);
    if (!fm.modifierFournisseur()) {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
        return;
    }
    QMessageBox::information(this, "Succès", "Fournisseur modifié !");
    afficherFournisseurs();
    chargerListeIDs();
}

void MainWindowF::chargerListeIDs()
{
    ui->comboBox_IdModif->clear();
    QSqlQuery q("SELECT ID_FOURNISSEUR FROM FOURNISSEUR");
    while (q.next())
        ui->comboBox_IdModif->addItem(q.value(0).toString());
}

void MainWindowF::on_btnSupprimer_clicked()
{
    QString id = ui->lineEdit_SuppID->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Entrez un ID à supprimer !");
        return;
    }
    Fournisseur f;
    if (!f.supprimerFournisseur(id)) {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
        return;
    }
    QMessageBox::information(this, "Succès", "Fournisseur supprimé !");
    afficherFournisseurs();
    chargerListeIDs();
}

void MainWindowF::afficherFournisseurs()
{
    auto *model = new QSqlQueryModel(this);
    model->setQuery(R"(
        SELECT
          F.ID_FOURNISSEUR,
          F.NOM,
          F.NUM_TEL,
          F.TYPE_SERVICE,
          NVL(S.QUANTITE_TOTALE, 0) AS QUANTITE_TOTALE
        FROM FOURNISSEUR F
        LEFT JOIN (
            SELECT ID_FOURNISSEUR,
                   SUM(QUANTITE) AS QUANTITE_TOTALE
              FROM FOURNIR
             GROUP BY ID_FOURNISSEUR
        ) S
          ON F.ID_FOURNISSEUR = S.ID_FOURNISSEUR
        ORDER BY F.ID_FOURNISSEUR
    )");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL:" << model->lastError().text();
    }

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Téléphone");
    model->setHeaderData(3, Qt::Horizontal, "Service");
    model->setHeaderData(4, Qt::Horizontal, "Quantité totale");
    ui->tableView_Fournisseurs->setModel(model);
}

void MainWindowF::trierParCommande()
{
    bool asc = (ui->comboBox_Tri->currentText() == "tri croissant");
    auto *model = new QSqlQueryModel(this);
    model->setQuery(QString(R"(
        SELECT
          F.ID_FOURNISSEUR,
          F.NOM,
          NVL(S.QUANTITE_TOTALE, 0) AS QUANTITE_TOTALE
        FROM FOURNISSEUR F
        LEFT JOIN (
            SELECT
              ID_FOURNISSEUR,
              SUM(QUANTITE) AS QUANTITE_TOTALE
            FROM FOURNIR
            GROUP BY ID_FOURNISSEUR
        ) S
          ON F.ID_FOURNISSEUR = S.ID_FOURNISSEUR
        ORDER BY NVL(S.QUANTITE_TOTALE, 0) %1
    )").arg(asc ? "ASC" : "DESC"));

    // (Optionnel) Renommer les en‑têtes
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Quantité");

    ui->tableView_Fournisseurs->setModel(model);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL dans trierParCommande() :" << model->lastError().text();
    }
}

void MainWindowF::onRechercherClicked()
{
    // Récupérer le texte de recherche (supposons que vous avez un QLineEdit nommé lineEdit_Recherche)
    QString nom = ui->btnRechercher->text().trimmed();

    auto *model = new QSqlQueryModel(this);
    QSqlQuery q;

    // Sous‑requête S qui agrège les quantités de FOURNIR
    q.prepare(R"(
        SELECT
          F.ID_FOURNISSEUR,
          F.NOM,
          NVL(S.QUANTITE_TOTALE, 0) AS QUANTITE_TOTALE
        FROM FOURNISSEUR F
        LEFT JOIN (
            SELECT
              ID_FOURNISSEUR,
              SUM(QUANTITE) AS QUANTITE_TOTALE
            FROM FOURNIR
            GROUP BY ID_FOURNISSEUR
        ) S
          ON F.ID_FOURNISSEUR = S.ID_FOURNISSEUR
        WHERE F.NOM LIKE :nom
        ORDER BY F.NOM
    )");
    q.bindValue(":nom", "%" + nom + "%");

    if (!q.exec()) {
        qDebug() << "Recherche SQL erreur:" << q.lastError().text();
        return;
    }

    model->setQuery(std::move(q));

    // Mettre à jour les en‑têtes
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Quantité");

    ui->tableView_Fournisseurs->setModel(model);
}

void MainWindowF::exporterEnPDF()
{
    // 1) Choix du fichier de sortie
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        "",
        "Fichier PDF (*.pdf)"
        );
    if (fileName.isEmpty())
        return;

    // 2) Récupérer les données avec agrégation depuis FOURNIR
    QSqlQuery query;
    const QString sql = R"(
        SELECT
          F.ID_FOURNISSEUR,
          F.NOM,
          F.NUM_TEL,
          F.TYPE_SERVICE,
          NVL(S.QUANTITE_TOTALE, 0) AS QUANTITE_TOTALE
        FROM FOURNISSEUR F
        LEFT JOIN (
            SELECT
              ID_FOURNISSEUR,
              SUM(QUANTITE) AS QUANTITE_TOTALE
            FROM FOURNIR
            GROUP BY ID_FOURNISSEUR
        ) S
          ON F.ID_FOURNISSEUR = S.ID_FOURNISSEUR
        ORDER BY F.ID_FOURNISSEUR
    )";
    if (!query.exec(sql)) {
        QMessageBox::critical(
            this,
            "Erreur SQL",
            "Impossible de récupérer la liste :\n" + query.lastError().text()
            );
        return;
    }

    // 3) Préparer le document et charger le logo
    QTextDocument document;
    QImage logo("C:/Users/ASUS/Desktop/Projet_QT/FOURNISSEURS/mm.png");
    if (!logo.isNull()) {
        document.addResource(
            QTextDocument::ImageResource,
            QUrl("logo"),
            QVariant(logo)
            );
    } else {
        qWarning() << "Logo introuvable : vérifiez le chemin !";
    }

    // 4) Construire le HTML
    QString today = QDate::currentDate().toString("dd/MM/yyyy");
    QString html = R"(
    <html><head><style>
      body { font-family: Arial; font-size:12px; }
      h1 { text-align:center; color:#2c3e50; }
      p.date { text-align:right; font-size:10px; }
      table { width:100%; border-collapse:collapse; margin-top:20px;}
      th, td { border:1px solid #888; padding:8px; text-align:center; }
      th { background:#3498db; color:#fff; }
    </style></head><body>
    )";
    html += "<img src=\"logo\" width=\"80\" style=\"float:left;margin:10px;\" />";
    html += "<h1>Liste des Fournisseurs</h1>";
    html += QString("<p class=\"date\">Date d'export : %1</p>").arg(today);
    html += R"(<table>
        <tr>
          <th>ID</th><th>Nom</th><th>Téléphone</th>
          <th>Service</th><th>Quantité</th>
        </tr>)";

    while (query.next()) {
        html += QString("<tr>"
                        "<td>%1</td>"
                        "<td>%2</td>"
                        "<td>%3</td>"
                        "<td>%4</td>"
                        "<td>%5</td>"
                        "</tr>")
                    .arg(query.value(0).toString())
                    .arg(query.value(1).toString())
                    .arg(query.value(2).toString())
                    .arg(query.value(3).toString())
                    .arg(query.value(4).toString());
    }
    html += "</table></body></html>";

    // 5) Générer le PDF
    document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    document.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
void MainWindowF::envoyerSMS()
{
    int row = ui->tableView_Fournisseurs->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un fournisseur !");
        return;
    }
    auto *m = ui->tableView_Fournisseurs->model();
    QString id  = m->data(m->index(row, 0)).toString();
    QString qte = m->data(m->index(row, 4)).toString();
    QString msg = QString("ID:%1  Qté:%2").arg(id, qte);

    // appel asynchrone, le résultat tombera dans nos lambdas
    m_sms->envoyerSMS("+21694321511", msg);
}



void MainWindowF::afficherHistoriqueCommandes(const QString &fournisseurId)
{
    // 1) On crée le modèle
    auto *histModel = new QSqlQueryModel(this);
    QSqlQuery query;

    // 2) On prépare la requête sur FOURNIR (avec vos nouveaux champs)
    query.prepare(R"(
        SELECT
          R.REF              AS Réf,
          R.QUANTITE         AS Quantité,

        FROM FOURNIR R
        WHERE R.ID_FOURNISSEUR = :id
        ORDER BY R.REF DESC
    )");
    query.bindValue(":id", fournisseurId);

    // 3) Exécution et gestion d’erreur
    if (!query.exec()) {
        QMessageBox::critical(
            this,
            "Erreur",
            "Impossible de charger l'historique des fournitures :\n" + query.lastError().text()
            );
        return;
    }

    // 4) On affecte au modèle et on renomme les en‑têtes
    histModel->setQuery(std::move(query));
    histModel->setHeaderData(0, Qt::Horizontal, "Réf");
    histModel->setHeaderData(1, Qt::Horizontal, "Quantité");


    // 5) On branche sur la vue
}


void MainWindowF::afficherStatistiques()
{
    // 1) Requête : nombre de fournisseurs par type
    QSqlQuery query;
    if (!query.exec(
            "SELECT TYPE_SERVICE, COUNT(*) AS NB_FOURNISSEURS "
            "FROM FOURNISSEUR "
            "GROUP BY TYPE_SERVICE"
            )) {
        QMessageBox::critical(
            this,
            "Erreur SQL",
            "Impossible de charger les statistiques :\n" + query.lastError().text()
            );
        return;
    }

    // 2) Construction de la série camembert
    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        QString type = query.value("TYPE_SERVICE").toString();
        int     cnt  = query.value("NB_FOURNISSEURS").toInt();
        QPieSlice *slice = series->append(type, cnt);
        slice->setLabelVisible(true);
    }

    // 3) Création et configuration du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par type de service");

    // 4) Affichage dans un QChartView au sein d'un dialogue
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog dialog(this);
    dialog.setWindowTitle("Statistiques par type");
    QVBoxLayout lay(&dialog);
    lay.addWidget(chartView);
    dialog.resize(600, 400);
    dialog.exec();
}
