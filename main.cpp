<<<<<<< HEAD
#include "connexion.h"
#include "loginwidget.h"
#include "accueil.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
}
