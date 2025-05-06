#include "connexion.h"
#include "loginwidget.h"
#include "accueil.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test = c.ouvrirConnexion();
    if (!test) {
        QMessageBox::critical(nullptr, "Connexion",
                              "Impossible de se connecter à la base de données.");
        return -1;
    }

    LoginWidget loginWidget;
    Accueil accueilWindow;

    QObject::connect(&loginWidget, &LoginWidget::loginSuccessful,
                     [&](const QString &id, const QString &role) {
                         loginWidget.close();
                         accueilWindow.setUtilisateur(id, role);
                         accueilWindow.show();
                     });

    loginWidget.show();

    return a.exec();
}
