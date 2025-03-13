#include "connexion.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connexion::ouvrirConnexion()
{
    db.setDatabaseName("PROJET");
    db.setUserName("louka");
    db.setPassword("louka");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données :" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Connexion réussie à la base de données fournisseur_db";
        return true;
    }
}

void Connexion::fermerConnexion()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée avec succès.";
    }
}

// **Ajout de l'implémentation du getter pour db**
QSqlDatabase Connexion::getDatabase() const {
    return db;
}

