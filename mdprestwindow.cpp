#include "mdprestwindow.h"
#include "qsqlerror.h"
#include "ui_MDP_rest.h"



MDPRestWindow::MDPRestWindow(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MDPRestWindow),
    mainWindow(mainWindow)
{
    ui->setupUi(this);

    // Connecter les boutons aux slots
    connect(ui->envoyerButton, &QPushButton::clicked, this, &MDPRestWindow::onEnvoyerButtonClicked);
    connect(ui->validerButton, &QPushButton::clicked, this, &MDPRestWindow::onValiderButtonClicked);
    connect(ui->changerButton, &QPushButton::clicked, this, &MDPRestWindow::onChangerButtonClicked);
}

MDPRestWindow::~MDPRestWindow()
{
    delete ui;
}

// Récupérer l'e-mail associé à l'ID
QString MDPRestWindow::recupererEmailParID(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT EMAIL FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        QMessageBox::warning(this, "Erreur", "ID non trouvé !");
        return QString();
    }
}

// Générer un code de vérification
QString MDPRestWindow::genererCode()
{
    const QString lettres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const QString chiffres = "0123456789";
    QString code;

    // Générer 4 lettres aléatoires
    for (int i = 0; i < 4; ++i) {
        code += lettres[QRandomGenerator::global()->bounded(lettres.length())];
    }

    // Générer 4 chiffres aléatoires
    for (int i = 0; i < 4; ++i) {
        code += chiffres[QRandomGenerator::global()->bounded(chiffres.length())];
    }

    return code;
}

// Envoyer le code par e-mail via l'API Brevo
void MDPRestWindow::envoyerCodeParEmail(const QString &email, const QString &code)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://api.brevo.com/v3/smtp/email");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("api-key", "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"); // Remplacez par votre clé API

    QJsonObject json;
    json["sender"] = QJsonObject{{"name", "Si Nadim"}, {"email", "nadimkhchini1@gmail.com"}};
    json["to"] = QJsonArray{QJsonObject{{"email", email}}};
    json["subject"] = "Code de vérification";
    json["htmlContent"] = QString("Votre code de vérification est : <strong>%1</strong>").arg(code);

    QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(this, "Succès", "Code envoyé avec succès !");
            ui->codeInput->setEnabled(true);
            ui->validerButton->setEnabled(true);
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'envoi du code.");
        }
        reply->deleteLater();
    });
}

// Envoyer le code de vérification
void MDPRestWindow::onEnvoyerButtonClicked()
{
    idUtilisateur = ui->idInput->text();
    QString email = recupererEmailParID(idUtilisateur);

    if (email.isEmpty()) {
        return;
    }

    codeGenere = genererCode();
    envoyerCodeParEmail(email, codeGenere);
}

// Valider le code de vérification
void MDPRestWindow::onValiderButtonClicked()
{
    QString codeSaisi = ui->codeInput->text();
    if (codeSaisi == codeGenere) {
        QMessageBox::information(this, "Succès", "Code valide !");
        ui->nouveauMDPInput->setEnabled(true);
        ui->changerButton->setEnabled(true);
    } else {
        QMessageBox::warning(this, "Erreur", "Code invalide !");
    }
}

// Valider le nouveau mot de passe
bool MDPRestWindow::validerMotDePasse(const QString &mdp)
{
    const int lettreCount = mdp.count(QRegularExpression("[a-zA-Z]"));
    const int chiffreCount = mdp.count(QRegularExpression("\\d"));

    if (mdp.length() >= 6 && lettreCount >= 2 && chiffreCount >= 1) {
        return true;
    } else {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins 6 caractères, dont 2 lettres et 1 chiffre.");
        return false;
    }
}

// Changer le mot de passe
void MDPRestWindow::onChangerButtonClicked()
{
    QString nouveauMDP = ui->nouveauMDPInput->text();
    if (validerMotDePasse(nouveauMDP)) {
        QString hashedPassword, salt;
        mainWindow->crypterMotDePasse(nouveauMDP, hashedPassword, salt);

        QSqlQuery query;
        query.prepare("UPDATE EMPLOYEE SET MOT_DE_PASSE = :mdp, SALT = :salt WHERE ID = :id");
        query.bindValue(":mdp", hashedPassword);
        query.bindValue(":salt", salt);
        query.bindValue(":id", idUtilisateur);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Mot de passe mis à jour avec succès !");
            this->close();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur : " + query.lastError().text());
        }
    }
}


