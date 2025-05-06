#include "vehicules.h"
#include <QSqlError>
#include <QDebug>

// Constructor
Vehicule::Vehicule(QString matricule, QString marque, QString type, QString statut, double volume_coffre, int Id_transporteur)
    : matricule(matricule), marque(marque), type(type), statut(statut), volume_coffre(volume_coffre), Id_transporteur(Id_transporteur) {}

// Getters
QString Vehicule::getMatricule() const { return matricule; }
QString Vehicule::getMarque() const { return marque; }
QString Vehicule::getType() const { return type; }
QString Vehicule::getStatut() const { return statut; }
double Vehicule::getVolumeCoffre() const { return volume_coffre; }
int Vehicule::getIdtransporteur() const { return Id_transporteur; }
// Setters
void Vehicule::setMatricule(const QString& matricule) { this->matricule = matricule; }
void Vehicule::setMarque(const QString& marque) { this->marque = marque; }
void Vehicule::setType(const QString& type) { this->type = type; }
void Vehicule::setStatut(const QString& statut) { this->statut = statut; }
void Vehicule::setVolumeCoffre(double volume_coffre) { this->volume_coffre = volume_coffre; }
void Vehicule::setIdtransporteur(int Id_transporteur) { this->Id_transporteur = Id_transporteur; }
// Create (Add a new vehicle)
bool Vehicule::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Vehicule (matricule, marque, type, statut, volume_coffre, Id_transporteur) "
                  "VALUES (:matricule, :marque, :type, :statut, :volume_coffre, :Id_transporteur)");

    query.bindValue(":matricule", matricule);
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":volume_coffre", volume_coffre);
    query.bindValue(":Id_transporteur", Id_transporteur);  // ✅ Now it's part of the SQL

    if (!query.exec()) {
        qDebug() << "Error adding vehicle: " << query.lastError().text();
        return false;
    }
    return true;
}


// Read (Display all vehicles)
QSqlQueryModel* Vehicule::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Vehicule");
    return model;
}

// Update (Modify vehicle details)
bool Vehicule::modifier(QString matricule) {
    QSqlQuery query;
    query.prepare("UPDATE Vehicule SET marque=:marque, type=:type, statut=:statut, volume_coffre=:volume_coffre, Id_transporteur=:Id_transporteur "
                  "WHERE matricule=:matricule");

    query.bindValue(":matricule", matricule);
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":volume_coffre", volume_coffre);
    query.bindValue(":Id_transporteur", Id_transporteur);  // ✅ Now it's included

    if (!query.exec()) {
        qDebug() << "Error updating vehicle: " << query.lastError().text();
        return false;
    }
    return true;
}


// Delete (Remove a vehicle)
bool Vehicule::supprimer(QString matricule) {
    QSqlQuery query;
    query.prepare("DELETE FROM Vehicule WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);

    if (!query.exec()) {
        qDebug() << "Error deleting vehicle: " << query.lastError().text();
        return false;
    }
    return true;
}
