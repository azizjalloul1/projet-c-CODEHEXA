#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QGeoCoordinate>
#include <QMetaType>
#include <QQmlApplicationEngine>
#include <QtPositioning>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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
}
