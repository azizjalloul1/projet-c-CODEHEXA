#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QChartView>
#include "etablissement.h"
#include "statswindow.h"
#include <QModelIndex>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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

};

#endif // MAINWINDOW_H
