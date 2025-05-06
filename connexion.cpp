<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "connexion.h"

<<<<<<< HEAD
=======
#include "connexion.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

>>>>>>> origin/gestion-de-fournisseur
=======
#include "connexion.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QDebug>

>>>>>>> origin/gestionexamen
Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connexion::ouvrirConnexion()
{
<<<<<<< HEAD
<<<<<<< HEAD
    db.setDatabaseName("PROJET"); // Nom de la source de données ODBC
    db.setUserName("naadim");     // Nom d'utilisateur Oracle
    db.setPassword("0000");       // Mot de passe Oracle

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Erreur de Connexion",
                              "Impossible de se connecter à la base de données :\n" + db.lastError().text());
        QMessageBox::critical(nullptr, "Erreur de Connexion",
                              "Impossible de se connecter à la base de données :\n" + db.lastError().text());
        return false;
    } else {
        qDebug() << "Connexion réussie !";
=======
    db.setDatabaseName("PROJET");
    db.setUserName("louka");
    db.setPassword("louka");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données :" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Connexion réussie à la base de données fournisseur_db";
>>>>>>> origin/gestion-de-fournisseur
=======

    db.setDatabaseName("PROJET_QT.bd");//nom de la base
    db.setUserName("imen");//utilisateur
    db.setPassword("imen");//mot de passe

    if (!db.open()) {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
        return false;
    } else {
        qDebug() << "Connexion réussie !";
>>>>>>> origin/gestionexamen
        return true;
    }
}

void Connexion::fermerConnexion()
{
<<<<<<< HEAD
<<<<<<< HEAD
    db.close();
    qDebug() << "Connexion fermée.";
=======
=======

#include "connexion.h"

>>>>>>> origin/gestionetablissement
Connection::Connection()
{

}
<<<<<<< HEAD

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PROJET_QT");//inserer le nom de la source de données
    db.setUserName("youssef");//inserer nom de l'utilisateur
    db.setPassword("youssef");//inserer mot de passe de cet utilisateur
=======
#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PROJET");//inserer le nom de la source de données
    db.setUserName("aziz");//inserer nom de l'utilisateur
    db.setPassword("0000");//inserer mot de passe de cet utilisateur
>>>>>>> origin/gestion_stock

    if (db.open())
        test=true;





    return  test;
<<<<<<< HEAD
>>>>>>> origin/gestion-de-véhicules
=======
bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PROJET");
    db.setUserName("meriam");//inserer nom de l'utilisateur
    db.setPassword("123");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;

    return  test;
>>>>>>> origin/gestionetablissement
}
=======
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée avec succès.";
    }
}

// **Ajout de l'implémentation du getter pour db**
QSqlDatabase Connexion::getDatabase() const {
    return db;
}

>>>>>>> origin/gestion-de-fournisseur
=======
    db.close();
    qDebug() << "Connexion fermée.";
}

QString Connexion::getLastError() const
{
    return db.lastError().text();
}
>>>>>>> origin/gestionexamen
=======
}
>>>>>>> origin/gestion_stock
