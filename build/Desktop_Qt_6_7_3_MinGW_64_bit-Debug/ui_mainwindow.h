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
<<<<<<< HEAD
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
=======
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
>>>>>>> origin/gestionetablissement
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
<<<<<<< HEAD
#include <QtWidgets/QListWidget>
=======
>>>>>>> origin/gestionetablissement
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
<<<<<<< HEAD
#include <QtWidgets/QTableWidget>
=======
#include <QtWidgets/QTableView>
>>>>>>> origin/gestionetablissement
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
<<<<<<< HEAD
    QGridLayout *gridLayout;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label;
    QComboBox *marque;
    QLabel *label_2;
    QComboBox *type;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *matricule1;
    QLabel *label_13;
    QLineEdit *matricule2;
    QLabel *label_3;
    QComboBox *statut;
    QLabel *label_4;
    QLineEdit *vcoffre;
    QLabel *label_5;
    QLineEdit *idtransporteur;
    QPushButton *addButton;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *exportButton;
    QPushButton *triButton;
    QPushButton *btnSimulateGPS;
    QPushButton *btnViewLatestGPS;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QQuickWidget *quickWidget;
    QFrame *chartContainer;
    QVBoxLayout *chartLayout;
    QWidget *tabSuppression;
    QVBoxLayout *layoutsupp;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *matricule;
    QPushButton *Supp_Button;
    QWidget *tabModification;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_15;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *matricule1_2;
    QLabel *label_14;
    QLineEdit *matricule2_2;
    QPushButton *matricule_valider;
    QLabel *label_9;
    QComboBox *marque_2;
    QLabel *label_11;
    QComboBox *type_2;
    QLabel *label_12;
    QComboBox *statut_2;
    QLabel *label_16;
    QLineEdit *vcoffre_2;
    QLabel *label_17;
    QLineEdit *idtransporteur_2;
    QPushButton *mod_button;
    QWidget *tabDiagnostique;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *symptomSearchLineEdit;
    QListWidget *symptomListWidget;
    QTableWidget *tabafficheerreur;
    QPushButton *btnNextSolution;
=======
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
>>>>>>> origin/gestionetablissement

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
<<<<<<< HEAD
        MainWindow->resize(982, 861);
=======
        MainWindow->resize(933, 784);
>>>>>>> origin/gestionetablissement
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"     QWidget {\n"
<<<<<<< HEAD
"       background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #E3F0FE, stop:1 #BBDEFB);\n"
=======
"     background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(227, 240, 254), stop:1 rgb(187, 222, 251));\n"
"\n"
>>>>>>> origin/gestionetablissement
"       font-family: Arial, sans-serif;\n"
"       font-size: 14px;\n"
"     }\n"
"\n"
"     QLineEdit {\n"
<<<<<<< HEAD
"       border: 2px solid #5c6bc0;\n"
"       border-radius: 8px;\n"
"       padding: 8px;\n"
"       background-color: #f9f9f9;\n"
=======
"     border: 2px solid rgb(92, 107, 192);\n"
"\n"
"       border-radius: 8px;\n"
"       padding: 8px;\n"
"       background-color: rgb(249, 249, 249);\n"
"\n"
>>>>>>> origin/gestionetablissement
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
<<<<<<< HEAD
"       transition: all 0.3s ease-in-out;\n"
"       box-shadow: "
                        "2px 2px 5px rgba(0, 0, 0, 0.2);\n"
=======
"       tra"
                        "nsition: all 0.3s ease-in-out;\n"
"       box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
>>>>>>> origin/gestionetablissement
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
<<<<<<< HEAD
"       border: 2px solid #5c6bc0;\n"
"       border-radius: 8px;"
                        "\n"
=======
"       bor"
                        "der: 2px solid #5c6bc0;\n"
"       border-radius: 8px;\n"
>>>>>>> origin/gestionetablissement
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
<<<<<<< HEAD
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        statusbar = new QStatusBar(centralwidget);
        statusbar->setObjectName("statusbar");

        gridLayout->addWidget(statusbar, 1, 0, 1, 1);

        menubar = new QMenuBar(centralwidget);
        menubar->setObjectName("menubar");

        gridLayout->addWidget(menubar, 0, 0, 1, 1);

=======
        verticalLayout1 = new QVBoxLayout(centralwidget);
        verticalLayout1->setObjectName("verticalLayout1");
