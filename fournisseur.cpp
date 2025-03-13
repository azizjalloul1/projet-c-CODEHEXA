#include "fournisseur.h"
#include <QSqlQuery>
#include <QVariant> // Manipuler les valeurs SQL
#include <QDebug>
#include <QSqlError>

// Constructeur
Fournisseur::Fournisseur(const QString& id_fournisseur, const QString& nom, const QString& num_tel, const QString& type_service)
    : id_fournisseur(id_fournisseur), nom(nom), num_tel(num_tel), type_service(type_service) {}

// Getters
QString Fournisseur::getIdFournisseur() const { return id_fournisseur; }
QString Fournisseur::getNom() const { return nom; }
QString Fournisseur::getNumTel() const { return num_tel; }
QString Fournisseur::getTypeService() const { return type_service; }

// Setters
void Fournisseur::setIdFournisseur(const QString& id_fournisseur) { this->id_fournisseur = id_fournisseur; }
void Fournisseur::setNom(const QString& nom) { this->nom = nom; }
void Fournisseur::setNumTel(const QString& num_tel) { this->num_tel = num_tel; }
void Fournisseur::setTypeService(const QString& type_service) { this->type_service = type_service; }

// Ajouter un fournisseur


bool Fournisseur::ajouterFournisseur() {
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, NUM_TEL, TYPE_SERVICE) "
                  "VALUES (:id, :nom, :num_tel, :type_service)");

    query.bindValue(":id", this->id_fournisseur);
    query.bindValue(":nom", this->nom);
    query.bindValue(":num_tel", this->num_tel);
    query.bindValue(":type_service", this->type_service);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout :" << query.lastError().text();
        return false;
    }

    return true;
}


// Supprimer un fournisseur
bool Fournisseur::supprimerFournisseur(const QString& id_fournisseur) {
    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id_fournisseur");
    query.bindValue(":id_fournisseur", id_fournisseur);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucun fournisseur supprimé, l'ID n'existe pas.";
        return false;
    }

    return true;
}

// Modifier un fournisseur
bool Fournisseur::modifierFournisseur() {
    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEUR SET NOM = :nom, NUM_TEL = :num_tel, TYPE_SERVICE = :type_service WHERE ID_FOURNISSEUR = :id_fournisseur");

    query.bindValue(":id_fournisseur", id_fournisseur.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":type_service", type_service);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }

    return true;
}

// Vérifier si un ID existe déjà
bool Fournisseur::idExisteDeja(const QString& id_fournisseur) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id_fournisseur");
    query.bindValue(":id_fournisseur", id_fournisseur);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

// Afficher la liste des fournisseurs
QList<Fournisseur> Fournisseur::afficherFournisseurs() {
    QList<Fournisseur> fournisseurs;
    QSqlQuery query;

    // 🔥TEST : Vérifie si la requête s'exécute correctement
    if (!query.exec("SELECT ID_FOURNISSEUR, NOM, NUM_TEL, TYPE_SERVICE FROM FOURNISSEUR")) {
        qDebug() << " Erreur SQL :" << query.lastError().text();
        return fournisseurs; // Retourne une liste vide en cas d'erreur
    }

    // TEST : Affiche chaque ligne trouvée dans la console
    int rowCount = 0;
    while (query.next()) {
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString num_tel = query.value(2).toString();
        QString type_service = query.value(3).toString();

        qDebug() << " ID:" << id
                 << "Nom:" << nom
                 << "Téléphone:" << num_tel
                 << "Service:" << type_service;

        Fournisseur f(id, nom, num_tel, type_service);
        fournisseurs.append(f);
        rowCount++;
    }

    //  TEST : Vérifie si au moins une ligne est trouvée
    if (rowCount == 0) {
        qDebug() << "Aucun fournisseur trouvé dans la base de données !";
    } else {
        qDebug() << "Nombre de fournisseurs trouvés :" << rowCount;
    }

    return fournisseurs;
}
