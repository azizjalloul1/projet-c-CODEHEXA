/********************************************************************************
** Form generated from reading UI file 'MDP_rest.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDP_REST_H
#define UI_MDP_REST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MDPRestWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *idInput;
    QPushButton *envoyerButton;
    QLineEdit *codeInput;
    QPushButton *validerButton;
    QLineEdit *nouveauMDPInput;
    QPushButton *changerButton;

    void setupUi(QDialog *MDPRestWindow)
    {
        if (MDPRestWindow->objectName().isEmpty())
            MDPRestWindow->setObjectName("MDPRestWindow");
        MDPRestWindow->resize(499, 468);
        verticalLayout = new QVBoxLayout(MDPRestWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MDPRestWindow);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 100));
        label->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        idInput = new QLineEdit(MDPRestWindow);
        idInput->setObjectName("idInput");

        verticalLayout->addWidget(idInput);

        envoyerButton = new QPushButton(MDPRestWindow);
        envoyerButton->setObjectName("envoyerButton");

        verticalLayout->addWidget(envoyerButton);

        codeInput = new QLineEdit(MDPRestWindow);
        codeInput->setObjectName("codeInput");
        codeInput->setEnabled(false);

        verticalLayout->addWidget(codeInput);

        validerButton = new QPushButton(MDPRestWindow);
        validerButton->setObjectName("validerButton");
        validerButton->setEnabled(false);

        verticalLayout->addWidget(validerButton);

        nouveauMDPInput = new QLineEdit(MDPRestWindow);
        nouveauMDPInput->setObjectName("nouveauMDPInput");
        nouveauMDPInput->setEnabled(false);
        nouveauMDPInput->setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        nouveauMDPInput->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(nouveauMDPInput);

        changerButton = new QPushButton(MDPRestWindow);
        changerButton->setObjectName("changerButton");
        changerButton->setEnabled(false);

        verticalLayout->addWidget(changerButton);


        retranslateUi(MDPRestWindow);

        QMetaObject::connectSlotsByName(MDPRestWindow);
    } // setupUi

    void retranslateUi(QDialog *MDPRestWindow)
    {
        MDPRestWindow->setWindowTitle(QCoreApplication::translate("MDPRestWindow", "R\303\251initialisation du mot de passe", nullptr));
        label->setText(QCoreApplication::translate("MDPRestWindow", "R\303\251initialisation du mot de passe", nullptr));
        idInput->setPlaceholderText(QCoreApplication::translate("MDPRestWindow", "Entrez votre ID", nullptr));
        envoyerButton->setText(QCoreApplication::translate("MDPRestWindow", "Envoyer le code", nullptr));
        codeInput->setPlaceholderText(QCoreApplication::translate("MDPRestWindow", "Entrez le code de v\303\251rification", nullptr));
        validerButton->setText(QCoreApplication::translate("MDPRestWindow", "Valider le code", nullptr));
        nouveauMDPInput->setPlaceholderText(QCoreApplication::translate("MDPRestWindow", "Nouveau mot de passe", nullptr));
        changerButton->setText(QCoreApplication::translate("MDPRestWindow", "Changer le mot de passe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MDPRestWindow: public Ui_MDPRestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDP_REST_H
