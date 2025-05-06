#ifndef MAINWINDOWF_H
#define MAINWINDOWF_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "smtpclient.h"
#include "sms.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowF; }  // uniquement forward‑déclaration
QT_END_NAMESPACE

class MainWindowF : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowF(QWidget *parent = nullptr);
    ~MainWindowF();

private slots:
    void on_btnAjouter_clicked();
    void on_btnSupprimer_clicked();
    void on_btnModifier_clicked();
    void on_btnMeilleurFournisseur_clicked();
    void afficherFournisseurs();
    void onRechercherClicked();
    void envoyerSMS();
    void afficherStatistiques();
    void trierParCommande();
    void genererIDFournisseur();
    void chargerListeIDs();
    void remplirChampsFournisseur();
    void exporterEnPDF();
    void afficherHistoriqueCommandes(const QString &fournisseurId);
    void onSmtpStatus(const QString &msg);

private:
    Ui::MainWindowF *ui;
    SMS* m_sms;
    void envoyerEmailSMTP(const QString &to,
                          const QString &subject,
                          const QString &body);
};

#endif // MAINWINDOWF_H
