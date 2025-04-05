#include "connexion.h"

Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QODBC"); //database system->(sql server,mysql,..)
}

bool Connexion::ouvrirConnexion()
{

    db.setDatabaseName("PROJET_QT.bd");//nom de la base
    db.setUserName("imen");//utilisateur
    db.setPassword("imen");//mot de passe

    if (!db.open()) {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
        return false;
    } else {
        qDebug() << "Connexion réussie !";
        return true;
    }
}

void Connexion::fermerConnexion()
{
    db.close();
    qDebug() << "Connexion fermée.";
}

QString Connexion::getLastError() const
{
    return db.lastError().text();
}
