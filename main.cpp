#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if (test){
        w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connection succeful.\nClick Cancel to exit."),QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr,QObject::tr("database is not open"), QObject::tr("connection failed .\nClick Cancel to exit ."),
                              QMessageBox::Cancel);
        return 1;
    }
    return a.exec();
}
