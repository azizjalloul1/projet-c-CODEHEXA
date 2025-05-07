/********************************************************************************
** Form generated from reading UI file 'mainwindowF.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWF_H
#define UI_MAINWINDOWF_H

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

class Ui_MainWindowF
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabAjout_2;
    QVBoxLayout *layoutAjout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *r1;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_Id;
    QLabel *label;
    QLineEdit *lineEdit_Nom;
    QLabel *label_10;
    QLineEdit *lineEdit_NumTel;
    QLabel *label_11;
    QComboBox *comboBox_TypeService_2;
    QPushButton *btnAjouter;
    QWidget *tabAffichage_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnStatistiques;
    QLineEdit *btnRechercher;
    QPushButton *btnMeilleurFournisseur;
    QPushButton *btnExporterPDF;
    QPushButton *btnEnvoyerSMS;
    QComboBox *comboBox_Tri;
    QVBoxLayout *chartLayout_2;
    QTableView *tableView_Fournisseurs;
    QWidget *tabModification_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBox_IdModif;
    QLabel *label_2;
    QLineEdit *lineEdit_NomModif;
    QLabel *label_15;
    QLineEdit *lineEdit_NumTelModif;
    QLabel *label_16;
    QComboBox *comboBox_TypeServiceModif;
    QPushButton *btnModifier;
    QWidget *tabSuppression_2;
    QVBoxLayout *layoutAjout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_12;
    QLineEdit *lineEdit_SuppID;
    QPushButton *btnSupprimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowF)
    {
        if (MainWindowF->objectName().isEmpty())
            MainWindowF->setObjectName("MainWindowF");
        MainWindowF->resize(1192, 825);
        centralwidget = new QWidget(MainWindowF);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"       QWidget {\n"
"         background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #E3F0FE, stop:1 #BBDEFB);\n"
"         font-family: Arial, sans-serif;\n"
"         font-size: 14px;\n"
"       }\n"
"\n"
"       QLineEdit {\n"
"         border: 2px solid #5c6bc0;\n"
"         border-radius: 8px;\n"
"         padding: 8px;\n"
"         background-color: #f9f9f9;\n"
"         color: #333;\n"
"         font-size: 14px;\n"
"\n"
"       }\n"
"\n"
"       QLineEdit:focus {\n"
"         border: 2px solid #3f51b5;\n"
"         background-color: #e8eaf6;\n"
"\n"
"       }\n"
"\n"
"       QPushButton {\n"
"         background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2196F3, stop:1 #1976D2);\n"
"         color: white;\n"
"         border-radius: 8px;\n"
"         padding: 12px;\n"
"         font-size: 16px;\n"
"         font-weight: bold;\n"
"         border: none;\n"
"\n"
"\n"
"       }\n"
"\n"
"       QPushButton:hover {\n"
"         background: #1976D2;\n"
"\n"
"      "
                        " }\n"
"\n"
"       QPushButton:pressed {\n"
"         background: #0D47A1;\n"
"\n"
"       }\n"
"\n"
"       QPushButton:disabled {\n"
"         background: #BBDEFB;\n"
"         color: #757575;\n"
"         ;\n"
"       }\n"
"\n"
"       QTabWidget::pane {\n"
"         border: 2px solid #3f51b5;\n"
"         border-radius: 8px;\n"
"         background: #ffffff;\n"
"       }\n"
"\n"
"       QTabBar::tab {\n"
"         background: #e3f2fd;\n"
"         padding: 10px;\n"
"         border-radius: 8px 8px 0 0;\n"
"         color: #333;\n"
"         font-weight: bold;\n"
"       }\n"
"\n"
"       QTabBar::tab:selected {\n"
"         background: #2196F3;\n"
"         color: white;\n"
"       }\n"
"       QTableView {\n"
"           border: 1px solid #5c6bc0;\n"
"           gridline-color: #5c6bc0;\n"
"           background-color: #ffffff;\n"
"           color: black;\n"
"           selection-background-color: #1976D2;\n"
"           selection-color: black; /* Texte en blanc quand s\303\251lectionn\303\251 */\n"
"   "
                        "    }\n"