>>>>>>> origin/gestionetablissement
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
<<<<<<< HEAD
        layoutAjout = new QVBoxLayout(tabAjout);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
=======
        layoutAjout1 = new QVBoxLayout(tabAjout);
        layoutAjout1->setObjectName("layoutAjout1");
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName("verticalLayout_1");
        verticalLayout_1->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
>>>>>>> origin/gestionetablissement
        label_6 = new QLabel(tabAjout);
        label_6->setObjectName("label_6");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        font.setBold(true);
        label_6->setFont(font);
<<<<<<< HEAD
        label_6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
=======
>>>>>>> origin/gestionetablissement
        label_6->setStyleSheet(QString::fromUtf8("\n"
"                font-size: 16pt;\n"
"                font-weight: bold;\n"
"             "));
<<<<<<< HEAD
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_6);
=======

        verticalLayout_1->addWidget(label_6);
>>>>>>> origin/gestionetablissement

        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));

<<<<<<< HEAD
        verticalLayout->addWidget(label);

        marque = new QComboBox(tabAjout);
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->addItem(QString());
        marque->setObjectName("marque");
        marque->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(marque);
=======
        verticalLayout_1->addWidget(label);

        ajout_id = new QLineEdit(tabAjout);
        ajout_id->setObjectName("ajout_id");
        ajout_id->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_id);
>>>>>>> origin/gestionetablissement

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        label_2->setFont(font1);

<<<<<<< HEAD
        verticalLayout->addWidget(label_2);

        type = new QComboBox(tabAjout);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(type);
=======
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
>>>>>>> origin/gestionetablissement

        label_8 = new QLabel(tabAjout);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 30));

<<<<<<< HEAD
        verticalLayout->addWidget(label_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        matricule1 = new QLineEdit(tabAjout);
        matricule1->setObjectName("matricule1");
        matricule1->setMaximumSize(QSize(300, 50));

        horizontalLayout_5->addWidget(matricule1);

        label_13 = new QLabel(tabAjout);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(100, 16777215));
        label_13->setStyleSheet(QString::fromUtf8(" font-size: 12pt;"));
        label_13->setLineWidth(3);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_13);

        matricule2 = new QLineEdit(tabAjout);
        matricule2->setObjectName("matricule2");
        matricule2->setMaximumSize(QSize(300, 50));

        horizontalLayout_5->addWidget(matricule2);


        verticalLayout->addLayout(horizontalLayout_5);
=======
        verticalLayout_1->addWidget(label_8);

        ajout_adresse = new QLineEdit(tabAjout);
        ajout_adresse->setObjectName("ajout_adresse");
        ajout_adresse->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_adresse);
>>>>>>> origin/gestionetablissement

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));

<<<<<<< HEAD
        verticalLayout->addWidget(label_3);

        statut = new QComboBox(tabAjout);
        statut->addItem(QString());
        statut->addItem(QString());
        statut->addItem(QString());
        statut->addItem(QString());
        statut->setObjectName("statut");
        statut->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(statut);
=======
        verticalLayout_1->addWidget(label_3);

        ajout_contact = new QLineEdit(tabAjout);
        ajout_contact->setObjectName("ajout_contact");
        ajout_contact->setMaximumSize(QSize(16777215, 50));

        verticalLayout_1->addWidget(ajout_contact);
>>>>>>> origin/gestionetablissement

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 30));

<<<<<<< HEAD
        verticalLayout->addWidget(label_4);

        vcoffre = new QLineEdit(tabAjout);
        vcoffre->setObjectName("vcoffre");
        vcoffre->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(vcoffre);

        label_5 = new QLabel(tabAjout);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_5);

        idtransporteur = new QLineEdit(tabAjout);
        idtransporteur->setObjectName("idtransporteur");
        idtransporteur->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(idtransporteur);

        addButton = new QPushButton(tabAjout);
        addButton->setObjectName("addButton");
        addButton->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(addButton);


        layoutAjout->addLayout(verticalLayout);
=======
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
>>>>>>> origin/gestionetablissement

        tabWidget->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
