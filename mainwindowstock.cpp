#include "mainwindowstock.h"
#include "stock.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include "ui_mainwindowstock.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include "CustomComboBox.h"
#include "AnimatedDialog.h"
#include "accueil.h"

MainWindowstock::MainWindowstock(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindowstock)
{
    ui->setupUi(this);
    connect(ui->suppb, &QPushButton::clicked, this, &MainWindowstock::onsupprimerclicked);
    connect(ui->addb, &QPushButton::clicked, this, &MainWindowstock::onajouterclicked);
    connect(ui->modb, &QPushButton::clicked, this, &MainWindowstock::onmodifierclicked);
    connect(ui->valider, &QPushButton::clicked, this, &MainWindowstock::onvaliderclicked);
    connect(ui->affiche, &QTabWidget::currentChanged, this, &MainWindowstock::displayStocks);
    connect(ui->triButton, &QPushButton::clicked, this, &MainWindowstock::onTriButtonClicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindowstock::onRechercheTextChanged);
    connect(ui->exportButton, &QPushButton::clicked, this, &MainWindowstock::exportToPDF);
    connect(ui->affiche, &QTabWidget::currentChanged, this, &MainWindowstock::onTabChanged);
    connect(ui->addb, &QPushButton::clicked, this, &MainWindowstock::ajouterFourniture);
    populateFournisseurComboBox();
    displayStocks(); // Load stocks
    connect(ui->idfournisseur, &CustomComboBox::popupShown, this, &MainWindowstock::populateFournisseurComboBox);
    connect(ui->textbutton, &QPushButton::clicked, this, &MainWindowstock::exportToTextFile);

    connect(ui->r2, &QPushButton::clicked, this, &MainWindowstock::retour);







}

void MainWindowstock::setAccueil(Accueil *accueilWindow) {
    this->accueil = accueilWindow;
}

void MainWindowstock::retour()
{
    this->hide();           // cacher MainWindow
    if (accueil) {
        accueil->show();    // montrer Accueil
    }
}

void MainWindowstock::onTabChanged(int index) {
    // Assuming your "Affichage" tab has index 0 (change this if needed)
    if (index == 1) {
        checkStockAlerts(); // Call alert only when Affichage tab is activated
    }
    if (index == 4) { // Assuming index 1 is the history tab
        afficherHistoriqueFourniture();
    }
}

void MainWindowstock::populateFournisseurComboBox() {
    qDebug() << "ComboBox opened! Populating...";

    ui->idfournisseur->clear();

    QSqlQuery query;
    query.setForwardOnly(true);  // Important avec ODBC pour éviter les erreurs de curseur

    if (query.exec("SELECT ID_FOURNISSEUR FROM fournisseur")) {
        qDebug() << "Query executed successfully.";
        while (query.next()) {
            int id = query.value(0).toInt();
            qDebug() << "Fetched ID:" << id;
            ui->idfournisseur->addItem(QString::number(id));
        }
    } else {
        qDebug() << "Failed to fetch fournisseurs:" << query.lastError().text();
    }
}








void MainWindowstock::onajouterclicked()
{
    QString refText = ui->ref->text();
    QString prixText = ui->prix->text();
    QString type = ui->type->text();
    QString quantiteText = ui->quantite->text();

    if (refText.isEmpty() || !refText.toInt()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid reference number.");
        return;
    }

    bool ok;
    double prix = prixText.toDouble(&ok);
    if (prixText.isEmpty() || !ok || prix < 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid price.");
        return;
    }

    int quantite = quantiteText.toInt(&ok);
    if (quantiteText.isEmpty() || !ok || quantite < 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid quantity.");
        return;
    }

    Stock stock(refText.toInt(), prix, type, quantite);

    if (stock.ajouterStock()) {
        QMessageBox::information(this, "Success", "Item added successfully.");
        displayStocks();
        loadAndDisplayStock(ui->frame);
    } else {
        QMessageBox::critical(this, "Error", "Failed to add item.");
    }
}

