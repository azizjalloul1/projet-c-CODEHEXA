#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QList>
#include <QDebug>

class Stock {
public:
    Stock() = default;
    Stock(int ref, double prix_unitaire, const QString& type, int quantite);

    int getRef() const;
    double getPrixUnitaire() const;
    QString getType() const;
    int getQuantite() const;

    void setRef(int ref);
    void setPrixUnitaire(double prix_unitaire);
    void setType(const QString& type);
    void setQuantite(int quantite);

    bool ajouterStock();
    bool supprimerStock(int ref);
    bool modifierStock();
    static bool idExisteDeja(int ref);
    QList<Stock> afficherStocks();
    QList<Stock> afficherStocksTriesParQuantiteDesc(); // Sorting function
    QList<Stock> afficherStocksParRef(int ref); // Search function

private:
    int ref;
    double prix_unitaire;
    QString type;
    int quantite;
};

#endif // STOCK_H
