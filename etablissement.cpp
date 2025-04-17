#include "etablissement.h"
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>

// Constructeur
Etablissement::Etablissement(const QString& id_E, const QString& nom, const QString& adresse,
                             const QString& contact, const QString& type_etablissement)
{
    this->id_E = id_E;
    this->nom = nom;
    this->adresse = adresse;
    this->contact = contact;
    this->type_etablissement = type_etablissement;
}

// Getters
QString Etablissement::getID_E() const { return id_E; }
QString Etablissement::getNOM() const { return nom; }
QString Etablissement::getADRESSE() const { return adresse; }
QString Etablissement::getCONTACT() const { return contact; }
QString Etablissement::getTYPE_ETABLISSEMENT() const { return type_etablissement; }

// Setters
void Etablissement::setID_E(const QString& id_E) { this->id_E = id_E; }
void Etablissement::setNOM(const QString& nom) { this->nom = nom; }
void Etablissement::setADRESSE(const QString& adresse) { this->adresse = adresse; }
void Etablissement::setCONTACT(const QString& contact) { this->contact = contact; }
void Etablissement::setTYPE_ETABLISSEMENT(const QString& type_etablissement) { this->type_etablissement = type_etablissement; }

bool Etablissement::champsValides() const {
    return !(id_E.isEmpty() || nom.isEmpty() || adresse.isEmpty() || contact.isEmpty() || type_etablissement.isEmpty());
}

QList<Etablissement> Etablissement::afficherEtablissement() {
    QList<Etablissement> liste;
    QSqlQuery query;
    if (!query.exec("SELECT ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT FROM ETABLISSEMENT")) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return liste;
    }

    while (query.next()) {
        QString id_E = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString adresse = query.value(2).toString();
        QString contact = query.value(3).toString();
        QString type_etablissement = query.value(4).toString();

        qDebug() << "ID_E:" << id_E
                 << "Nom:" << nom
                 << "Adresse:" << adresse
                 << "Contact:" << contact
                 << "Type:" << type_etablissement;

        Etablissement e(id_E, nom, adresse, contact, type_etablissement);
        liste.append(e);
    }

    return liste;
}

// --- C'était ça le problème : le '}' manquait ici ! ---

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
    query.prepare("INSERT INTO ETABLISSEMENT (ID_E, NOM, ADRESSE, CONTACT, TYPE_ETABLISSEMENT) "
                  "VALUES (:id_E, :nom, :adresse, :contact, :type_etablissement)");
    query.bindValue(":id_E", id_E);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":contact", contact);
    query.bindValue(":type_etablissement", type_etablissement);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Etablissement::modifierEtablissement(const QString& id_E, const QString& nom, const QString& adresse,
                                          const QString& contact, const QString& type_etablissement) {
    QSqlQuery query;
    query.prepare("UPDATE ETABLISSEMENT SET NOM = :nom, ADRESSE = :adresse, CONTACT = :contact, "
                  "TYPE_ETABLISSEMENT = :type_etablissement WHERE ID_E = :id_E");
    query.bindValue(":id_E", id_E); // Ne pas convertir en int si c’est une QString
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":contact", contact);
    query.bindValue(":type_etablissement", type_etablissement);

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

