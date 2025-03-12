#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QCryptographicHash>


LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget), mdpRestWindow(nullptr)
{
    ui->setupUi(this);

    QPixmap pixmap("C:/Users/Nadim/Desktop/PROJET_QT/GESTION/logo.png");
    if (!pixmap.isNull()) {
        ui->imageLabel->setPixmap(pixmap.scaled(150, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Erreur : Impossible de charger l'image !";
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
    connect(ui->mdpOublieButton, &QPushButton::clicked, this, &LoginWidget::onMDPOublieClicked);
}

LoginWidget::~LoginWidget()
{
    delete ui;
    if (mdpRestWindow) {
        delete mdpRestWindow;
    }
}

QString LoginWidget::transformerMotDePasse(const QString &mdp, const QString &salt) {
    // Étape 1 : Diviser en deux et inverser
    int mid = mdp.length() / 2;
    QString part1 = mdp.left(mid);
    QString part2 = mdp.mid(mid);
    QString inverse = part2 + part1;

    // Étape 2 : Remplacer les caractères successifs identiques par "#"
    QString result;
    for (int i = 0; i < inverse.length(); ++i) {
        if (i > 0 && inverse[i] == inverse[i - 1]) {
            result += "#";
        } else {
            result += inverse[i];
        }
    }

    // Étape 3 : Ajouter le sel au début et à la fin
    QString motDePasseTransforme = salt + result + salt;

    // Étape 4 : Hacher avec SHA-256
    QByteArray hash = QCryptographicHash::hash(motDePasseTransforme.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

void LoginWidget::onLoginClicked()
{
    // Récupérer les valeurs des champs de texte
    QString id = ui->idLineEdit->text().trimmed();
    QString password = ui->motdpLineEdit->text().trimmed();

    // Vérifier si les champs sont vides
    if (id.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Récupérer le mot de passe haché et le sel de la base
    QSqlQuery query;
    query.prepare("SELECT MOT_DE_PASSE, SALT FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Vérifier si l'ID existe
    if (!query.next()) {
        QMessageBox::critical(this, "Erreur", "ID incorrect !");
        return;
    }

    // Récupérer le mot de passe stocké et le sel
    QString storedHashedPassword = query.value("MOT_DE_PASSE").toString();
    QString storedSalt = query.value("SALT").toString();

    // Transformer et hacher le mot de passe saisi avec le sel
    QString hashedInputPassword = transformerMotDePasse(password, storedSalt);

    // Comparer les deux hachages
    if (storedHashedPassword == hashedInputPassword) {
        qDebug() << "Connexion réussie pour l'ID :" << id;
        emit loginSuccessful(id); // Émettre le signal de connexion réussie
    } else {
        QMessageBox::critical(this, "Erreur", "Mot de passe incorrect !");
    }
}

void LoginWidget::onMDPOublieClicked()
{
    mdpRestWindow = new MDPRestWindow(mainWindow, this);
    mdpRestWindow->show();
}
