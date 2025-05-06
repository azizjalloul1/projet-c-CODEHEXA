#include "etablissement.h"
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>


Etablissement::Etablissement(const QString& id_E, const QString& nom, const QString& adresse,
                             const QString& contact, const QString& type_etablissement,
                             const QString& latitude, const QString& longitude)
{
    this->id_E = id_E;
    this->nom = nom;
    this->adresse = adresse;
    this->contact = contact;
    this->type_etablissement = type_etablissement;
    this->latitude = latitude;
    this->longitude = longitude;
}



QString Etablissement::getID_E() const { return id_E; }
QString Etablissement::getNOM() const { return nom; }
QString Etablissement::getADRESSE() const { return adresse; }
QString Etablissement::getCONTACT() const { return contact; }
QString Etablissement::getTYPE_ETABLISSEMENT() const { return type_etablissement; }
QString Etablissement::getLatitude() const { return latitude; }
QString Etablissement::getLongitude() const { return longitude; }


void Etablissement::setID_E(const QString& id_E) { this->id_E = id_E; }
void Etablissement::setNOM(const QString& nom) { this->nom = nom; }
void Etablissement::setADRESSE(const QString& adresse) { this->adresse = adresse; }
void Etablissement::setCONTACT(const QString& contact) { this->contact = contact; }
void Etablissement::setTYPE_ETABLISSEMENT(const QString& type_etablissement) { this->type_etablissement = type_etablissement; }
void Etablissement::setLatitude(const QString& latitude) { this->latitude = latitude;}
void Etablissement::setLongitude(const QString& longitude){ this->longitude = longitude;}

bool Etablissement::champsValides() const {
    return !(id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty() || latitude.isEmpty() || longitude.isEmpty());
}
QList<Etablissement> Etablissement::afficherEtablissement() {
    QList<Etablissement> liste;
    QSqlQuery query;
    if (!query.exec("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE FROM ETABLISSEMENT")) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return liste;
    }

    while (query.next()) {
        QString id_E = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString adresse = query.value(2).toString();
        QString contact = query.value(3).toString();
        QString type = query.value(4).toString();
        QString latitude = query.value(5).toString();
        QString longitude = query.value(6).toString();

        Etablissement e(id_E, nom, adresse, contact, type, latitude, longitude);
        liste.append(e);
    }

    return liste;
}



bool Etablissement::ajouterEtablissement() {
    if (!champsValides()) {
        qDebug() << "Erreur : Tous les champs doivent être remplis.";
        return false;
    }

    if (idExisteDeja(id_E)) {
        qDebug() << "Erreur : L'ID" << id_E << "existe déjà.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ETABLISSEMENT (ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT, LATITUDE, LONGITUDE) "
                  "VALUES (:id_E, :nom, :adresse, :contact, :type_etablissement, :latitude, :longitude)");
    query.bindValue(":id_E", id_E);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":contact", contact);
    query.bindValue(":type_etablissement", type_etablissement);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Etablissement::modifierEtablissement(const QString& id_E, const QString& nom, const QString& adresse,
                                          const QString& contact, const QString& type_etablissement, const QString& latitude, const QString& longitude) {
    QSqlQuery query;
    query.prepare("UPDATE ETABLISSEMENT SET NOM = :nom, ADRESSE = :adresse, CONTACT = :contact, "
                  "TYPE_ETABLISSEMENT = :type_etablissement,LATITUDE = :latitude ,LONGITUDE = :longitude WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E); // Ne pas convertir en int si c’est une QString
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":contact", contact);
    query.bindValue(":type_etablissement", type_etablissement);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Etablissement::supprimerEtablissement(const QString& id_E) {
    if (id_E.isEmpty()) {
        qDebug() << "Erreur: L'ID de l'établissement doit être renseigné pour supprimer.";
        return false;
    }

    if (!idExisteDeja(id_E)) {
        qDebug() << "Erreur: L'établissement avec ID" << id_E << "n'existe pas.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM ETABLISSEMENT WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Etablissement::idExisteDeja(const QString& id_E) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM ETABLISSEMENT WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    qDebug() << "Erreur lors de la vérification de l'ID :" << query.lastError().text();
    return false;
}

