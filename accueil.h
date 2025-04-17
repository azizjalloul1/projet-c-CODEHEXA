#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include "mainwindow.h"
#include <QPixmap>

namespace Ui {
class accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

    void setUtilisateur(const QString &id, const QString &role);

private:
    Ui::accueil *ui;
    MainWindow *mainWindow;
    QString userId;
    QString userRole;
};

#endif // ACCUEIL_H
