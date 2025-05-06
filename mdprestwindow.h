#ifndef MDPRESTWINDOW_H
#define MDPRESTWINDOW_H

#include <QMessageBox>
#include <QSqlQuery>
#include <QCryptographicHash>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRandomGenerator>

#include "mainwindow.h"


namespace Ui {
class MDPRestWindow;
}

class MDPRestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MDPRestWindow(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~MDPRestWindow();

private slots:
    void onEnvoyerButtonClicked(); // Slot pour le bouton "Envoyer le code"
    void onValiderButtonClicked(); // Slot pour le bouton "Valider le code"
    void onChangerButtonClicked(); // Slot pour le bouton "Changer le mot de passe"

private:
    Ui::MDPRestWindow *ui;
    MainWindow *mainWindow;
    QString codeGenere; // Stocke le code de vérification généré
    QString idUtilisateur; // Stocke l'ID de l'utilisateur

    // Méthodes utilitaires
    QString recupererEmailParID(const QString &id); // Récupère l'e-mail associé à l'ID
    QString genererCode(); // Génère un code de vérification
    void envoyerCodeParEmail(const QString &email, const QString &code); // Envoie le code par e-mail
    bool validerMotDePasse(const QString &mdp); // Valide le nouveau mot de passe
};

#endif // MDPRESTWINDOW_H
