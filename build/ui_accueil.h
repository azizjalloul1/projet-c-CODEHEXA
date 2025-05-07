/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accueil
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QLabel *labelBienvenue;
    QVBoxLayout *verticalLayout_2;
    QPushButton *employee;
    QPushButton *stock;
    QPushButton *vehicule;
    QPushButton *fournisseur;
    QPushButton *examen;
    QPushButton *etablissement;

    void setupUi(QWidget *accueil)
    {
        if (accueil->objectName().isEmpty())
            accueil->setObjectName("accueil");
        accueil->resize(698, 539);
        verticalLayout = new QVBoxLayout(accueil);
        verticalLayout->setObjectName("verticalLayout");
        imageLabel = new QLabel(accueil);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setMaximumSize(QSize(700, 100));
        imageLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        imageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(imageLabel);

        labelBienvenue = new QLabel(accueil);
        labelBienvenue->setObjectName("labelBienvenue");
        labelBienvenue->setMaximumSize(QSize(16777215, 50));
        labelBienvenue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelBienvenue);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        employee = new QPushButton(accueil);
        employee->setObjectName("employee");

        verticalLayout_2->addWidget(employee);

        stock = new QPushButton(accueil);
        stock->setObjectName("stock");

        verticalLayout_2->addWidget(stock);

        vehicule = new QPushButton(accueil);
        vehicule->setObjectName("vehicule");

        verticalLayout_2->addWidget(vehicule);

        fournisseur = new QPushButton(accueil);
        fournisseur->setObjectName("fournisseur");

        verticalLayout_2->addWidget(fournisseur);

        examen = new QPushButton(accueil);
        examen->setObjectName("examen");

        verticalLayout_2->addWidget(examen);

        etablissement = new QPushButton(accueil);
        etablissement->setObjectName("etablissement");

        verticalLayout_2->addWidget(etablissement);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(accueil);

        QMetaObject::connectSlotsByName(accueil);
    } // setupUi

    void retranslateUi(QWidget *accueil)
    {
        accueil->setWindowTitle(QCoreApplication::translate("accueil", "Accueil", nullptr));
        accueil->setStyleSheet(QCoreApplication::translate("accueil", "\n"
"    QWidget {\n"
"        background-color: #E3F0FE;\n"
"        background-position: center;\n"
"        background-repeat: no-repeat;\n"
"        background-size: cover;\n"
"    }\n"
"\n"
"    QLabel {\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: #333;\n"
"    }\n"
"\n"
"    QLineEdit {\n"
"        border: 2px solid #ccc;\n"
"        border-radius: 8px;\n"
"        padding: 5px;\n"
"        font-size: 14px;\n"
"        background-color: #fff;\n"
"        selection-background-color: #7ec8e3;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #0078D7;\n"
"        color: white;\n"
"        border-radius: 8px;\n"
"        padding: 8px;\n"
"        font-size: 14px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #005a9e;\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: #004b87;\n"
"    }\n"
"   ", nullptr));
        imageLabel->setText(QString());
        labelBienvenue->setText(QCoreApplication::translate("accueil", "TextLabel", nullptr));
        employee->setText(QCoreApplication::translate("accueil", "Gestion des employ\303\251es", nullptr));
        stock->setText(QCoreApplication::translate("accueil", "Gestion de stock ", nullptr));
        vehicule->setText(QCoreApplication::translate("accueil", "Gestion des v\303\251hicules", nullptr));
        fournisseur->setText(QCoreApplication::translate("accueil", "Gestion des Fournisseurs", nullptr));
        examen->setText(QCoreApplication::translate("accueil", "Gestion des examen", nullptr));
        etablissement->setText(QCoreApplication::translate("accueil", "Gestion des Etablissement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accueil: public Ui_accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
