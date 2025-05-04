#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Vehicule {
private:
    QString matricule;
    QString marque;
    QString type;
    QString statut;
    double volume_coffre;
    int Id_transporteur;

public:
    // Constructors
    Vehicule() = default;
    Vehicule(QString matricule, QString marque, QString type, QString statut, double volume_coffre, int Id_transporteur);

    // Getters and Setters
    QString getMatricule() const;
    QString getMarque() const;
    QString getType() const;
    QString getStatut() const;
    double getVolumeCoffre() const;
    int getIdtransporteur() const;

    void setMatricule(const QString& matricule);
    void setMarque(const QString& marque);
    void setType(const QString& type);
    void setStatut(const QString& statut);
    void setVolumeCoffre(double volume_coffre);
    void setIdtransporteur(int Id_transporteur);

    // CRUD Operations
    bool ajouter();  // Create
    QSqlQueryModel* afficher();  // Read
    bool modifier(QString matricule);  // Update
    bool supprimer(QString matricule);  // Delete
};

#endif // VEHICULE_H