"\n"
"\n"
"\n"
"       QComboBox {\n"
"         background-color: #f1f1f1;\n"
"         border: 2px solid #5c6bc0;\n"
"         border-radius: 8px;\n"
"         padding: 5px;\n"
"         font-size: 14px;\n"
"       }\n"
"\n"
"       QTableWidget {\n"
"         border: 1px solid #5c6bc0;\n"
"         gridline-color: #5c6bc0;\n"
"         background-color: #ffffff;\n"
"       }\n"
"\n"
"       QTableWidget::item {\n"
"         padding: 5px;\n"
"       }\n"
"\n"
"       QTableWidget::item:selected {\n"
"         background-color: #1976D2;\n"
"         color: black;\n"
"       }\n"
"     "));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 1171, 751));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout_2 = new QWidget();
        tabAjout_2->setObjectName("tabAjout_2");
        layoutAjout_3 = new QVBoxLayout(tabAjout_2);
        layoutAjout_3->setObjectName("layoutAjout_3");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        r1 = new QPushButton(tabAjout_2);
        r1->setObjectName("r1");
        r1->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(r1);

        label_8 = new QLabel(tabAjout_2);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 50));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 16pt;\n"
"color: rgb(0, 0, 0);\n"
"font-family: \"Arial Rounded MT\""));

        horizontalLayout_3->addWidget(label_8);


        verticalLayout_5->addLayout(horizontalLayout_3);

        label_9 = new QLabel(tabAjout_2);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(16777215, 30));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(31, 139, 231);"));

        verticalLayout_5->addWidget(label_9);

        lineEdit_Id = new QLineEdit(tabAjout_2);
        lineEdit_Id->setObjectName("lineEdit_Id");
        lineEdit_Id->setMaximumSize(QSize(16777215, 50));
        lineEdit_Id->setReadOnly(false);

        verticalLayout_5->addWidget(lineEdit_Id);

        label = new QLabel(tabAjout_2);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 235);"));

        verticalLayout_5->addWidget(label);

        lineEdit_Nom = new QLineEdit(tabAjout_2);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(lineEdit_Nom);

        label_10 = new QLabel(tabAjout_2);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(16777215, 30));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);"));

        verticalLayout_5->addWidget(label_10);

        lineEdit_NumTel = new QLineEdit(tabAjout_2);
        lineEdit_NumTel->setObjectName("lineEdit_NumTel");
        lineEdit_NumTel->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(lineEdit_NumTel);

        label_11 = new QLabel(tabAjout_2);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 30));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);"));

        verticalLayout_5->addWidget(label_11);

        comboBox_TypeService_2 = new QComboBox(tabAjout_2);
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->addItem(QString());
        comboBox_TypeService_2->setObjectName("comboBox_TypeService_2");
        comboBox_TypeService_2->setMaximumSize(QSize(16777215, 50));
        comboBox_TypeService_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(31, 141, 234);"));

        verticalLayout_5->addWidget(comboBox_TypeService_2);

        btnAjouter = new QPushButton(tabAjout_2);
        btnAjouter->setObjectName("btnAjouter");

        verticalLayout_5->addWidget(btnAjouter);


        layoutAjout_3->addLayout(verticalLayout_5);

        tabWidget->addTab(tabAjout_2, QString());
        tabAffichage_2 = new QWidget();
        tabAffichage_2->setObjectName("tabAffichage_2");
        verticalLayout_6 = new QVBoxLayout(tabAffichage_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnStatistiques = new QPushButton(tabAffichage_2);
        btnStatistiques->setObjectName("btnStatistiques");

        horizontalLayout_4->addWidget(btnStatistiques);

        btnRechercher = new QLineEdit(tabAffichage_2);
        btnRechercher->setObjectName("btnRechercher");

        horizontalLayout_4->addWidget(btnRechercher);

        btnMeilleurFournisseur = new QPushButton(tabAffichage_2);
        btnMeilleurFournisseur->setObjectName("btnMeilleurFournisseur");

        horizontalLayout_4->addWidget(btnMeilleurFournisseur);

        btnExporterPDF = new QPushButton(tabAffichage_2);
        btnExporterPDF->setObjectName("btnExporterPDF");

        horizontalLayout_4->addWidget(btnExporterPDF);

        btnEnvoyerSMS = new QPushButton(tabAffichage_2);
        btnEnvoyerSMS->setObjectName("btnEnvoyerSMS");

        horizontalLayout_4->addWidget(btnEnvoyerSMS);

        comboBox_Tri = new QComboBox(tabAffichage_2);
        comboBox_Tri->addItem(QString());
        comboBox_Tri->addItem(QString());
        comboBox_Tri->setObjectName("comboBox_Tri");
        comboBox_Tri->setStyleSheet(QString::fromUtf8("\n"
"              /* Fond d\303\251grad\303\251 bleu, coins arrondis et texte blanc */\n"
"              QComboBox#comboBox_Tri {\n"
"                background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                            stop:0 #2196F3, stop:1 #1976D2);\n"
"                color: white;\n"
"                padding: 6px 12px;\n"
"                border: none;\n"
"                border-radius: 8px;\n"
"                font-weight: bold;\n"
"              }\n"
"              /* Suppression de la bordure gauche du dropdown */\n"
"              QComboBox#comboBox_Tri::drop-down {\n"
"                subcontrol-origin: padding;\n"
"                subcontrol-position: top right;\n"
"                width: 20px;\n"
"                border-left: none;\n"
"              }\n"
"              /* Style de la liste d\303\251roulante */\n"
"              QComboBox#comboBox_Tri QAbstractItemView {\n"
"                background: white;\n"
"                color: black;\n"
"                select"
                        "ion-background-color: #1976D2;\n"
"                selection-color: white;\n"
"              }\n"
"            "));

        horizontalLayout_4->addWidget(comboBox_Tri);


        verticalLayout_6->addLayout(horizontalLayout_4);

        chartLayout_2 = new QVBoxLayout();
        chartLayout_2->setObjectName("chartLayout_2");
        tableView_Fournisseurs = new QTableView(tabAffichage_2);
        tableView_Fournisseurs->setObjectName("tableView_Fournisseurs");
        tableView_Fournisseurs->setMaximumSize(QSize(16777215, 16777215));
        tableView_Fournisseurs->setIconSize(QSize(0, 0));
        tableView_Fournisseurs->horizontalHeader()->setMinimumSectionSize(100);
        tableView_Fournisseurs->horizontalHeader()->setDefaultSectionSize(200);

        chartLayout_2->addWidget(tableView_Fournisseurs);


        verticalLayout_6->addLayout(chartLayout_2);

        tabWidget->addTab(tabAffichage_2, QString());
        tabModification_2 = new QWidget();
        tabModification_2->setObjectName("tabModification_2");
        layoutWidget = new QWidget(tabModification_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(19, 17, 1031, 661));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(16777215, 50));
        label_13->setStyleSheet(QString::fromUtf8("font-size: 16pt;\n"
"color: rgb(0, 0, 0);\n"
"font-family: \"Arial Rounded MT\""));

        verticalLayout_7->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(16777215, 30));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(31, 139, 231);"));

        verticalLayout_7->addWidget(label_14);

        comboBox_IdModif = new QComboBox(layoutWidget);
        comboBox_IdModif->setObjectName("comboBox_IdModif");
        comboBox_IdModif->setMaximumSize(QSize(16777215, 50));
        comboBox_IdModif->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);"));

        verticalLayout_7->addWidget(comboBox_IdModif);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 235);"));

        verticalLayout_7->addWidget(label_2);

        lineEdit_NomModif = new QLineEdit(layoutWidget);
        lineEdit_NomModif->setObjectName("lineEdit_NomModif");
        lineEdit_NomModif->setMaximumSize(QSize(16777215, 50));

        verticalLayout_7->addWidget(lineEdit_NomModif);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");
        label_15->setMaximumSize(QSize(16777215, 30));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);"));

        verticalLayout_7->addWidget(label_15);

        lineEdit_NumTelModif = new QLineEdit(layoutWidget);
        lineEdit_NumTelModif->setObjectName("lineEdit_NumTelModif");
        lineEdit_NumTelModif->setMaximumSize(QSize(16777215, 50));

        verticalLayout_7->addWidget(lineEdit_NumTelModif);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(16777215, 30));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);"));

        verticalLayout_7->addWidget(label_16);

        comboBox_TypeServiceModif = new QComboBox(layoutWidget);
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->addItem(QString());
        comboBox_TypeServiceModif->setObjectName("comboBox_TypeServiceModif");
        comboBox_TypeServiceModif->setMaximumSize(QSize(16777215, 50));
        comboBox_TypeServiceModif->setToolTipDuration(1);
        comboBox_TypeServiceModif->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(31, 143, 236);"));

        verticalLayout_7->addWidget(comboBox_TypeServiceModif);

        btnModifier = new QPushButton(layoutWidget);
        btnModifier->setObjectName("btnModifier");

        verticalLayout_7->addWidget(btnModifier);

        tabWidget->addTab(tabModification_2, QString());
        tabSuppression_2 = new QWidget();
        tabSuppression_2->setObjectName("tabSuppression_2");
        layoutAjout_4 = new QVBoxLayout(tabSuppression_2);
        layoutAjout_4->setObjectName("layoutAjout_4");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_12 = new QLabel(tabSuppression_2);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(31, 143, 236);\n"
