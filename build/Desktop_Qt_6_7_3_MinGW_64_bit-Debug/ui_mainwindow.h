/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout1;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout1;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *ajout_id;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ajout_nom;
    QLabel *validation;
    QLabel *label_8;
    QLineEdit *ajout_adresse;
    QLabel *label_3;
    QLineEdit *ajout_contact;
    QLabel *label_4;
    QComboBox *ajout_type;
    QPushButton *ajout_button;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *aff_rech;
    QPushButton *aff_pdf;
    QPushButton *aff_tri;
    QPushButton *btn_stats;
    QVBoxLayout *chartLayout;
    QTableView *tableView_Etablissements;
    QWidget *tabSuppression;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLineEdit *SuppID;
    QPushButton *SuppButton;
    QWidget *tabModification;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout2_2;
    QLabel *label_9;
    QLineEdit *mod_nom;
    QLabel *label_11;
    QLineEdit *mod_adresse;
    QLabel *label_12;
    QLineEdit *mod_contact;
    QLabel *label_5;
    QComboBox *mod_type;
    QPushButton *mod_button;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *mod_id;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(933, 784);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"     QWidget {\n"
"     background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(227, 240, 254), stop:1 rgb(187, 222, 251));\n"
"\n"
"       font-family: Arial, sans-serif;\n"
"       font-size: 14px;\n"
"     }\n"
"\n"
"     QLineEdit {\n"
"     border: 2px solid rgb(92, 107, 192);\n"
"\n"
"       border-radius: 8px;\n"
"       padding: 8px;\n"
"       background-color: rgb(249, 249, 249);\n"
"\n"
"       color: #333;\n"
"       font-size: 14px;\n"
"       transition: 0.3s ease-in-out;\n"
"     }\n"
"\n"
"     QLineEdit:focus {\n"
"       border: 2px solid #3f51b5;\n"
"       background-color: #e8eaf6;\n"
"       box-shadow: 0px 0px 5px rgba(63, 81, 181, 0.5);\n"
"     }\n"
"\n"
"     QPushButton {\n"
"       background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2196F3, stop:1 #1976D2);\n"
"       color: white;\n"
"       border-radius: 8px;\n"
"       padding: 12px;\n"
"       font-size: 16px;\n"
"       font-weight: bold;\n"
"       border: none;\n"
"       tra"
                        "nsition: all 0.3s ease-in-out;\n"
"       box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"     }\n"
"\n"
"     QPushButton:hover {\n"
"       background: #1976D2;\n"
"       box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"       background: #0D47A1;\n"
"       box-shadow: inset 2px 2px 4px rgba(0, 0, 0, 0.3);\n"
"     }\n"
"\n"
"     QPushButton:disabled {\n"
"       background: #BBDEFB;\n"
"       color: #757575;\n"
"       box-shadow: none;\n"
"     }\n"
"\n"
"     QTabWidget::pane {\n"
"       border: 2px solid #3f51b5;\n"
"       border-radius: 8px;\n"
"       background: #ffffff;\n"
"     }\n"
"\n"
"     QTabBar::tab {\n"
"       background: #e3f2fd;\n"
"       padding: 10px;\n"
"       border-radius: 8px 8px 0 0;\n"
"       color: #333;\n"
"       font-weight: bold;\n"
"     }\n"
"\n"
"     QTabBar::tab:selected {\n"
"       background: #2196F3;\n"
"       color: white;\n"
"     }\n"
"\n"
"     QComboBox {\n"
"       background-color: #f1f1f1;\n"
"       bor"
                        "der: 2px solid #5c6bc0;\n"
