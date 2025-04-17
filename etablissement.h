#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QVariant>
#include <QDebug>

class Etablissement
{
public:
    Etablissement() = default;

    Etablissement(const QString& id_E, const QString& nom, const QString& adresse,
                  const QString& contact, const QString& type_etablissement);

    // Getters
    QString getID_E() const;
    QString getNOM() const;
    QString getADRESSE() const;
    QString getCONTACT() const;
    QString getTYPE_ETABLISSEMENT() const;

    // Setters
    void setID_E(const QString& id_E);
    void setNOM(const QString& nom);
    void setADRESSE(const QString& adresse);
    void setCONTACT(const QString& contact);
    void setTYPE_ETABLISSEMENT(const QString& type_etablissement);

    // CRUD
    bool ajouterEtablissement();
    bool supprimerEtablissement(const QString& id_E);
    static QList<Etablissement> afficherEtablissement();
    static bool idExisteDeja(const QString& id_E);
    bool modifierEtablissement(const QString& id_E, const QString& nom, const QString& adresse,
                               const QString& contact, const QString& type_etablissement);

    // Validation
    bool champsValides() const;


private:
    QString id_E;
    QString nom;
    QString adresse;
    QString contact;
    QString type_etablissement;
};

#endif // ETABLISSEMENT_H
