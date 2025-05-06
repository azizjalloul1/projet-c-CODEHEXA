<<<<<<< HEAD
<<<<<<< HEAD
#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

class Connexion
{
public:
    Connexion(); // Constructeur
    bool ouvrirConnexion();
    void fermerConnexion();

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
=======
=======
>>>>>>> origin/gestionetablissement
#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
<<<<<<< HEAD
>>>>>>> origin/gestion-de-véhicules
=======
>>>>>>> origin/gestionetablissement
