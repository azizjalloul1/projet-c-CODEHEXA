#include "connexion.h"

Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connexion::ouvrirConnexion()
{
    db.setDatabaseName("PROJET"); // Nom de la source de données ODBC
    db.setUserName("naadim");     // Nom d'utilisateur Oracle
    db.setPassword("0000");       // Mot de passe Oracle

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Erreur de Connexion",
                              "Impossible de se connecter à la base de données :\n" + db.lastError().text());
        QMessageBox::critical(nullptr, "Erreur de Connexion",
                              "Impossible de se connecter à la base de données :\n" + db.lastError().text());
        return false;
    } else {
        qDebug() << "Connexion réussie !";
        return true;
    }
}

void Connexion::fermerConnexion()
{
    db.close();
    qDebug() << "Connexion fermée.";
}
