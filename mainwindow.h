#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);


private slots:
    void onajouterclicked();
    void onsupprimerclicked();
    void onmodifierclicked();
    void onvaliderclicked();
    void displayStocks();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
