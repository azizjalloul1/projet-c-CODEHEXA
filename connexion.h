<<<<<<< HEAD
<<<<<<< HEAD
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
=======
#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
>>>>>>> origin/gestionexamen
#include <QMessageBox>
#include <QDebug>

class Connexion
{
<<<<<<< HEAD
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
=======
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
    QString getLastError() const;

>>>>>>> origin/gestionexamen
private:
    QSqlDatabase db;
};

<<<<<<< HEAD
#endif // CONNEXION_H
=======
=======
>>>>>>> origin/gestionetablissement
=======
>>>>>>> origin/gestion_stock
#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

<<<<<<< HEAD
class Connection
{
public:
    Connection();
=======
class Connexion
{
public:
    Connexion();
>>>>>>> origin/gestion_stock
    bool createconnect();
};

#endif // CONNECTION_H
<<<<<<< HEAD
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
=======
#endif
>>>>>>> origin/gestionexamen
=======
>>>>>>> origin/gestion_stock