void MainWindowstock::onsupprimerclicked()
{
    QString refText = ui->suppref->text();

    if (refText.isEmpty() || !refText.toInt()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid reference number.");
        return;
    }

    int ref = refText.toInt();

    Stock stock;
    if (stock.supprimerStock(ref)) {
        QMessageBox::information(this, "Success", "Item deleted successfully.");
        displayStocks();
        loadAndDisplayStock(ui->frame);
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete item.");
    }
}

void MainWindowstock::onmodifierclicked()
{
    int ref = ui->refmod->text().toInt();
    double prix = ui->prixmod->text().toDouble();
    QString type = ui->typemod->text();
    int quantite = ui->quantitemod->text().toInt();

    Stock stock(ref, prix, type, quantite);

    if (stock.modifierStock()) {
        QMessageBox::information(this, "Success", "Item updated successfully.");
        displayStocks();
        loadAndDisplayStock(ui->frame);
    } else {
        QMessageBox::critical(this, "Error", "Failed to update item.");
    }
}

void MainWindowstock::onvaliderclicked()
{
    QString refText = ui->refmod->text().trimmed();

    if (refText.isEmpty() || !refText.toInt()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un REF valide.");
        return;
    }

    int ref = refText.toInt();

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

void MainWindowstock::displayStocks()
{
    ui->table->setRowCount(0);
    QStringList headers = { "REF", "Type", "Prix Unitaire", "Quantité" };
    ui->table->setHorizontalHeaderLabels(headers);

    Stock stock;
    QList<Stock> stocks = stock.afficherStocks();

    for (const Stock& s : stocks) {
        int rowPosition = ui->table->rowCount();
        ui->table->insertRow(rowPosition);
        ui->table->setItem(rowPosition, 0, new QTableWidgetItem(QString::number(s.getRef())));
        ui->table->setItem(rowPosition, 1, new QTableWidgetItem(s.getType()));
        ui->table->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(s.getPrixUnitaire(), 'f', 2)));
        ui->table->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(s.getQuantite())));
    }

    loadAndDisplayStock(ui->frame); // Refresh the progress bar

}

void MainWindowstock::onTriButtonClicked()
{
    ui->table->setRowCount(0);
    Stock stock;
    QList<Stock> stocks = stock.afficherStocksTriesParQuantiteDesc();

    for (const Stock& s : stocks) {
        int rowPosition = ui->table->rowCount();
        ui->table->insertRow(rowPosition);
        ui->table->setItem(rowPosition, 0, new QTableWidgetItem(QString::number(s.getRef())));
        ui->table->setItem(rowPosition, 1, new QTableWidgetItem(s.getType()));
        ui->table->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(s.getPrixUnitaire(), 'f', 2)));
        ui->table->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(s.getQuantite())));
    }
}

void MainWindowstock::onRechercheTextChanged(const QString &text)
{
    Stock stock;
    QList<Stock> stocks;

    if (text.isEmpty()) {
        stocks = stock.afficherStocks();
    } else {
        stocks = stock.afficherStocksParRef(text.toInt());
    }

    ui->table->setRowCount(0);
    for (const Stock& s : stocks) {
        int rowPosition = ui->table->rowCount();
        ui->table->insertRow(rowPosition);
        ui->table->setItem(rowPosition, 0, new QTableWidgetItem(QString::number(s.getRef())));
        ui->table->setItem(rowPosition, 1, new QTableWidgetItem(s.getType()));
        ui->table->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(s.getPrixUnitaire(), 'f', 2)));
        ui->table->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(s.getQuantite())));
    }

    loadAndDisplayStock(ui->frame); // Optional: refresh stats while searching
}

