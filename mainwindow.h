#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crypterMotDePasse(const QString &mdp, QString &hashedPassword, QString &salt);

private slots:
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
    struct PasswordData {
        QString hashedPassword;
        QString salt;
    };
    PasswordData crypterMotDePasse(const QString &mdp);

    bool triCroissant = true;
};

#endif // MAINWINDOW_H
