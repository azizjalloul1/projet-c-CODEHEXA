#ifndef WINDOWEXAMEN_H
#define WINDOWEXAMEN_H
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QVBoxLayout>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class WindowExamen;
}

QT_END_NAMESPACE

class WindowExamen : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowExamen(QWidget *parent = nullptr);
    ~WindowExamen();


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
    void lireDonneesArduino();
    void ValeurSuperieuregaz(int valeurGaz);

private:
    Ui::WindowExamen *ui;
    QChartView *chartView = nullptr;
    QSerialPort *arduino;

};

#endif
