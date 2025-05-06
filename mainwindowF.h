#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "smtpclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();   // Ajouter un fournisseur
    void on_btnSupprimer_clicked(); // Supprimer un fournisseur
    void on_btnModifier_clicked();  // Modifier un fournisseur
    void on_btnMeilleurFournisseur_clicked();
    void afficherFournisseurs();    // Afficher les fournisseurs
    void onRechercherClicked();     // Rechercher un fournisseur par nom
   // void sendEmail(const QString& fournisseurNom, int totalCommandes);
    void envoyerSMS();
    void afficherStatistiques();
    //void afficherHistoriqueCommandes(const QString &fournisseurId);
   // void afficherHistoriqueCommandes(const QString& fournisseurId);
     void trierParCommande();
    //void afficherMeilleurFournisseur();
    void genererIDFournisseur();
    void chargerListeIDs();
    // Déclaration dans mainwindow.h
    //void sendEmail(const QString& fournisseurNom, int totalCommandes, int frequenceCommandes);
 //void afficherHistoriqueCommandes(const QString& fournisseurId);
    //void onEmailSent(QNetworkReply* reply);
    void remplirChampsFournisseur();
   // void addCommande(const QString &id_fournisseur);
    void exporterEnPDF();
    //void afficherHistoriqueCommandes();
    //void afficherHistoriqueMeilleurFournisseur();



    void afficherHistoriqueCommandes(const QString &fournisseurId);
    void onSmtpStatus(const QString &msg);

private:
    Ui::MainWindow *ui;

   // SmtpClient    *smtp;

    void envoyerEmailSMTP(const QString &to,
                          const QString &subject,
                          const QString &body);

};

#endif // MAINWINDOW_H