"       border-radius: 8px;\n"
"       padding: 5px;\n"
"       font-size: 14px;\n"
"     }\n"
"\n"
"     QTableWidget {\n"
"       border: 1px solid #5c6bc0;\n"
"       gridline-color: #5c6bc0;\n"
"       background-color: #ffffff;\n"
"     }\n"
"\n"
"     QTableWidget::item {\n"
"       padding: 5px;\n"
"     }\n"
"\n"
"     QTableWidget::item:selected {\n"
"       background-color: #1976D2;\n"
"       color: white;\n"
"     }\n"
"   "));
        verticalLayout1 = new QVBoxLayout(centralwidget);
        verticalLayout1->setObjectName("verticalLayout1");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
        layoutAjout1 = new QVBoxLayout(tabAjout);
        layoutAjout1->setObjectName("layoutAjout1");
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName("verticalLayout_1");
        verticalLayout_1->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_6 = new QLabel(tabAjout);
        label_6->setObjectName("label_6");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("\n"
"                font-size: 16pt;\n"
"                font-weight: bold;\n"
"             "));

        verticalLayout_1->addWidget(label_6);

        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout_1->addWidget(label);

        ajout_id = new QLineEdit(tabAjout);
        ajout_id->setObjectName("ajout_id");
        ajout_id->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_id);

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        label_2->setFont(font1);

        verticalLayout_1->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ajout_nom = new QLineEdit(tabAjout);
        ajout_nom->setObjectName("ajout_nom");
        ajout_nom->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(ajout_nom);

        validation = new QLabel(tabAjout);
        validation->setObjectName("validation");
        validation->setMaximumSize(QSize(1000, 50));

        horizontalLayout_2->addWidget(validation);


        verticalLayout_1->addLayout(horizontalLayout_2);

        label_8 = new QLabel(tabAjout);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 30));

        verticalLayout_1->addWidget(label_8);

        ajout_adresse = new QLineEdit(tabAjout);
        ajout_adresse->setObjectName("ajout_adresse");
        ajout_adresse->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_adresse);

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout_1->addWidget(label_3);

        ajout_contact = new QLineEdit(tabAjout);
        ajout_contact->setObjectName("ajout_contact");
        ajout_contact->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_contact);

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout_1->addWidget(label_4);

        ajout_type = new QComboBox(tabAjout);
        ajout_type->addItem(QString());
        ajout_type->addItem(QString());
        ajout_type->addItem(QString());
        ajout_type->addItem(QString());
        ajout_type->setObjectName("ajout_type");
        ajout_type->setMaximumSize(QSize(16777215, 50));
        ajout_type->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));

        verticalLayout_1->addWidget(ajout_type);

        ajout_button = new QPushButton(tabAjout);
        ajout_button->setObjectName("ajout_button");

        verticalLayout_1->addWidget(ajout_button);


        layoutAjout1->addLayout(verticalLayout_1);

        tabWidget->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout = new QVBoxLayout(tabAffichage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        aff_rech = new QLineEdit(tabAffichage);
        aff_rech->setObjectName("aff_rech");

        horizontalLayout->addWidget(aff_rech);

        aff_pdf = new QPushButton(tabAffichage);
        aff_pdf->setObjectName("aff_pdf");

        horizontalLayout->addWidget(aff_pdf);

        aff_tri = new QPushButton(tabAffichage);
        aff_tri->setObjectName("aff_tri");

        horizontalLayout->addWidget(aff_tri);

        btn_stats = new QPushButton(tabAffichage);
        btn_stats->setObjectName("btn_stats");

        horizontalLayout->addWidget(btn_stats);


        verticalLayout->addLayout(horizontalLayout);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");
        tableView_Etablissements = new QTableView(tabAffichage);
        tableView_Etablissements->setObjectName("tableView_Etablissements");
        tableView_Etablissements->setMinimumSize(QSize(0, 0));

        chartLayout->addWidget(tableView_Etablissements);


        verticalLayout->addLayout(chartLayout);

        tabWidget->addTab(tabAffichage, QString());
        tabSuppression = new QWidget();
        tabSuppression->setObjectName("tabSuppression");
        layoutAjout = new QVBoxLayout(tabSuppression);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_7 = new QLabel(tabSuppression);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"\n"
""));

        verticalLayout_3->addWidget(label_7);

        SuppID = new QLineEdit(tabSuppression);
        SuppID->setObjectName("SuppID");
        SuppID->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(SuppID);

        SuppButton = new QPushButton(tabSuppression);
        SuppButton->setObjectName("SuppButton");

        verticalLayout_3->addWidget(SuppButton);


        layoutAjout->addLayout(verticalLayout_3);

        tabWidget->addTab(tabSuppression, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
        verticalLayoutWidget = new QWidget(tabModification);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 220, 891, 441));
        verticalLayout2_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout2_2->setObjectName("verticalLayout2_2");
        verticalLayout2_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(16777215, 30));

        verticalLayout2_2->addWidget(label_9);

        mod_nom = new QLineEdit(verticalLayoutWidget);
        mod_nom->setObjectName("mod_nom");
        mod_nom->setMaximumSize(QSize(16777215, 50));

        verticalLayout2_2->addWidget(mod_nom);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 30));

        verticalLayout2_2->addWidget(label_11);

        mod_adresse = new QLineEdit(verticalLayoutWidget);
        mod_adresse->setObjectName("mod_adresse");
        mod_adresse->setMaximumSize(QSize(16777215, 50));

        verticalLayout2_2->addWidget(mod_adresse);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 30));

        verticalLayout2_2->addWidget(label_12);

        mod_contact = new QLineEdit(verticalLayoutWidget);
        mod_contact->setObjectName("mod_contact");
        mod_contact->setMaximumSize(QSize(16777215, 50));

        verticalLayout2_2->addWidget(mod_contact);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout2_2->addWidget(label_5);

        mod_type = new QComboBox(verticalLayoutWidget);
        mod_type->addItem(QString());
        mod_type->addItem(QString());
        mod_type->addItem(QString());
        mod_type->addItem(QString());
        mod_type->addItem(QString());
        mod_type->setObjectName("mod_type");
        mod_type->setMaximumSize(QSize(16777215, 50));

        verticalLayout2_2->addWidget(mod_type);

        mod_button = new QPushButton(verticalLayoutWidget);
        mod_button->setObjectName("mod_button");

        verticalLayout2_2->addWidget(mod_button);

        horizontalLayoutWidget = new QWidget(tabModification);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 110, 891, 101));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        mod_id = new QLineEdit(horizontalLayoutWidget);
        mod_id->setObjectName("mod_id");
        mod_id->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_3->addWidget(mod_id);

        label_10 = new QLabel(tabModification);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 70, 889, 30));
        tabWidget->addTab(tabModification, QString());

        verticalLayout1->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 933, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "                             L'ajout d'un \303\251tablissement", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID-E:", nullptr));
        ajout_id->setText(QString());
        ajout_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer l'identifiant ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        ajout_nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer le nom d'\303\251tablissement ", nullptr));
        validation->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        ajout_adresse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer l'adresse", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Contact :", nullptr));
        ajout_contact->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer le contact ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Type d'\303\251tablissement", nullptr));
        ajout_type->setItemText(0, QCoreApplication::translate("MainWindow", "\303\251cole", nullptr));
        ajout_type->setItemText(1, QCoreApplication::translate("MainWindow", "Lyc\303\251e", nullptr));
        ajout_type->setItemText(2, QCoreApplication::translate("MainWindow", "Universit\303\251", nullptr));
        ajout_type->setItemText(3, QCoreApplication::translate("MainWindow", "centre de formation", nullptr));

        ajout_button->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        aff_rech->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par nom...", nullptr));
        aff_pdf->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        aff_tri->setText(QCoreApplication::translate("MainWindow", "Trier par id", nullptr));
        btn_stats->setText(QCoreApplication::translate("MainWindow", "statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "                                               Supprission d'un \303\251tablissement", nullptr));
        SuppID->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer L'ID \303\240 supprimer ", nullptr));
        SuppButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression), QCoreApplication::translate("MainWindow", "Suppression", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Contact :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Type d'\303\251tablissement:", nullptr));
        mod_type->setItemText(0, QString());
        mod_type->setItemText(1, QCoreApplication::translate("MainWindow", "\303\251cole", nullptr));
        mod_type->setItemText(2, QCoreApplication::translate("MainWindow", "Lyc\303\251e", nullptr));
        mod_type->setItemText(3, QCoreApplication::translate("MainWindow", "Universit\303\251", nullptr));
        mod_type->setItemText(4, QCoreApplication::translate("MainWindow", "Centre de formation", nullptr));

        mod_button->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        mod_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer ID \303\240 modifier ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ID-E :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModification), QCoreApplication::translate("MainWindow", "Modification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
