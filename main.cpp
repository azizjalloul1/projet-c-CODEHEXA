#include "mainwindow.h"
#include "connexion.h"
#include "loginwidget.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test = c.ouvrirConnexion();
    if (!test) {
        QMessageBox::critical(nullptr, " Connexion",
                              "Impossible de se connecter à la base de données :\n");
        return -1;
    }

    // Afficher le widget de login
    LoginWidget loginWidget;
    MainWindow mainWindow;
    loginWidget.show();

    QObject::connect(&loginWidget, &LoginWidget::loginSuccessful, [&]() {
        loginWidget.close();
        mainWindow.show();
    });


    return a.exec();
}
