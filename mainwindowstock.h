<<<<<<< HEAD
#ifndef MAINWINDOWSTOCK_H
#define MAINWINDOWSTOCK_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
>>>>>>> origin/gestion_stock

#include <QMainWindow>
#include <QtCharts/QChartView>  // Include chart view header for pie chart
#include "CustomComboBox.h"
#include "ui_mainwindow.h"

<<<<<<< HEAD
class Accueil;

=======
>>>>>>> origin/gestion_stock
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowstock; }
QT_END_NAMESPACE

class MainWindowstock : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindowstock(QWidget *parent = nullptr);
<<<<<<< HEAD
    void setAccueil(Accueil *accueilWindow);

=======
>>>>>>> origin/gestion_stock

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
    Ui::MainWindowstock *ui;            // UI pointer
<<<<<<< HEAD
    Accueil *accueil;
=======
>>>>>>> origin/gestion_stock
    QChartView *chartView;         // Member variable for the pie chart view
    void setupPieChartFrame();      // Function to set up the pie chart frame
    void onTabChanged(int index);

};

<<<<<<< HEAD
#endif // MAINWINDOWSTOCK_H
=======
#endif // MAINWINDOW_H
>>>>>>> origin/gestion_stock
