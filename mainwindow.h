#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>  // Include chart view header for pie chart
#include "CustomComboBox.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
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
    Ui::MainWindow *ui;            // UI pointer
    QChartView *chartView;         // Member variable for the pie chart view
    void setupPieChartFrame();      // Function to set up the pie chart frame
    void onTabChanged(int index);

};

#endif // MAINWINDOW_H
