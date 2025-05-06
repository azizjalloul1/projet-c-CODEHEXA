#include "mainwindowF.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connexion c;
    bool test = c.ouvrirConnexion();

    if (test) {
        MainWindowF w;  // Création de la fenêtre principale
        w.show();       // Affichage de la fenêtre principale
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données !");
        return -1;
    }
}
