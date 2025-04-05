#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE//lien entre mainwindow.h et mainwindow.ui

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);//constructeur
    ~MainWindow();//destructeur


private slots: //les méthodes privées

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

private:
    Ui::MainWindow *ui;
};

#endif
