
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "vehicules.h"
#include "mainwindow.h"  // Include MainWindow
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed."), QMessageBox::Ok);
        return -1;
    }

    // Create and show MainWindow
    MainWindow w;
    w.show();

    return a.exec();  // Start the event loop
}
