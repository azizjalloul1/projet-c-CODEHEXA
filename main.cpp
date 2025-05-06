<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "connexion.h"
#include "loginwidget.h"
#include "accueil.h"
#include <QApplication>
#include <QMessageBox>
=======
=======
>>>>>>> origin/gestion-de-fournisseur
#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
<<<<<<< HEAD
#include <QGeoCoordinate>
#include <QMetaType>
#include <QQmlApplicationEngine>
#include <QtPositioning>
>>>>>>> origin/gestionetablissement

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD

    Connexion c;
    bool test = c.ouvrirConnexion();
    if (!test) {
        QMessageBox::critical(nullptr, "Connexion",
                              "Impossible de se connecter à la base de données.");
        return -1;
    }

    LoginWidget loginWidget;
    Accueil accueilWindow;

    QObject::connect(&loginWidget, &LoginWidget::loginSuccessful,
                     [&](const QString &id, const QString &role) {
                         loginWidget.close();
                         accueilWindow.setUtilisateur(id, role);
                         accueilWindow.show();
                     });

    loginWidget.show();

    return a.exec();
=======

#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "vehicules.h"
#include "mainwindow.h"  // Include MainWindow
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed."), QMessageBox::Ok);
        return -1;
    }

    // Create and show MainWindow
    MainWindow w;
    w.show();

    return a.exec();  // Start the event loop
>>>>>>> origin/gestion-de-véhicules
=======
    qRegisterMetaType<QGeoCoordinate>("QGeoCoordinate");
    Connection c;
    bool test = c.createconnect();

    MainWindow w;
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database ouverte"),
                                 QObject::tr("Connexion réussie.\nCliquez sur Annuler pour fermer."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database non ouverte"),
                              QObject::tr("Échec de connexion.\nCliquez sur Annuler pour fermer."), QMessageBox::Cancel);
        return 1;
    }

    return a.exec();
>>>>>>> origin/gestionetablissement
=======

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //  Connexion à la base de données
    Connexion c;
    bool test = c.ouvrirConnexion();

    if (test) {
        MainWindow w;  // Création de la fenêtre principale
        w.show();      //  Affichage de la fenêtre principale
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données !");
        return -1;
    }
>>>>>>> origin/gestion-de-fournisseur
}
