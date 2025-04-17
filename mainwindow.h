#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


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
    void afficherFournisseurs();    // Afficher les fournisseurs
    void onRechercherClicked();     // Rechercher un fournisseur par nom
    void envoyerSMS() ;
    void afficherStatistiques();
   // void afficherHistoriqueCommandes(const QString& fournisseurId);
     void trierParCommande();
    //void afficherMeilleurFournisseur();
    void genererIDFournisseur();
    void chargerListeIDs();
    void sendEmail(const QString &supplierName, int totalOrders);
    void onEmailSent(QNetworkReply* reply);
    void remplirChampsFournisseur();
   // void addCommande(const QString &id_fournisseur);
    void exporterEnPDF();
    //void afficherHistoriqueCommandes();
    void afficherHistoriqueMeilleurFournisseur();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
