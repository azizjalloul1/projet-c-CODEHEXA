#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c ;
    bool test = c.ouvrirConnexion() ;
    if(!test){
        QMessageBox::critical(nullptr, "Erreur de Connexion",
                              "Impossible de se connecter à la base de données \n");
    }


    MainWindow w;
    w.show();
    return a.exec();
}
