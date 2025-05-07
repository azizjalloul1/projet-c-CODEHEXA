/********************************************************************************
** Form generated from reading UI file 'mainwindowstock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWSTOCK_H
#define UI_MAINWINDOWSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowstock
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *affiche;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *r2;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *ref;
    QLabel *label_2;
    QLineEdit *prix;
    QLabel *label_4;
    QLineEdit *type;
    QLabel *label_3;
    CustomComboBox *idfournisseur;
    QLabel *label_5;
    QLineEdit *quantite;
    QPushButton *addb;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *recherche;
    QPushButton *exportButton;
    QPushButton *triButton;
    QTableWidget *table;
    QVBoxLayout *chartLayout;
    QFrame *frame;
    QWidget *tabSuppression;
    QVBoxLayout *layoutAjout1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLineEdit *suppref;
    QPushButton *suppb;
    QWidget *tabModification;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLineEdit *prixmod;
    QLabel *label_13;
    QLineEdit *typemod;
    QLabel *label_9;
    QLineEdit *quantitemod;
    QPushButton *modb;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *refmod;
    QPushButton *valider;
    QWidget *tabHistorique;
    QVBoxLayout *verticalLayoutHistorique;
    QLabel *labelHistorique;
    QTableWidget *tableHistorique;
    QHBoxLayout *historiqueButtonLayout;
    QPushButton *textbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowstock)
    {
        if (MainWindowstock->objectName().isEmpty())
            MainWindowstock->setObjectName("MainWindowstock");
        MainWindowstock->resize(968, 823);
        centralwidget = new QWidget(MainWindowstock);
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
        affiche = new QTabWidget(centralwidget);
        affiche->setObjectName("affiche");
        affiche->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
        layoutAjout = new QVBoxLayout(tabAjout);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout1 = new QVBoxLayout();
        verticalLayout1->setObjectName("verticalLayout1");
        verticalLayout1->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        r2 = new QPushButton(tabAjout);
        r2->setObjectName("r2");
        r2->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_2->addWidget(r2);

        label_6 = new QLabel(tabAjout);
        label_6->setObjectName("label_6");
        label_6->setEnabled(true);
        label_6->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("\n"
"                font-size: 16pt;\n"
"                font-weight: bold;\n"
"             "));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_6);


        verticalLayout1->addLayout(horizontalLayout_2);

        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout1->addWidget(label);

        ref = new QLineEdit(tabAjout);
        ref->setObjectName("ref");
        ref->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(ref);

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 50));
        label_2->setFont(font1);

        verticalLayout1->addWidget(label_2);

        prix = new QLineEdit(tabAjout);
        prix->setObjectName("prix");
        prix->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(prix);

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 50));
        label_4->setFont(font1);

        verticalLayout1->addWidget(label_4);

        type = new QLineEdit(tabAjout);
        type->setObjectName("type");
        type->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(type);

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 50));
        label_3->setFont(font1);

        verticalLayout1->addWidget(label_3);

        idfournisseur = new CustomComboBox(tabAjout);
        idfournisseur->setObjectName("idfournisseur");

        verticalLayout1->addWidget(idfournisseur);

        label_5 = new QLabel(tabAjout);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 50));
        label_5->setFont(font1);

        verticalLayout1->addWidget(label_5);

        quantite = new QLineEdit(tabAjout);
        quantite->setObjectName("quantite");
        quantite->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(quantite);

        addb = new QPushButton(tabAjout);
        addb->setObjectName("addb");
        addb->setMaximumSize(QSize(16777215, 50));

        verticalLayout1->addWidget(addb);


        layoutAjout->addLayout(verticalLayout1);

        affiche->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout2 = new QVBoxLayout(tabAffichage);
        verticalLayout2->setObjectName("verticalLayout2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        recherche = new QLineEdit(tabAffichage);
        recherche->setObjectName("recherche");

        horizontalLayout->addWidget(recherche);

        exportButton = new QPushButton(tabAffichage);
        exportButton->setObjectName("exportButton");

        horizontalLayout->addWidget(exportButton);

        triButton = new QPushButton(tabAffichage);
        triButton->setObjectName("triButton");

        horizontalLayout->addWidget(triButton);


        verticalLayout2->addLayout(horizontalLayout);

        table = new QTableWidget(tabAffichage);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table->setObjectName("table");
        table->setMaximumSize(QSize(16777215, 400));

        verticalLayout2->addWidget(table);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");
        frame = new QFrame(tabAffichage);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        chartLayout->addWidget(frame);


        verticalLayout2->addLayout(chartLayout);

        affiche->addTab(tabAffichage, QString());
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
        label_7->setStyleSheet(QString::fromUtf8("\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"\n"
""));

        verticalLayout_2->addWidget(label_7);

        suppref = new QLineEdit(tabSuppression);
        suppref->setObjectName("suppref");
        suppref->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(suppref);

        suppb = new QPushButton(tabSuppression);
        suppb->setObjectName("suppb");

        verticalLayout_2->addWidget(suppb);


        layoutAjout1->addLayout(verticalLayout_2);

        affiche->addTab(tabSuppression, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
        verticalLayoutWidget = new QWidget(tabModification);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 270, 911, 421));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setFont(font1);

        verticalLayout_3->addWidget(label_12);

        prixmod = new QLineEdit(verticalLayoutWidget);
        prixmod->setObjectName("prixmod");
        prixmod->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(prixmod);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(16777215, 30));
        label_13->setFont(font1);

        verticalLayout_3->addWidget(label_13);

        typemod = new QLineEdit(verticalLayoutWidget);
        typemod->setObjectName("typemod");
        typemod->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(typemod);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(16777215, 30));
        label_9->setFont(font1);

        verticalLayout_3->addWidget(label_9);

        quantitemod = new QLineEdit(verticalLayoutWidget);
        quantitemod->setObjectName("quantitemod");
        quantitemod->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(quantitemod);

        modb = new QPushButton(verticalLayoutWidget);
        modb->setObjectName("modb");

        verticalLayout_3->addWidget(modb);

        verticalLayoutWidget_2 = new QWidget(tabModification);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 110, 911, 100));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(16777215, 50));
        label_10->setFont(font1);

        verticalLayout_4->addWidget(label_10);

        verticalLayoutWidget_3 = new QWidget(tabModification);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 911, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget_3);
        textEdit->setObjectName("textEdit");

        verticalLayout_5->addWidget(textEdit);

        horizontalLayoutWidget = new QWidget(tabModification);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 911, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        refmod = new QLineEdit(horizontalLayoutWidget);
        refmod->setObjectName("refmod");
        refmod->setMaximumSize(QSize(800, 50));

        horizontalLayout_3->addWidget(refmod);

        valider = new QPushButton(horizontalLayoutWidget);
        valider->setObjectName("valider");
        valider->setMaximumSize(QSize(200, 60));

        horizontalLayout_3->addWidget(valider);

        affiche->addTab(tabModification, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName("tabHistorique");
        verticalLayoutHistorique = new QVBoxLayout(tabHistorique);
        verticalLayoutHistorique->setObjectName("verticalLayoutHistorique");
        labelHistorique = new QLabel(tabHistorique);
        labelHistorique->setObjectName("labelHistorique");
        labelHistorique->setFont(font1);
        labelHistorique->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutHistorique->addWidget(labelHistorique);

        tableHistorique = new QTableWidget(tabHistorique);
        if (tableHistorique->columnCount() < 5)
            tableHistorique->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        tableHistorique->setObjectName("tableHistorique");
        tableHistorique->setMaximumSize(QSize(16777215, 600));

        verticalLayoutHistorique->addWidget(tableHistorique);

        historiqueButtonLayout = new QHBoxLayout();
        historiqueButtonLayout->setObjectName("historiqueButtonLayout");
        textbutton = new QPushButton(tabHistorique);
        textbutton->setObjectName("textbutton");

        historiqueButtonLayout->addWidget(textbutton);


        verticalLayoutHistorique->addLayout(historiqueButtonLayout);

        affiche->addTab(tabHistorique, QString());

        verticalLayout->addWidget(affiche);

        MainWindowstock->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowstock);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 968, 26));
        MainWindowstock->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowstock);
        statusbar->setObjectName("statusbar");
        MainWindowstock->setStatusBar(statusbar);

        retranslateUi(MainWindowstock);

        affiche->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowstock);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowstock)
    {
        MainWindowstock->setWindowTitle(QCoreApplication::translate("MainWindowstock", "MainWindow", nullptr));
        r2->setText(QCoreApplication::translate("MainWindowstock", "retour", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowstock", "Ajouter un element au stock", nullptr));
        label->setText(QCoreApplication::translate("MainWindowstock", "Ref\303\251rence d'element :", nullptr));
        ref->setText(QString());
        ref->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "Ins\303\251rer la Ref d'element a stocker", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowstock", "prix:", nullptr));
        prix->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "inserer le prix ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowstock", "Type :", nullptr));
        type->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "donner le type ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowstock", "id_fournisseur", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowstock", "Qantit\303\251 :", nullptr));
        quantite->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "Ins\303\250rer la quantit\303\251", nullptr));
        addb->setText(QCoreApplication::translate("MainWindowstock", "Ajouter", nullptr));
        affiche->setTabText(affiche->indexOf(tabAjout), QCoreApplication::translate("MainWindowstock", "Ajout", nullptr));
        recherche->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "Rechercher par REF d'element", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindowstock", "Exporter en PDF", nullptr));
        triButton->setText(QCoreApplication::translate("MainWindowstock", "Trier par quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindowstock", "Ref", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindowstock", "prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindowstock", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindowstock", "Quantit\303\251", nullptr));
        affiche->setTabText(affiche->indexOf(tabAffichage), QCoreApplication::translate("MainWindowstock", "Affichage", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowstock", "Suppression d'un element :", nullptr));
        suppref->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "Ins\303\251rer La reference d'element \303\240 supprimer ", nullptr));
        suppb->setText(QCoreApplication::translate("MainWindowstock", "Supprimer", nullptr));
        affiche->setTabText(affiche->indexOf(tabSuppression), QCoreApplication::translate("MainWindowstock", "Suppression", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowstock", "prix:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindowstock", "Type :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowstock", "Qantit\303\251 :", nullptr));
        modb->setText(QCoreApplication::translate("MainWindowstock", "Modifier", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindowstock", "Ref\303\251rence d'element :", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindowstock", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:700;\">Modifier le stock</span></p></body></html>", nullptr));
        refmod->setPlaceholderText(QCoreApplication::translate("MainWindowstock", "Ins\303\251rer la reference d'element  a modifier ", nullptr));
        valider->setText(QCoreApplication::translate("MainWindowstock", "valider", nullptr));
        affiche->setTabText(affiche->indexOf(tabModification), QCoreApplication::translate("MainWindowstock", "Modification", nullptr));
        labelHistorique->setText(QCoreApplication::translate("MainWindowstock", "Historique des commandes ", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableHistorique->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindowstock", "Ref", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableHistorique->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindowstock", "idfournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableHistorique->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindowstock", "Quantite", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableHistorique->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindowstock", "Utilisateur", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableHistorique->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindowstock", "prix totale", nullptr));
        textbutton->setText(QCoreApplication::translate("MainWindowstock", "transfer en fichier text ", nullptr));
        affiche->setTabText(affiche->indexOf(tabHistorique), QCoreApplication::translate("MainWindowstock", "Historique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowstock: public Ui_MainWindowstock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSTOCK_H
