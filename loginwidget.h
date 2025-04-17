#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include "mdprestwindow.h"
#include "mainwindow.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

signals:
signals:
    void loginSuccessful(const QString &id, const QString &role);


private slots:
    void onLoginClicked(); // Slot pour le clic sur le bouton de connexion
    void onMDPOublieClicked(); // Slot pour le clic sur le bouton "Mot de passe oublié"

private:
    Ui::LoginWidget *ui;
    MainWindow *mainWindow;
    MDPRestWindow *mdpRestWindow; // Pointeur vers la fenêtre de réinitialisation
    QString transformerMotDePasse(const QString &mdp, const QString &salt);
};

#endif // LOGINWIDGET_H