void MainWindowstock::exportToPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);

    QPainter painter(&writer);
    painter.setPen(Qt::black);

    int margin = 70;
    int y = margin;

    painter.setFont(QFont("Arial", 24, QFont::Bold));
    painter.drawText(writer.width() / 2 - 150, y, "Stock Inventory Report");
    y += 50;

    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.setPen(Qt::white);
    QRect headerRect = QRect(margin, y, writer.width() - 2 * margin, 50);
    painter.fillRect(headerRect, Qt::darkBlue);

    QStringList headers = {"REF", "Type", "Prix Unitaire", "Quantite"};
    int columnWidth = 300;

    int headerPosX = margin;
    for (const QString& header : headers) {
        painter.drawText(headerPosX + (columnWidth - painter.fontMetrics().boundingRect(header).width()) / 2, y + 35, header);
        headerPosX += columnWidth;
    }

    y += 50;
    painter.setPen(Qt::black);
    painter.drawLine(margin, y, writer.width() - margin, y);

    painter.setFont(QFont("Arial", 12));
    Stock stock;
    QList<Stock> stocks = stock.afficherStocks();

    int rowHeight = 60;
    for (const Stock& s : stocks) {
        y += rowHeight;
        QStringList rowData = {
            QString::number(s.getRef()),
            s.getType(),
            QString::number(s.getPrixUnitaire(), 'f', 2),
            QString::number(s.getQuantite())
        };

        int rowPosX = margin;
        for (int i = 0; i < rowData.size(); ++i) {
            QString data = rowData[i];
            painter.drawText(rowPosX + (columnWidth - painter.fontMetrics().boundingRect(data).width()) / 2, y, data);
            rowPosX += columnWidth;
        }

        painter.drawLine(margin, y + 5, writer.width() - margin, y + 5);
    }

    y += 50;
    QString dateTime = "Generated on: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    painter.setFont(QFont("Arial", 10, QFont::StyleItalic));
    painter.drawText(margin, y, dateTime);

    painter.end();
    QMessageBox::information(this, "Success", "Stock exported to PDF successfully!");
}

void MainWindowstock::loadAndDisplayStock(QFrame* frame) {
    const int maxStock = 100000;
    int currentStock = 0;

    QSqlQuery query;
    if (query.exec("SELECT SUM(quantite) FROM stock")) {
        if (query.next()) {
            currentStock = query.value(0).toInt(); // Get the summed quantity
        }
    } else {
        qDebug() << "Database query failed:" << query.lastError().text();
        return;
    }

    int remainingStock = maxStock - currentStock;

    // Create pie series
    QPieSeries *series = new QPieSeries();
    series->append("Current Stock", currentStock);
    series->append("Remaining", remainingStock);

    // Calculate the percentages
    double currentStockPercentage = (static_cast<double>(currentStock) / maxStock) * 100;
    double remainingStockPercentage = (static_cast<double>(remainingStock) / maxStock) * 100;

    // Set the labels to show percentage
    QPieSlice *usedSlice = series->slices().at(0);
    usedSlice->setExploded(true);
    usedSlice->setLabelVisible(true);
    usedSlice->setBrush(Qt::green);
    usedSlice->setLabel(QString("%1%").arg(currentStockPercentage, 0, 'f', 2));

    QPieSlice *remainSlice = series->slices().at(1);
    remainSlice->setLabelVisible(true);
    remainSlice->setBrush(Qt::gray);
    remainSlice->setLabel(QString("%1%").arg(remainingStockPercentage, 0, 'f', 2));

    // Create chart and view
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Stock Status");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Replace layout content
    QLayout *oldLayout = frame->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->addWidget(chartView);
    frame->setLayout(layout);
}


void MainWindowstock::checkStockAlerts() {
    const int maxStock = 100000;
    int currentStock = 0;

    QSqlQuery query;
    if (query.exec("SELECT SUM(quantite) FROM stock")) {
        if (query.next()) {
            currentStock = query.value(0).toInt();
        }
    } else {
        qDebug() << "Stock alert query failed:" << query.lastError().text();
        return;
    }

    QString message;
    QString title;

    if (currentStock < maxStock * 0.10) {
        title = "⚠️ Stock Bas";
        message = QString("Attention : le stock est faible (%1 sur %2)")
                      .arg(currentStock).arg(maxStock);
    } else if (currentStock >= maxStock) {
        title = "✅ Stock Saturé";
        message = QString("Le stock est saturé (%1/%2)")
                      .arg(currentStock).arg(maxStock);
    } else {
        return;
    }

    AnimatedDialog dialog(title, message, this);
    dialog.exec();
}