<<<<<<< HEAD
        verticalLayout1 = new QVBoxLayout(tabAffichage);
        verticalLayout1->setObjectName("verticalLayout1");
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

        btnSimulateGPS = new QPushButton(tabAffichage);
        btnSimulateGPS->setObjectName("btnSimulateGPS");

        horizontalLayout->addWidget(btnSimulateGPS);

        btnViewLatestGPS = new QPushButton(tabAffichage);
        btnViewLatestGPS->setObjectName("btnViewLatestGPS");

        horizontalLayout->addWidget(btnViewLatestGPS);


        verticalLayout1->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tableWidget = new QTableWidget(tabAffichage);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setDefaultSectionSize(152);

        horizontalLayout_4->addWidget(tableWidget);

        quickWidget = new QQuickWidget(tabAffichage);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setMinimumSize(QSize(400, 0));
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);

        horizontalLayout_4->addWidget(quickWidget);


        verticalLayout1->addLayout(horizontalLayout_4);

        chartContainer = new QFrame(tabAffichage);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setMinimumSize(QSize(0, 250));
        chartContainer->setFrameShape(QFrame::Shape::StyledPanel);
        chartContainer->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout1->addWidget(chartContainer);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");

        verticalLayout1->addLayout(chartLayout);
=======
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
>>>>>>> origin/gestionetablissement

        tabWidget->addTab(tabAffichage, QString());
        tabSuppression = new QWidget();
        tabSuppression->setObjectName("tabSuppression");
<<<<<<< HEAD
        layoutsupp = new QVBoxLayout(tabSuppression);
        layoutsupp->setObjectName("layoutsupp");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
=======
        layoutAjout = new QVBoxLayout(tabSuppression);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
>>>>>>> origin/gestionetablissement
        label_7 = new QLabel(tabSuppression);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setStyleSheet(QString::fromUtf8("\n"
<<<<<<< HEAD
"              font-size: 16pt;\n"
"              font-weight: bold;\n"
"              "));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        matricule = new QLineEdit(tabSuppression);
        matricule->setObjectName("matricule");
        matricule->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(matricule);


        verticalLayout_2->addLayout(horizontalLayout_2);


        layoutsupp->addLayout(verticalLayout_2);

        Supp_Button = new QPushButton(tabSuppression);
        Supp_Button->setObjectName("Supp_Button");

        layoutsupp->addWidget(Supp_Button);
