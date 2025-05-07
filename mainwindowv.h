#ifndef MAINWINDOWV_H
#define MAINWINDOWV_H

#include <QMainWindow>
#include "vehicules.h"
#include <QSerialPort>




class Accueil;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowv; }
QT_END_NAMESPACE

class MainWindowv : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindowv(QWidget *parent = nullptr);
    ~MainWindowv();
    void updateTableWidget();
    void setAccueil(Accueil *accueilWindow);

private slots:

    void retour();
    void on_addButton_clicked();
    void on_mod_button_clicked();
    void on_matricule_valider_clicked();
    void on_Supp_Button_clicked();
    void on_triButton_clicked();
    void on_exportButton_clicked();
    void showStatistics();
    void on_searchTextChanged(const QString &searchTerm);
    void updateErrorTable();
    void on_btnNextSolution_clicked();
    void simulateAndInsertGPS(const QString &matricule);
    void on_btnSimulateGPS_clicked();
    void on_btnViewLatestGPS_clicked();
    void loadSymptomsToList();  // new function
    void filterSymptoms(const QString &text);
    void viewLatestGPS(const QString &matricule);
    void setPinLocation(double lat, double lon);
    void readFromArduino();

private:
    Ui::MainWindowv *ui;
    Accueil *accueil;
    bool sortAsc = true;
    QMap<int, int> currentSolutionIndex;
    QTimer *gpsTimer;
    QStringList allSymptoms;
    QSerialPort *serial;
};

#endif // MAINWINDOWV_H
