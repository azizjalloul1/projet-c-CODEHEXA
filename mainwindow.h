#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QVBoxLayout>

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

    void afficherExamens();

    void ajouterExamen();

    void remplirCombo();
    void modif(int i);
    void modifierExamen();


    void supprimerExamen();

    void ExporterPDF();

    void TRIC();
    void TRID();
    void TRIDATE();
    void TriCombo(int i);


    void CHERCHER(const QString &id);

    void Statistiques();

    void uploadPDF();

    QPixmap QRCodeImage(const QString &text);
    void QRCode();



private:
    Ui::MainWindow *ui;
    QChartView *chartView = nullptr;
};

#endif
