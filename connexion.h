#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class Connexion {
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

    QSqlDatabase getDatabase() const; // Ajout du getter pour db

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