void MainWindowstock::ajouterFourniture() {
    QString refText = ui->ref->text();
    QString quantiteText = ui->quantite->text();
    QString prixText = ui->prix->text();
    QString idFournisseurText = ui->idfournisseur->currentText(); // Getting selected item

    // Validation
    if (refText.isEmpty() || quantiteText.isEmpty() || prixText.isEmpty() || idFournisseurText.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    bool okRef, okQuantite, okPrix, okFournisseur;
    int ref = refText.toInt(&okRef);
    int quantite = quantiteText.toInt(&okQuantite);
    double prixUnitaire = prixText.toDouble(&okPrix);
    int idFournisseur = idFournisseurText.toInt(&okFournisseur);

    if (!okRef || !okQuantite || !okPrix || !okFournisseur ||
        ref <= 0 || quantite <= 0 || prixUnitaire < 0 || idFournisseur <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer des valeurs valides.");
        return;
    }

    double prixTotal = quantite * prixUnitaire;
    QString dateSysteme = QDate::currentDate().toString("yyyy-MM-dd");

    // Optional: check if fournisseur exists
    QSqlQuery checkFournisseur;
    checkFournisseur.prepare("SELECT COUNT(*) FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    checkFournisseur.bindValue(":id", idFournisseur);
    if (!checkFournisseur.exec() || !checkFournisseur.next() || checkFournisseur.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "ID FOURNISSEUR introuvable.");
        return;
    }

    // Insert into FOURNIR
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNIR (REF, ID_FOURNISSEUR, DATE_FOURNITURE, QUANTITE, PRIX_TOTALE) "
                  "VALUES (:ref, :idFournisseur, TO_DATE(:date, 'YYYY-MM-DD'), :quantite, :prixTotal)");
    query.bindValue(":ref", ref);
    query.bindValue(":date", dateSysteme);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prixTotal", prixTotal);
    query.bindValue(":idFournisseur", idFournisseur);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", " ajoutée avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout dans FOURNIR.\n" + query.lastError().text());
    }
}


void MainWindowstock::afficherHistoriqueFourniture() {
    QSqlQuery query;
    query.prepare("SELECT REF, ID_FOURNISSEUR, DATE_FOURNITURE, QUANTITE, PRIX_TOTALE FROM FOURNIR");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération de l'historique :\n" + query.lastError().text());
        return;
    }

    // Clear existing content
    ui->tableHistorique->clear();
    ui->tableHistorique->setRowCount(0);

    // Set headers
    QStringList headers = {"REF", "ID FOURNISSEUR", "DATE FOURNITURE", "QUANTITE", "PRIX TOTALE"};
    ui->tableHistorique->setColumnCount(headers.size());
    ui->tableHistorique->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->tableHistorique->insertRow(row);

        for (int col = 0; col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableHistorique->setItem(row, col, item);
        }
        ++row;
    }

    // Resize columns to fit contents
    ui->tableHistorique->resizeColumnsToContents();
}

void MainWindowstock::exportToTextFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en fichier texte", "", "Fichier texte (*.txt)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier pour l'écriture.");
        return;
    }

    QTextStream out(&file);

    // Largeurs des colonnes : REF | ID | Date | Qté | Prix Total
    const int colWidths[] = {10, 25, 30, 10, 10}; // Adjusted width for Date
    int columnCount = ui->tableHistorique->columnCount();
    int safeColumnCount = qMin(columnCount, int(sizeof(colWidths)/sizeof(int)));

    // En-têtes
    for (int col = 0; col < safeColumnCount; ++col) {
        QTableWidgetItem* headerItem = ui->tableHistorique->horizontalHeaderItem(col);
        QString header = headerItem ? headerItem->text() : "";
        out << header.leftJustified(colWidths[col], ' ');
    }
    out << "\n";

    // Ligne séparatrice
    for (int col = 0; col < safeColumnCount; ++col)
        out << QString("-").repeated(colWidths[col]);
    out << "\n";

    // Données
    for (int row = 0; row < ui->tableHistorique->rowCount(); ++row) {
        for (int col = 0; col < safeColumnCount; ++col) {
            QTableWidgetItem* item = ui->tableHistorique->item(row, col);
            QString text = item ? item->text() : "";

            // REF, ID, Date → alignés à gauche ; Quantité, Prix, Total → à droite
            if (col <= 2) {
                out << text.leftJustified(colWidths[col], ' ');
            } else {
                out << text.rightJustified(colWidths[col], ' ');
            }
        }
        out << "\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", "Table exportée en fichier texte avec succès !");
}




