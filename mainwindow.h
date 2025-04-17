#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "etablissement.h"
#include "statswindow.h"

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
    void on_aff_tri_clicked();

    void on_aff_rech_clicked();

    void remplirChampsModification(const QString& id_E);
    void on_btn_stats_clicked();
    void on_btn_geo_clicked();


    void on_btn_path_clicked();



private:
    Ui::MainWindow *ui;
    Etablissement etablissement;

    void afficherEtablissement();
    void clearInputs();

};

#endif // MAINWINDOW_H
