#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

class Connexion
{
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
    QString getLastError() const;

private:
    QSqlDatabase db;
};

#endif
