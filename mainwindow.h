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

    void importerid();
    void afficherExamens();
    void ajouterExamen();
    void modifierExamen();
    void modif(int i);
    void supprimerExamen();
    void ExporterPDF();
    void TRIC();
    void TRID();
    void CHERCHER(const QString &id);
    void afficherStatistiques();
    void uploadPDF();
    void genererCodeBarres();
    QPixmap genererCodeBarImage(const QString &text);

private:
    Ui::MainWindow *ui;
    QChartView *chartView = nullptr;
};

#endif
