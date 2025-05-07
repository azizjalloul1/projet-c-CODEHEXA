#include "accueil.h"
#include "ui_accueil.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accueil)
{
    ui->setupUi(this);

    QPixmap pixmap("C:/Users/Nadim/Desktop/PROJET_QT/GESTION/logo.png");
    if (!pixmap.isNull()) {
        ui->imageLabel->setPixmap(pixmap.scaled(150, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Erreur : Impossible de charger l'image !";
    }


    mainWindow = new MainWindow(this);
    mainWindow->setAccueil(this);

    mainWindowv = new MainWindowv(this);
    mainWindow->setAccueil(this);

    mainWindowstock = new MainWindowstock(this);
    mainWindowstock->setAccueil(this);

    windowexam = new WindowExamen(this);
    windowexam->setAccueil(this);

    mainWindowF = new MainWindowF(this);
    mainWindowF->setAccueil(this);

    connect(ui->employee, &QPushButton::clicked, this, [=]() {
        this->hide();
        mainWindow->show();
    });

    connect(ui->vehicule, &QPushButton::clicked, this, [=]() {
        this->hide();
        mainWindowv->show();
    });

    connect(ui->stock, &QPushButton::clicked, this, [=]() {
        this->hide();
        mainWindowstock->show();
    });

    connect(ui->examen, &QPushButton::clicked, this, [=]() {
        this->hide();
        windowexam->show();
    });

    connect(ui->fournisseur, &QPushButton::clicked, this, [=]() {
        this->hide();
        mainWindowF->show();
    });

}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::setUtilisateur(const QString &id, const QString &role)
{
    userId = id;
    userRole = role;

    QSqlQuery query;
    query.prepare("SELECT NOM FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", userId);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();

        qDebug() << "Utilisateur connecté :" << nom << "avec rôle :" << userRole;

        ui->labelBienvenue->setText("Bienvenue " + nom + " ");
    } else {
        qDebug() << "Erreur lors de la récupération du nom :" << query.lastError().text();
        ui->labelBienvenue->setText("Bienvenue (" + userRole + ")");
    }

    if (userRole == "Responsable") {
        ui->employee->hide();
        ui->vehicule->hide();
        ui->etablissement->hide();
    }
    if (userRole == "Transporteur") {
        ui->employee->hide();
        ui->stock->hide();
        ui->fournisseur->hide();
    }
}