""));

        verticalLayout_8->addWidget(label_12);

        lineEdit_SuppID = new QLineEdit(tabSuppression_2);
        lineEdit_SuppID->setObjectName("lineEdit_SuppID");
        lineEdit_SuppID->setMaximumSize(QSize(16777215, 50));

        verticalLayout_8->addWidget(lineEdit_SuppID);

        btnSupprimer = new QPushButton(tabSuppression_2);
        btnSupprimer->setObjectName("btnSupprimer");

        verticalLayout_8->addWidget(btnSupprimer);


        layoutAjout_4->addLayout(verticalLayout_8);

        tabWidget->addTab(tabSuppression_2, QString());
        MainWindowF->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowF);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1192, 26));
        MainWindowF->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowF);
        statusbar->setObjectName("statusbar");
        MainWindowF->setStatusBar(statusbar);

        retranslateUi(MainWindowF);

        tabWidget->setCurrentIndex(1);
        comboBox_IdModif->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindowF);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowF)
    {
        MainWindowF->setWindowTitle(QCoreApplication::translate("MainWindowF", "MainWindow", nullptr));
        r1->setText(QCoreApplication::translate("MainWindowF", "retour", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowF", "                                                    L'ajout D'un Fournisseur", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowF", "ID", nullptr));
        label->setText(QCoreApplication::translate("MainWindowF", "Nom", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindowF", "num de t\303\251lephone", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindowF", "type de service", nullptr));
        comboBox_TypeService_2->setItemText(0, QString());
        comboBox_TypeService_2->setItemText(1, QCoreApplication::translate("MainWindowF", "Transporteur", nullptr));
        comboBox_TypeService_2->setItemText(2, QCoreApplication::translate("MainWindowF", "logistique", nullptr));
        comboBox_TypeService_2->setItemText(3, QCoreApplication::translate("MainWindowF", "informatique", nullptr));
        comboBox_TypeService_2->setItemText(4, QCoreApplication::translate("MainWindowF", " maintenance et r\303\251paration", nullptr));
        comboBox_TypeService_2->setItemText(5, QCoreApplication::translate("MainWindowF", "s\303\251curit\303\251", nullptr));
        comboBox_TypeService_2->setItemText(6, QCoreApplication::translate("MainWindowF", "Ressource Humaine et formation", nullptr));

        btnAjouter->setText(QCoreApplication::translate("MainWindowF", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout_2), QCoreApplication::translate("MainWindowF", "Ajout", nullptr));
        btnStatistiques->setText(QCoreApplication::translate("MainWindowF", "statistique", nullptr));
        btnRechercher->setPlaceholderText(QCoreApplication::translate("MainWindowF", "Rechercher par nom...", nullptr));
        btnMeilleurFournisseur->setText(QCoreApplication::translate("MainWindowF", "meuilleur fournisseur", nullptr));
        btnExporterPDF->setText(QCoreApplication::translate("MainWindowF", "Exporter en PDF", nullptr));
        btnEnvoyerSMS->setText(QCoreApplication::translate("MainWindowF", "ENVOYER", nullptr));
        comboBox_Tri->setItemText(0, QCoreApplication::translate("MainWindowF", "tri croissant", nullptr));
        comboBox_Tri->setItemText(1, QCoreApplication::translate("MainWindowF", "tri d\303\251croissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabAffichage_2), QCoreApplication::translate("MainWindowF", "Affichage", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindowF", "                                            Modification D'un Fournisseur", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindowF", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowF", "Nom", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindowF", "num de t\303\251lephone", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindowF", "type de service", nullptr));
        comboBox_TypeServiceModif->setItemText(0, QString());
        comboBox_TypeServiceModif->setItemText(1, QCoreApplication::translate("MainWindowF", "Transporteur", nullptr));
        comboBox_TypeServiceModif->setItemText(2, QCoreApplication::translate("MainWindowF", "logistique", nullptr));
        comboBox_TypeServiceModif->setItemText(3, QCoreApplication::translate("MainWindowF", "informatique", nullptr));
        comboBox_TypeServiceModif->setItemText(4, QCoreApplication::translate("MainWindowF", "s\303\251curit\303\251", nullptr));
        comboBox_TypeServiceModif->setItemText(5, QCoreApplication::translate("MainWindowF", " maintenance et r\303\251paration", nullptr));
        comboBox_TypeServiceModif->setItemText(6, QCoreApplication::translate("MainWindowF", "Ressource Humaine et formation", nullptr));

        btnModifier->setText(QCoreApplication::translate("MainWindowF", "modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModification_2), QCoreApplication::translate("MainWindowF", "Modification", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowF", "ID", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindowF", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression_2), QCoreApplication::translate("MainWindowF", "Suppression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowF: public Ui_MainWindowF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWF_H
