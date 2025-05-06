#include "Stock.h"

// Constructor
Stock::Stock(int ref, double prix_unitaire, const QString& type, int quantite)
    : ref(ref), prix_unitaire(prix_unitaire), type(type), quantite(quantite) {}

// Getters
int Stock::getRef() const { return ref; }
double Stock::getPrixUnitaire() const { return prix_unitaire; }
QString Stock::getType() const { return type; }
int Stock::getQuantite() const { return quantite; }

// Setters
void Stock::setRef(int ref) { this->ref = ref; }
void Stock::setPrixUnitaire(double prix_unitaire) { this->prix_unitaire = prix_unitaire; }
void Stock::setType(const QString& type) { this->type = type; }
void Stock::setQuantite(int quantite) { this->quantite = quantite; }

// Add stock
bool Stock::ajouterStock() {
    QSqlQuery query;
    query.prepare("INSERT INTO STOCK (REF, PRIX_UNITAIRE, TYPE, QUANTITE) VALUES (:ref, :prix_unitaire, :type, :quantite)");
    query.bindValue(":ref", ref);
    query.bindValue(":prix_unitaire", prix_unitaire);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du stock:" << query.lastError().text();
        return false;
    }

    qDebug() << "Stock ajouté avec succès.";
    return true;
}

// Remove stock
bool Stock::supprimerStock(int ref) {
    QSqlQuery query;
    query.prepare("DELETE FROM STOCK WHERE REF = :ref");
    query.bindValue(":ref", ref);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du stock:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}

// Modify stock
bool Stock::modifierStock() {
    if (!idExisteDeja(ref)) {
        qDebug() << "REF introuvable pour modification.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE STOCK SET PRIX_UNITAIRE = :prix_unitaire, TYPE = :type, QUANTITE = :quantite WHERE REF = :ref");
    query.bindValue(":ref", ref);
    query.bindValue(":prix_unitaire", prix_unitaire);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du stock:" << query.lastError().text();
        return false;
    }

    return true;
}

// Check if REF exists
bool Stock::idExisteDeja(int ref) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM STOCK WHERE REF = :ref");
    query.bindValue(":ref", ref);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

// Display all stocks
QList<Stock> Stock::afficherStocks() {
    QList<Stock> stocks;
    QSqlQuery query("SELECT REF, PRIX_UNITAIRE, TYPE, QUANTITE FROM STOCK");

    while (query.next()) {
        int ref = query.value(0).toInt();
        double prix_unitaire = query.value(1).toDouble();
        QString type = query.value(2).toString();
        int quantite = query.value(3).toInt();

        stocks.append(Stock(ref, prix_unitaire, type, quantite));
    }

    return stocks;
}
// Display stocks sorted by quantity (descending order)
QList<Stock> Stock::afficherStocksTriesParQuantiteDesc() {
    QList<Stock> stocks;
    QSqlQuery query("SELECT REF, PRIX_UNITAIRE, TYPE, QUANTITE FROM STOCK ORDER BY QUANTITE DESC");

    while (query.next()) {
        stocks.append(Stock(query.value(0).toInt(), query.value(1).toDouble(), query.value(2).toString(), query.value(3).toInt()));
    }

    return stocks;
}
// Search for stock by REF dynamically
QList<Stock> Stock::afficherStocksParRef(int ref) {
    QList<Stock> stocks;
    QSqlQuery query;
    query.prepare("SELECT REF, PRIX_UNITAIRE, TYPE, QUANTITE FROM STOCK WHERE REF LIKE :ref");
    query.bindValue(":ref", QString::number(ref) + "%"); // Supports partial search

    if (query.exec()) {
        while (query.next()) {
            stocks.append(Stock(query.value(0).toInt(), query.value(1).toDouble(), query.value(2).toString(), query.value(3).toInt()));
        }
    }
    return stocks;
}
