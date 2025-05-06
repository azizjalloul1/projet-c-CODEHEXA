<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> origin/gestion-de-fournisseur
#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
<<<<<<< HEAD
#include <QMessageBox>
#include <QDebug>

class Connexion
{
=======
#include <QSqlQuery>
#include <QDebug>

class Connexion {
>>>>>>> origin/gestion-de-fournisseur
public:
    Connexion(); // Constructeur
    bool ouvrirConnexion();
    void fermerConnexion();

<<<<<<< HEAD
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
=======
    QSqlDatabase getDatabase() const;

private:
    QSqlDatabase db;  // Objet
};

#endif // CONNEXION_H
>>>>>>> origin/gestion-de-fournisseur
