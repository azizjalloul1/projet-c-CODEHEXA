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
