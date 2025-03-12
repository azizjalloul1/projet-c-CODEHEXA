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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout1;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *idInput;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *MDPInput;
    QPushButton *valider;
    QLabel *validation;
    QLabel *label_8;
    QLineEdit *email;
    QLabel *label_3;
    QLineEdit *nomInput;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QSpinBox *spinBox;
    QPushButton *addButton;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *exportButton;
    QPushButton *triButton;
    QTableWidget *tableWidget;
    QVBoxLayout *chartLayout;
    QWidget *tabSuppression;
    QVBoxLayout *layoutAjout1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLineEdit *SuppID;
    QPushButton *SuppButton;
    QWidget *tabModification;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLineEdit *mod_mail;
    QLabel *label_11;
    QLineEdit *mod_nom;
    QLabel *label_12;
    QSpinBox *mod_salaire;
    QPushButton *mod_bouton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *mod_id;
    QPushButton *id_valide;
    QLabel *label_10;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(998, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"     QWidget {\n"
"       background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #E3F0FE, stop:1 #BBDEFB);\n"
"       font-family: Arial, sans-serif;\n"
"       font-size: 14px;\n"
"     }\n"
"\n"
"     QLineEdit {\n"
"       border: 2px solid #5c6bc0;\n"
"       border-radius: 8px;\n"
"       padding: 8px;\n"
"       background-color: #f9f9f9;\n"
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
"       transition: all 0.3s ease-in-out;\n"
"       box-shadow: "
                        "2px 2px 5px rgba(0, 0, 0, 0.2);\n"
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
"       border: 2px solid #5c6bc0;\n"
"       border-radius: 8px;"
                        "\n"
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
        tabAjout->setMaximumSize(QSize(16777215, 16777215));
        layoutAjout = new QVBoxLayout(tabAjout);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout1 = new QVBoxLayout();
        verticalLayout1->setObjectName("verticalLayout1");
        verticalLayout1->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_6 = new QLabel(tabAjout);
        label_6->setObjectName("label_6");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font.setPointSize(16);
        font.setBold(false);
        font.setKerning(false);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font-size: 16pt;\n"
"font-family: \"Arial Rounded MT\";\n"
"               \n"
"             "));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout1->addWidget(label_6);

        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));
        label->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout1->addWidget(label);

        idInput = new QLineEdit(tabAjout);
        idInput->setObjectName("idInput");
        idInput->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(idInput);

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout1->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        MDPInput = new QLineEdit(tabAjout);
        MDPInput->setObjectName("MDPInput");
        MDPInput->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(MDPInput);

        valider = new QPushButton(tabAjout);
        valider->setObjectName("valider");

        horizontalLayout_2->addWidget(valider);

        validation = new QLabel(tabAjout);
        validation->setObjectName("validation");
        validation->setMaximumSize(QSize(1000, 50));

        horizontalLayout_2->addWidget(validation);


        verticalLayout1->addLayout(horizontalLayout_2);

        label_8 = new QLabel(tabAjout);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout1->addWidget(label_8);

        email = new QLineEdit(tabAjout);
        email->setObjectName("email");
        email->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(email);

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";\n"
""));

        verticalLayout1->addWidget(label_3);

        nomInput = new QLineEdit(tabAjout);
        nomInput->setObjectName("nomInput");
        nomInput->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(nomInput);

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout1->addWidget(label_4);

        comboBox = new QComboBox(tabAjout);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMaximumSize(QSize(16777215, 50));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));

        verticalLayout1->addWidget(comboBox);

        label_5 = new QLabel(tabAjout);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 30));
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout1->addWidget(label_5);

        spinBox = new QSpinBox(tabAjout);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximumSize(QSize(16777215, 50));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));
        spinBox->setMaximum(9999999);
        spinBox->setSingleStep(50);

        verticalLayout1->addWidget(spinBox);

        addButton = new QPushButton(tabAjout);
        addButton->setObjectName("addButton");

        verticalLayout1->addWidget(addButton);


        layoutAjout->addLayout(verticalLayout1);

        tabWidget->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout2 = new QVBoxLayout(tabAffichage);
        verticalLayout2->setObjectName("verticalLayout2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        searchLineEdit = new QLineEdit(tabAffichage);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        exportButton = new QPushButton(tabAffichage);
        exportButton->setObjectName("exportButton");

        horizontalLayout->addWidget(exportButton);

        triButton = new QPushButton(tabAffichage);
        triButton->setObjectName("triButton");

        horizontalLayout->addWidget(triButton);


        verticalLayout2->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(tabAffichage);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");

        verticalLayout2->addWidget(tableWidget);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");

        verticalLayout2->addLayout(chartLayout);

        tabWidget->addTab(tabAffichage, QString());
        tabSuppression = new QWidget();
        tabSuppression->setObjectName("tabSuppression");
        layoutAjout1 = new QVBoxLayout(tabSuppression);
        layoutAjout1->setObjectName("layoutAjout1");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_7 = new QLabel(tabSuppression);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setStyleSheet(QString::fromUtf8(" font-size: 16pt;\n"
"   font-family: \"Arial Rounded MT\";\n"
"  \n"
"              \n"
"             "));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        SuppID = new QLineEdit(tabSuppression);
        SuppID->setObjectName("SuppID");
        SuppID->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(SuppID);

        SuppButton = new QPushButton(tabSuppression);
        SuppButton->setObjectName("SuppButton");

        verticalLayout_2->addWidget(SuppButton);


        layoutAjout1->addLayout(verticalLayout_2);

        tabWidget->addTab(tabSuppression, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
        tabModification->setEnabled(true);
        tabModification->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(tabModification);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 220, 951, 431));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(16777215, 30));
        label_9->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout_3->addWidget(label_9);

        mod_mail = new QLineEdit(verticalLayoutWidget);
        mod_mail->setObjectName("mod_mail");
        mod_mail->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(mod_mail);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 30));
        label_11->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout_3->addWidget(label_11);

        mod_nom = new QLineEdit(verticalLayoutWidget);
        mod_nom->setObjectName("mod_nom");
        mod_nom->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(mod_nom);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));

        verticalLayout_3->addWidget(label_12);

        mod_salaire = new QSpinBox(verticalLayoutWidget);
        mod_salaire->setObjectName("mod_salaire");
        mod_salaire->setMaximumSize(QSize(16777215, 50));
        mod_salaire->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));
        mod_salaire->setMaximum(99999999);
        mod_salaire->setSingleStep(50);
        mod_salaire->setValue(0);

        verticalLayout_3->addWidget(mod_salaire);

        mod_bouton = new QPushButton(verticalLayoutWidget);
        mod_bouton->setObjectName("mod_bouton");

        verticalLayout_3->addWidget(mod_bouton);

        horizontalLayoutWidget = new QWidget(tabModification);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 110, 951, 91));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        mod_id = new QLineEdit(horizontalLayoutWidget);
        mod_id->setObjectName("mod_id");
        mod_id->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_3->addWidget(mod_id);

        id_valide = new QPushButton(horizontalLayoutWidget);
        id_valide->setObjectName("id_valide");

        horizontalLayout_3->addWidget(id_valide);

        label_10 = new QLabel(tabModification);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 70, 951, 30));
        label_10->setStyleSheet(QString::fromUtf8("font-family: \"Arial Rounded MT\";"));
        label_13 = new QLabel(tabModification);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 10, 951, 50));
        label_13->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font2.setPointSize(16);
        font2.setBold(true);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("\n"
"    font-size: 16pt;\n"
"   font-family: \"Arial Rounded MT\";\n"
"    \n"
"    \n"
""));
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget->addTab(tabModification, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 998, 26));
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
        label_6->setText(QCoreApplication::translate("MainWindow", "L'ajout d'un employ\303\251e", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        idInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer l'identifiant ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        MDPInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer le mot de passe ", nullptr));
        valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        validation->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "E-mail de v\303\251rification :", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer le E-mail de v\303\251rification", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        nomInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer le nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Role :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Responsable", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Salaire :", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par nom...", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        triButton->setText(QCoreApplication::translate("MainWindow", "Trier par Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "ROLE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "SALAIRE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Suppression d'un empoly\303\251e", nullptr));
        SuppID->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer L'ID \303\240 supprimer ", nullptr));
        SuppButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression), QCoreApplication::translate("MainWindow", "Suppression", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "E-mail :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Salaire :", nullptr));
        mod_bouton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        mod_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer ID \303\240 modifier ", nullptr));
        id_valide->setText(QCoreApplication::translate("MainWindow", "valide", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ID \303\240 modifier :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Modification d'un empoly\303\251e", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModification), QCoreApplication::translate("MainWindow", "Modification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
