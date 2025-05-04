#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QMap>
#include <QPixmap>

class Etablissement
{
public:
    Etablissement() = default;


    Etablissement(const QString& id_E, const QString& nom, const QString& adresse,
                  const QString& contact, const QString& type_etablissement,
                  const QString& latitude, const QString& longitude);

    // Getters
    QString getID_E() const;
    QString getNOM() const;
    QString getADRESSE() const;
    QString getCONTACT() const;
    QString getTYPE_ETABLISSEMENT() const;
    QString getLatitude() const;
    QString getLongitude() const;

    // Setters
    void setID_E(const QString& id_E);
    void setNOM(const QString& nom);
    void setADRESSE(const QString& adresse);
    void setCONTACT(const QString& contact);
    void setTYPE_ETABLISSEMENT(const QString& type_etablissement);
    void setLatitude(const QString& latitude);
    void setLongitude(const QString& longitude);
    // CRUD
    bool ajouterEtablissement();
    bool supprimerEtablissement(const QString& id_E);
    static QList<Etablissement> afficherEtablissement();
    static bool idExisteDeja(const QString& id_E);
    bool modifierEtablissement(const QString& id_E, const QString& nom, const QString& adresse,
                               const QString& contact, const QString& type_etablissement,
                               const QString& latitude, const QString& longitude);


    // Validation
    bool champsValides() const;


private:
    QString id_E;
    QString nom;
    QString adresse;
    QString contact;
    QString type_etablissement;
    QString latitude;
    QString longitude;
};

#endif // ETABLISSEMENT_H