=======
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
>>>>>>> origin/gestionetablissement

        tabWidget->addTab(tabSuppression, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
<<<<<<< HEAD
        verticalLayout_3 = new QVBoxLayout(tabModification);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_15 = new QLabel(tabModification);
        label_15->setObjectName("label_15");
        label_15->setFont(font);
        label_15->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_15->setStyleSheet(QString::fromUtf8("\n"
"                font-size: 16pt;\n"
"                font-weight: bold;\n"
"             "));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_15);

        label_10 = new QLabel(tabModification);
        label_10->setObjectName("label_10");

        verticalLayout_3->addWidget(label_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        matricule1_2 = new QLineEdit(tabModification);
        matricule1_2->setObjectName("matricule1_2");
        matricule1_2->setMaximumSize(QSize(300, 50));

        horizontalLayout_6->addWidget(matricule1_2);

        label_14 = new QLabel(tabModification);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setStyleSheet(QString::fromUtf8(" font-size: 12pt;"));
        label_14->setLineWidth(3);
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_14);

        matricule2_2 = new QLineEdit(tabModification);
        matricule2_2->setObjectName("matricule2_2");
        matricule2_2->setMaximumSize(QSize(300, 50));

        horizontalLayout_6->addWidget(matricule2_2);

        matricule_valider = new QPushButton(tabModification);
        matricule_valider->setObjectName("matricule_valider");
        matricule_valider->setMinimumSize(QSize(0, 50));
        matricule_valider->setMaximumSize(QSize(1000, 16777215));

        horizontalLayout_6->addWidget(matricule_valider);


        verticalLayout_3->addLayout(horizontalLayout_6);

        label_9 = new QLabel(tabModification);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_9);

        marque_2 = new QComboBox(tabModification);
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->addItem(QString());
        marque_2->setObjectName("marque_2");
        marque_2->setMinimumSize(QSize(0, 50));
        marque_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(marque_2);

        label_11 = new QLabel(tabModification);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_11);

        type_2 = new QComboBox(tabModification);
        type_2->addItem(QString());
        type_2->addItem(QString());
        type_2->addItem(QString());
        type_2->addItem(QString());
        type_2->setObjectName("type_2");
        type_2->setMinimumSize(QSize(0, 50));
        type_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(type_2);

        label_12 = new QLabel(tabModification);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_12);

        statut_2 = new QComboBox(tabModification);
        statut_2->addItem(QString());
        statut_2->addItem(QString());
        statut_2->addItem(QString());
        statut_2->setObjectName("statut_2");
        statut_2->setMinimumSize(QSize(0, 50));
        statut_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(statut_2);

        label_16 = new QLabel(tabModification);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_16);

        vcoffre_2 = new QLineEdit(tabModification);
        vcoffre_2->setObjectName("vcoffre_2");
        vcoffre_2->setMinimumSize(QSize(0, 50));
        vcoffre_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(vcoffre_2);

        label_17 = new QLabel(tabModification);
        label_17->setObjectName("label_17");
        label_17->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_17);

        idtransporteur_2 = new QLineEdit(tabModification);
        idtransporteur_2->setObjectName("idtransporteur_2");
        idtransporteur_2->setMinimumSize(QSize(0, 50));
        idtransporteur_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(idtransporteur_2);

        mod_button = new QPushButton(tabModification);
        mod_button->setObjectName("mod_button");
        mod_button->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(mod_button);

        tabWidget->addTab(tabModification, QString());
        tabDiagnostique = new QWidget();
        tabDiagnostique->setObjectName("tabDiagnostique");
        verticalLayout_4 = new QVBoxLayout(tabDiagnostique);
        verticalLayout_4->setObjectName("verticalLayout_4");
        symptomSearchLineEdit = new QLineEdit(tabDiagnostique);
        symptomSearchLineEdit->setObjectName("symptomSearchLineEdit");

        verticalLayout_4->addWidget(symptomSearchLineEdit);

        symptomListWidget = new QListWidget(tabDiagnostique);
        symptomListWidget->setObjectName("symptomListWidget");
        symptomListWidget->setMaximumSize(QSize(16777215, 500));

        verticalLayout_4->addWidget(symptomListWidget);

        tabafficheerreur = new QTableWidget(tabDiagnostique);
        tabafficheerreur->setObjectName("tabafficheerreur");
        tabafficheerreur->setMaximumSize(QSize(2000, 300));

        verticalLayout_4->addWidget(tabafficheerreur);

        btnNextSolution = new QPushButton(tabDiagnostique);
        btnNextSolution->setObjectName("btnNextSolution");
        btnNextSolution->setEnabled(true);
        btnNextSolution->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"font: 700 italic 16pt \"Segoe UI\";"));

        verticalLayout_4->addWidget(btnNextSolution);

        tabWidget->addTab(tabDiagnostique, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
=======
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
>>>>>>> origin/gestionetablissement


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
<<<<<<< HEAD
        label_6->setText(QCoreApplication::translate("MainWindow", "Ajouter une Vehicule", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Marque :", nullptr));
        marque->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir une marque", nullptr));
        marque->setItemText(1, QCoreApplication::translate("MainWindow", "Citroen", nullptr));
        marque->setItemText(2, QCoreApplication::translate("MainWindow", "DFSK", nullptr));
        marque->setItemText(3, QCoreApplication::translate("MainWindow", "Fiat", nullptr));
        marque->setItemText(4, QCoreApplication::translate("MainWindow", "Ford", nullptr));
        marque->setItemText(5, QCoreApplication::translate("MainWindow", "Hyundai", nullptr));
        marque->setItemText(6, QCoreApplication::translate("MainWindow", "Isuzu", nullptr));
        marque->setItemText(7, QCoreApplication::translate("MainWindow", "Mercedes", nullptr));
        marque->setItemText(8, QCoreApplication::translate("MainWindow", "Opel", nullptr));
        marque->setItemText(9, QCoreApplication::translate("MainWindow", "Peugeot", nullptr));
        marque->setItemText(10, QCoreApplication::translate("MainWindow", "Renault", nullptr));
        marque->setItemText(11, QCoreApplication::translate("MainWindow", "Toyota", nullptr));
        marque->setItemText(12, QCoreApplication::translate("MainWindow", "Volkswagen", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        type->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir un type", nullptr));
        type->setItemText(1, QCoreApplication::translate("MainWindow", "Camions", nullptr));
        type->setItemText(2, QCoreApplication::translate("MainWindow", "Bennes", nullptr));
        type->setItemText(3, QCoreApplication::translate("MainWindow", "Remorques", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Matricule :", nullptr));
        matricule1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer la premiere partie de matricule", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "TN", nullptr));
        matricule2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer la deuxi\303\250me partie de matricule", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        statut->setItemText(0, QCoreApplication::translate("MainWindow", "choisir une status", nullptr));
        statut->setItemText(1, QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        statut->setItemText(2, QCoreApplication::translate("MainWindow", "En livraison", nullptr));
        statut->setItemText(3, QCoreApplication::translate("MainWindow", "En maintenance", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Volume du coffre :", nullptr));
        vcoffre->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer le volume du coffre", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Id transporteur :", nullptr));
        idtransporteur->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer l'id transporteur", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par matricul...", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        triButton->setText(QCoreApplication::translate("MainWindow", "Trier par Marque", nullptr));
        btnSimulateGPS->setText(QCoreApplication::translate("MainWindow", "Localiser", nullptr));
        btnViewLatestGPS->setText(QCoreApplication::translate("MainWindow", "voir dans Map", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "MATRICULE", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID TRANSPORTEUR", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "MARQUE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "TYPE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "VOLUME DU COFFRE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "STATUT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Suppression d'une vehicule", nullptr));
        matricule->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\251rer La matricule \303\240 supprimer ", nullptr));
        Supp_Button->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression), QCoreApplication::translate("MainWindow", "Suppremer", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Modification d'une Vehicule", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Matricule \303\240 modifier :", nullptr));
        matricule1_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer la premiere partie de matricule", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TN", nullptr));
        matricule2_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer la deuxi\303\250me partie de matricule", nullptr));
        matricule_valider->setText(QCoreApplication::translate("MainWindow", "valide", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Marque :", nullptr));
        marque_2->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir une marque", nullptr));
        marque_2->setItemText(1, QCoreApplication::translate("MainWindow", "Citroen", nullptr));
        marque_2->setItemText(2, QCoreApplication::translate("MainWindow", "DFSK", nullptr));
        marque_2->setItemText(3, QCoreApplication::translate("MainWindow", "Fiat", nullptr));
        marque_2->setItemText(4, QCoreApplication::translate("MainWindow", "Ford", nullptr));
        marque_2->setItemText(5, QCoreApplication::translate("MainWindow", "Hyundai", nullptr));
        marque_2->setItemText(6, QCoreApplication::translate("MainWindow", "Isuzu", nullptr));
        marque_2->setItemText(7, QCoreApplication::translate("MainWindow", "Mercedes", nullptr));
        marque_2->setItemText(8, QCoreApplication::translate("MainWindow", "Opel", nullptr));
        marque_2->setItemText(9, QCoreApplication::translate("MainWindow", "Peugeot", nullptr));
        marque_2->setItemText(10, QCoreApplication::translate("MainWindow", "Renault", nullptr));
        marque_2->setItemText(11, QCoreApplication::translate("MainWindow", "Toyota", nullptr));
        marque_2->setItemText(12, QCoreApplication::translate("MainWindow", "Volkswagen", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        type_2->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir un type", nullptr));
        type_2->setItemText(1, QCoreApplication::translate("MainWindow", "Camions", nullptr));
        type_2->setItemText(2, QCoreApplication::translate("MainWindow", "Bennes", nullptr));
        type_2->setItemText(3, QCoreApplication::translate("MainWindow", "Remorques", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        statut_2->setItemText(0, QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        statut_2->setItemText(1, QCoreApplication::translate("MainWindow", "En livraison", nullptr));
        statut_2->setItemText(2, QCoreApplication::translate("MainWindow", "En maintenance", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Volume du coffre :", nullptr));
        vcoffre_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer le volume du coffre", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Id transporteur :", nullptr));
        idtransporteur_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ins\303\250rer l'id transporteur", nullptr));
        mod_button->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModification), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        symptomSearchLineEdit->setInputMask(QString());
        symptomSearchLineEdit->setText(QString());
        symptomSearchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Votre problemme..", nullptr));
#if QT_CONFIG(accessibility)
        btnNextSolution->setAccessibleName(QCoreApplication::translate("MainWindow", "next solution", nullptr));
#endif // QT_CONFIG(accessibility)
        btnNextSolution->setText(QCoreApplication::translate("MainWindow", "autre solution", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDiagnostique), QCoreApplication::translate("MainWindow", "Diagnostique", nullptr));
=======
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
>>>>>>> origin/gestionetablissement
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
