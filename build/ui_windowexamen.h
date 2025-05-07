/********************************************************************************
** Form generated from reading UI file 'windowexamen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWEXAMEN_H
#define UI_WINDOWEXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowExamen
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *r4;
    QLabel *label_8;
    QLabel *label;
    QLineEdit *codeajout;
    QPushButton *upload;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *matajout;
    QLabel *label_4;
    QComboBox *nivajout;
    QLabel *label_3;
    QDateEdit *datajout;
    QLabel *label_5;
    QTimeEdit *herajout;
    QLabel *label_7;
    QLineEdit *quantiteajout;
    QPushButton *ajouter;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *recherche;
    QPushButton *exporter;
    QComboBox *triComboBox;
    QPushButton *stat;
    QPushButton *codebar;
    QTableWidget *tabaffiche;
    QVBoxLayout *chartLayout;
    QWidget *tabModification;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_15;
    QComboBox *codemod;
    QLabel *label_14;
    QComboBox *matmod;
    QLabel *label_13;
    QComboBox *nivmod;
    QLabel *label_16;
    QDateEdit *datmod;
    QLabel *label_17;
    QTimeEdit *hermod;
    QLabel *label_6;
    QLineEdit *quantitemod;
    QPushButton *modifier;
    QWidget *tabSuppression;
    QVBoxLayout *layoutAjout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QLineEdit *codesup;
    QPushButton *supprimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowExamen)
    {
        if (WindowExamen->objectName().isEmpty())
            WindowExamen->setObjectName("WindowExamen");
        WindowExamen->resize(1149, 767);
        centralwidget = new QWidget(WindowExamen);
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
"         transition: 0.3s ease-in-out;\n"
"       }\n"
"\n"
"       QLineEdit:focus {\n"
"         border: 2px solid #3f51b5;\n"
"         background-color: #e8eaf6;\n"
"         box-shadow: 0px 0px 5px rgba(63, 81, 181, 0.5);\n"
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
"         t"
                        "ransition: all 0.3s ease-in-out;\n"
"         box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"       }\n"
"\n"
"       QPushButton:hover {\n"
"         background: #1976D2;\n"
"         box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3);\n"
"       }\n"
"\n"
"       QPushButton:pressed {\n"
"         background: #0D47A1;\n"
"         box-shadow: inset 2px 2px 4px rgba(0, 0, 0, 0.3);\n"
"       }\n"
"\n"
"       QPushButton:disabled {\n"
"         background: #BBDEFB;\n"
"         color: #757575;\n"
"         box-shadow: none;\n"
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
"\n"
"     "
                        "  QComboBox {\n"
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
"         color: white;\n"
"       }\n"
"       #triComboBox {\n"
"           background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"           stop:0 #2196F3, stop:1 #1976D2);\n"
"           color: white;\n"
"           border-radius: 8px;\n"
"           padding-left: 12px;\n"
"           padding-right: 10px;\n"
"           height: 38px;\n"
"           font-size: 16px;\n"
"           font-weight: bold;\n"
"           border: none;\n"
"           min-width: 150px;\n"
"           qpr"
                        "operty-alignment: 'AlignCenter';\n"
"\n"
"       }\n"
"\n"
"       #triComboBox::drop-down {\n"
"           border: none;\n"
"           width: 20px;\n"
"       }\n"
"\n"
"       #triComboBox::down-arrow {\n"
"           image: none;\n"
"       }\n"
"\n"
"       #triComboBox QAbstractItemView {\n"
"           background-color: white;\n"
"           selection-background-color: #1976D2;\n"
"           selection-color: white;\n"
"           font-size: 14px;\n"
"       }\n"
"       #triComboBox QAbstractItemView {\n"
"           background-color: #2196F3;\n"
"           selection-background-color: #1976D2;\n"
"           selection-color: white;\n"
"           color: white;\n"
"           font-size: 14px;\n"
"       }\n"
"\n"
"\n"
"     "));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1141, 711));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
        layoutAjout = new QVBoxLayout(tabAjout);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        r4 = new QPushButton(tabAjout);
        r4->setObjectName("r4");
        r4->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(r4);

        label_8 = new QLabel(tabAjout);
        label_8->setObjectName("label_8");

        horizontalLayout_3->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_3);

        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        codeajout = new QLineEdit(tabAjout);
        codeajout->setObjectName("codeajout");
        codeajout->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(codeajout);

        upload = new QPushButton(tabAjout);
        upload->setObjectName("upload");

        verticalLayout->addWidget(upload);

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        matajout = new QComboBox(tabAjout);
        matajout->setObjectName("matajout");
        matajout->setMaximumSize(QSize(16777215, 50));
        matajout->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(matajout);


        verticalLayout->addLayout(horizontalLayout_2);

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_4);

        nivajout = new QComboBox(tabAjout);
        nivajout->setObjectName("nivajout");
        nivajout->setMaximumSize(QSize(16777215, 50));
        nivajout->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;\n"
"color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(nivajout);

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_3);

        datajout = new QDateEdit(tabAjout);
        datajout->setObjectName("datajout");
        datajout->setMaximumSize(QSize(16777215, 50));
        datajout->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(datajout);

        label_5 = new QLabel(tabAjout);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 30));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_5);

        herajout = new QTimeEdit(tabAjout);
        herajout->setObjectName("herajout");
        herajout->setMaximumSize(QSize(16777215, 50));
        herajout->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(herajout);

        label_7 = new QLabel(tabAjout);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_7);

        quantiteajout = new QLineEdit(tabAjout);
        quantiteajout->setObjectName("quantiteajout");
        quantiteajout->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(quantiteajout);

        ajouter = new QPushButton(tabAjout);
        ajouter->setObjectName("ajouter");

        verticalLayout->addWidget(ajouter);


        layoutAjout->addLayout(verticalLayout);

        tabWidget->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout_2 = new QVBoxLayout(tabAffichage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        recherche = new QLineEdit(tabAffichage);
        recherche->setObjectName("recherche");

        horizontalLayout->addWidget(recherche);

        exporter = new QPushButton(tabAffichage);
        exporter->setObjectName("exporter");

        horizontalLayout->addWidget(exporter);

        triComboBox = new QComboBox(tabAffichage);
        triComboBox->setObjectName("triComboBox");
        triComboBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(triComboBox);

        stat = new QPushButton(tabAffichage);
        stat->setObjectName("stat");

        horizontalLayout->addWidget(stat);

        codebar = new QPushButton(tabAffichage);
        codebar->setObjectName("codebar");

        horizontalLayout->addWidget(codebar);


        verticalLayout_2->addLayout(horizontalLayout);

        tabaffiche = new QTableWidget(tabAffichage);
        if (tabaffiche->columnCount() < 7)
            tabaffiche->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabaffiche->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tabaffiche->setObjectName("tabaffiche");
        tabaffiche->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(tabaffiche);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");

        verticalLayout_2->addLayout(chartLayout);

        tabWidget->addTab(tabAffichage, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
        verticalLayoutWidget = new QWidget(tabModification);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 1121, 651));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName("label_15");
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMaximumSize(QSize(16777215, 30));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_15);

        codemod = new QComboBox(verticalLayoutWidget);
        codemod->setObjectName("codemod");
        codemod->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(codemod);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(16777215, 30));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_14);

        matmod = new QComboBox(verticalLayoutWidget);
        matmod->setObjectName("matmod");
        matmod->setMaximumSize(QSize(16777215, 50));
        matmod->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(matmod);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(16777215, 30));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_13);

        nivmod = new QComboBox(verticalLayoutWidget);
        nivmod->setObjectName("nivmod");
        nivmod->setMaximumSize(QSize(16777215, 50));
        nivmod->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(nivmod);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(16777215, 30));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_16);

        datmod = new QDateEdit(verticalLayoutWidget);
        datmod->setObjectName("datmod");
        datmod->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(datmod);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName("label_17");
        label_17->setMaximumSize(QSize(16777215, 30));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_17);

        hermod = new QTimeEdit(verticalLayoutWidget);
        hermod->setObjectName("hermod");
        hermod->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(hermod);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_6);

        quantitemod = new QLineEdit(verticalLayoutWidget);
        quantitemod->setObjectName("quantitemod");
        quantitemod->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(quantitemod);

        modifier = new QPushButton(verticalLayoutWidget);
        modifier->setObjectName("modifier");

        verticalLayout_3->addWidget(modifier);

        tabWidget->addTab(tabModification, QString());
        tabSuppression = new QWidget();
        tabSuppression->setObjectName("tabSuppression");
        layoutAjout_2 = new QVBoxLayout(tabSuppression);
        layoutAjout_2->setObjectName("layoutAjout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label_18 = new QLabel(tabSuppression);
        label_18->setObjectName("label_18");
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(label_18);

        codesup = new QLineEdit(tabSuppression);
        codesup->setObjectName("codesup");
        codesup->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(codesup);

        supprimer = new QPushButton(tabSuppression);
        supprimer->setObjectName("supprimer");

        verticalLayout_4->addWidget(supprimer);


        layoutAjout_2->addLayout(verticalLayout_4);

        tabWidget->addTab(tabSuppression, QString());
        WindowExamen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowExamen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 26));
        WindowExamen->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowExamen);
        statusbar->setObjectName("statusbar");
        WindowExamen->setStatusBar(statusbar);

        retranslateUi(WindowExamen);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WindowExamen);
    } // setupUi

    void retranslateUi(QMainWindow *WindowExamen)
    {
        WindowExamen->setWindowTitle(QCoreApplication::translate("WindowExamen", "MainWindow", nullptr));
        r4->setText(QCoreApplication::translate("WindowExamen", "retour", nullptr));
        label_8->setText(QCoreApplication::translate("WindowExamen", "                                                             Ajouter des examen", nullptr));
        label->setText(QCoreApplication::translate("WindowExamen", "Id examen", nullptr));
        codeajout->setPlaceholderText(QCoreApplication::translate("WindowExamen", "........", nullptr));
        upload->setText(QCoreApplication::translate("WindowExamen", "upload pdf", nullptr));
        label_2->setText(QCoreApplication::translate("WindowExamen", "matiere", nullptr));
        label_4->setText(QCoreApplication::translate("WindowExamen", "niveau", nullptr));
        label_3->setText(QCoreApplication::translate("WindowExamen", "date", nullptr));
        label_5->setText(QCoreApplication::translate("WindowExamen", "heure", nullptr));
        label_7->setText(QCoreApplication::translate("WindowExamen", "Quantite", nullptr));
        quantiteajout->setPlaceholderText(QCoreApplication::translate("WindowExamen", "........", nullptr));
        ajouter->setText(QCoreApplication::translate("WindowExamen", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QCoreApplication::translate("WindowExamen", "Ajout", nullptr));
        recherche->setText(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("WindowExamen", "Rechercher par code ou mati\303\251re ...", nullptr));
        exporter->setText(QCoreApplication::translate("WindowExamen", "Exporter en PDF", nullptr));
        stat->setText(QCoreApplication::translate("WindowExamen", "STAT", nullptr));
        codebar->setText(QCoreApplication::translate("WindowExamen", "QRCODE", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabaffiche->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WindowExamen", "id examen", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabaffiche->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WindowExamen", "matiere", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabaffiche->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WindowExamen", "niveau", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabaffiche->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WindowExamen", "date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabaffiche->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WindowExamen", "heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tabaffiche->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WindowExamen", "Quantite", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tabaffiche->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WindowExamen", "pdf", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("WindowExamen", "Affichage", nullptr));
        label_15->setText(QCoreApplication::translate("WindowExamen", "Id examen", nullptr));
        label_14->setText(QCoreApplication::translate("WindowExamen", "matiere", nullptr));
        label_13->setText(QCoreApplication::translate("WindowExamen", "niveau", nullptr));
        label_16->setText(QCoreApplication::translate("WindowExamen", "date", nullptr));
        label_17->setText(QCoreApplication::translate("WindowExamen", "heure", nullptr));
        label_6->setText(QCoreApplication::translate("WindowExamen", "Quantite", nullptr));
        quantitemod->setPlaceholderText(QCoreApplication::translate("WindowExamen", "........", nullptr));
        modifier->setText(QCoreApplication::translate("WindowExamen", "modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModification), QCoreApplication::translate("WindowExamen", "Modification", nullptr));
        label_18->setText(QCoreApplication::translate("WindowExamen", "Id examen", nullptr));
        codesup->setPlaceholderText(QCoreApplication::translate("WindowExamen", "....", nullptr));
        supprimer->setText(QCoreApplication::translate("WindowExamen", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression), QCoreApplication::translate("WindowExamen", "Suppression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowExamen: public Ui_WindowExamen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWEXAMEN_H
