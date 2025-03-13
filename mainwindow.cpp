#include "mainwindow.h"
#include "stock.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayStocks();
    connect(ui->suppb, &QPushButton::clicked, this, &MainWindow::onsupprimerclicked);
    connect(ui->addb, &QPushButton::clicked, this, &MainWindow::onajouterclicked);
    connect(ui->modb, &QPushButton::clicked, this, &MainWindow::onmodifierclicked);
    connect(ui->valider, &QPushButton::clicked, this, &MainWindow::onvaliderclicked);
    connect(ui->affiche, &QTabWidget::currentChanged, this, &MainWindow::displayStocks);

}

void MainWindow::onajouterclicked()
{
    int ref = ui->ref->text().toInt();
    double prix = ui->prix->text().toDouble();
    QString type = ui->type->text();
    int quantite = ui->quantite->text().toInt();

    Stock stock(ref, prix, type, quantite);

    if (stock.ajouterStock()) {
        QMessageBox::information(this, "Success", "Item added successfully.");
        displayStocks();  // Refresh the display
    } else {
        QMessageBox::critical(this, "Error", "Failed to add item.");
    }
}

void MainWindow::onsupprimerclicked()
{
    int ref = ui->suppref->text().toInt();

    Stock stock;
    if (stock.supprimerStock(ref)) {
        QMessageBox::information(this, "Success", "Item deleted successfully.");
        displayStocks();  // Refresh the display
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete item.");
    }
}

void MainWindow::onmodifierclicked()
{
    int ref = ui->refmod->text().toInt();
    double prix = ui->prixmod->text().toDouble();
    QString type = ui->typemod->text();
    int quantite = ui->quantitemod->text().toInt();

    Stock stock(ref, prix, type, quantite);

    if (stock.modifierStock()) {
        QMessageBox::information(this, "Success", "Item updated successfully.");
        displayStocks();  // Refresh the display
    } else {
        QMessageBox::critical(this, "Error", "Failed to update item.");
    }
}

void MainWindow::onvaliderclicked() {
    QString refText = ui->refmod->text().trimmed();

    if (refText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un REF à vérifier.");
        return;
    }

    int ref = refText.toInt();

    // Check if the REF exists and retrieve data
    QSqlQuery query;
    query.prepare("SELECT TYPE, PRIX_UNITAIRE, QUANTITE FROM STOCK WHERE REF = :ref");
    query.bindValue(":ref", ref);

    if (query.exec() && query.next()) {
        ui->refmod->setText(QString::number(ref));
        ui->typemod->setText(query.value(0).toString());
        ui->prixmod->setText(QString::number(query.value(1).toDouble(), 'f', 2));
        ui->quantitemod->setText(QString::number(query.value(2).toInt()));
    } else {
        QMessageBox::warning(this, "Erreur", "Le REF spécifié n'existe pas.");
        ui->refmod->clear();
        ui->typemod->clear();
        ui->prixmod->clear();
        ui->quantitemod->clear();
    }
}

// New function to display stocks in a QTableWidget
void MainWindow::displayStocks() {
    // Clear existing data
    ui->table->setRowCount(0);  // Reset the row count

    // Set the header labels for the table
    QStringList headers = { "REF", "Type", "Prix Unitaire", "Quantité" };
    ui->table->setHorizontalHeaderLabels(headers);

    // Fetch stocks
    Stock stock;
    QList<Stock> stocks = stock.afficherStocks();

    // Populate the table with stock data
    for (const Stock& s : stocks) {
        int rowPosition = ui->table->rowCount();  // Get the current number of rows
        ui->table->insertRow(rowPosition);  // Insert a new row at the end
        ui->table->setItem(rowPosition, 0, new QTableWidgetItem(QString::number(s.getRef())));
        ui->table->setItem(rowPosition, 1, new QTableWidgetItem(s.getType()));
        ui->table->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(s.getPrixUnitaire(), 'f', 2)));
        ui->table->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(s.getQuantite())));
    }
}
