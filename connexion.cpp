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
Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connexion::ouvrirConnexion()
{
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
        return true;
    }
}

void Connexion::fermerConnexion()
{
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

    if (db.open())
        test=true;





    return  test;
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
