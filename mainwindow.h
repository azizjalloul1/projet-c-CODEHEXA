#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
<<<<<<< HEAD
#include <QTableWidget>
#include <QMessageBox>

#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

#include <QPrinter>
#include <QPageSize>
#include <QPainter>
#include <QFileDialog>

#include <cmath>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QCryptographicHash>

#include <QTimer>
#include <QProcessEnvironment>
#include <QProcess>

// Ne pas inclure accueil.h ici
class Accueil;

=======
#include <QMessageBox>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QChartView>
#include "etablissement.h"
#include "statswindow.h"
#include <QModelIndex>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
>>>>>>> origin/gestionetablissement
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setAccueil(Accueil *accueilWindow);

    void crypterMotDePasse(const QString &mdp, QString &hashedPassword, QString &salt);
    void collectId();
    void collectSalary();
    void collectRole();
    void collectEmail();
    void  collectName();
    void collectPassword();

private slots:

    void on_btnRetourAccueil_clicked();

    void executePythonScript(const QString& promptType, std::function<void()> callback);
    void startDataCollection();

    void resetInputs();

    bool validerMotDePasse();
    bool validerEmail(QString &email);
    bool verifierIdExistant();

    void ajouterEmploye();
    void afficherEmployes();
    void supprimerEmploye();
    void modifierEmploye();

    void afficherStatistiques();
    void rechercherEmploye();
    void exportPdf();
    void trierParSalaire();


private:
    Ui::MainWindow *ui;
    Accueil *accueil;

    struct PasswordData {
        QString hashedPassword;
        QString salt;
    };
    PasswordData crypterMotDePasse(const QString &mdp);

    bool triCroissant = true;
=======
#include "vehicules.h"
#include <QSerialPort>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTableWidget();

private slots:

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
    Ui::MainWindow *ui;
    bool sortAsc = true;
    QMap<int, int> currentSolutionIndex;
    QTimer *gpsTimer;
    QStringList allSymptoms;
    QSerialPort *serial;
>>>>>>> origin/gestion-de-véhicules
=======
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_mod_button_clicked();
    void on_SuppButton_clicked();
    void on_aff_pdf_clicked();
    void on_triComboBox_currentTextChanged(const QString &text);

    void on_aff_rech_clicked();

    void remplirChampsModification(const QString& id_E);
    void on_btn_stats_clicked();
    void on_tableView_Etablissements_clicked(const QModelIndex &index);
    void mettreAJourPositionUtilisateur(const QGeoPositionInfo &info); // MODIFIER la signature

    void on_btn_path_clicked();  // bouton pour afficher le chemin


private:
    Ui::MainWindow *ui;
    Etablissement etablissement;
    void afficherCarteEtablissements();
    void afficherEtablissement();
    void clearInputs();
    void calculerCheminVersEtablissement(double destLat, double destLon);
    QGeoPositionInfoSource *positionSource;
    QGeoCoordinate currentPosition;
    Etablissement getSelectedEtablissement();


>>>>>>> origin/gestionetablissement
};

#endif // MAINWINDOW_H
