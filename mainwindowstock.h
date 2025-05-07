#ifndef MAINWINDOWSTOCK_H
#define MAINWINDOWSTOCK_H

#include <QMainWindow>
#include <QtCharts/QChartView>  // Include chart view header for pie chart
#include "CustomComboBox.h"
#include "ui_mainwindow.h"

class Accueil;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowstock; }
QT_END_NAMESPACE

class MainWindowstock : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindowstock(QWidget *parent = nullptr);
    void setAccueil(Accueil *accueilWindow);


private slots:
    void retour();
    void onajouterclicked();
    void onsupprimerclicked();
    void onmodifierclicked();
    void onvaliderclicked();
    void displayStocks();
    void onTriButtonClicked(); // Slot for sorting button
    void onRechercheTextChanged(const QString &text); // Slot for search function
    void exportToPDF();  // Function to export stock data to a PDF file
    //void showStockStatistics();  // Function to display stock statistics
    void loadAndDisplayStock(QFrame* frame);
    void checkStockAlerts();
    void ajouterFourniture();
    void populateFournisseurComboBox();
    void afficherHistoriqueFourniture();
    void exportToTextFile();




private:
    Ui::MainWindowstock *ui;            // UI pointer
    Accueil *accueil;
    QChartView *chartView;         // Member variable for the pie chart view
    void setupPieChartFrame();      // Function to set up the pie chart frame
    void onTabChanged(int index);

};

#endif // MAINWINDOWSTOCK_H
