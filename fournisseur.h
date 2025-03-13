#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QList>
#include <QDebug>

class Fournisseur {
public:
    Fournisseur() = default; //constructeur vide
    Fournisseur(const QString& id_fournisseur, const QString& nom, const QString& num_tel, const QString& type_service);

//getters
    QString getIdFournisseur() const;
    QString getNom() const;
    QString getNumTel() const;
    QString getTypeService() const;

//setters
    void setIdFournisseur(const QString& id_fournisseur);
    void setNom(const QString& nom);
    void setNumTel(const QString& num_tel);
    void setTypeService(const QString& type_service);

//fct
    bool ajouterFournisseur();
    bool supprimerFournisseur(const QString& id_fournisseur);
    bool modifierFournisseur();
    static bool idExisteDeja(const QString& id_fournisseur);
    static QList<Fournisseur> afficherFournisseurs();

private:
    QString id_fournisseur, nom, num_tel, type_service;
};

#endif // FOURNISSEUR_H
