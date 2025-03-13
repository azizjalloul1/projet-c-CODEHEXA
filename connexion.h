#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class Connexion {
public:
    Connexion(); // Constructeur
    bool ouvrirConnexion();
    void fermerConnexion();

    QSqlDatabase getDatabase() const;

private:
    QSqlDatabase db;  // Objet
};

#endif // CONNEXION_H
