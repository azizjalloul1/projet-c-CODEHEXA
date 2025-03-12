/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idLineEdit;
    QLabel *label_2;
    QLineEdit *motdpLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loginButton;
    QPushButton *mdpOublieButton;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(698, 539);
        verticalLayout = new QVBoxLayout(LoginWidget);
        verticalLayout->setObjectName("verticalLayout");
        imageLabel = new QLabel(LoginWidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setMaximumSize(QSize(700, 100));
        imageLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        imageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(imageLabel);

        label_3 = new QLabel(LoginWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(41);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(LoginWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label);

        idLineEdit = new QLineEdit(LoginWidget);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(idLineEdit);

        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(100, 20));

        horizontalLayout->addWidget(label_2);

        motdpLineEdit = new QLineEdit(LoginWidget);
        motdpLineEdit->setObjectName("motdpLineEdit");
        motdpLineEdit->setMaximumSize(QSize(200, 16777215));
        motdpLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout->addWidget(motdpLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName("loginButton");

        horizontalLayout_2->addWidget(loginButton);

        mdpOublieButton = new QPushButton(LoginWidget);
        mdpOublieButton->setObjectName("mdpOublieButton");
        mdpOublieButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(mdpOublieButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Login", nullptr));
        LoginWidget->setStyleSheet(QCoreApplication::translate("LoginWidget", "\n"
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
        label_3->setText(QCoreApplication::translate("LoginWidget", "BIENVENUE ! Ins\303\251rer votre donn\303\251es personnel", nullptr));
        label->setText(QCoreApplication::translate("LoginWidget", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "mot de passe", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWidget", "Se connecter", nullptr));
        mdpOublieButton->setText(QCoreApplication::translate("LoginWidget", "MDP oubli\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
