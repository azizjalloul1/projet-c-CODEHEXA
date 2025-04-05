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
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QVBoxLayout *layoutAjout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *idInput;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_3;
    QCalendarWidget *calendarWidget;
    QLabel *label_5;
    QTimeEdit *timeEdit_2;
    QPushButton *addButton;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *exportButton;
    QPushButton *triButton;
    QTableWidget *tableWidget;
    QVBoxLayout *chartLayout;
    QWidget *tabModification;
    QLabel *label_13;
    QPushButton *addButton_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QComboBox *comboBox_5;
    QLineEdit *idInput_3;
    QCalendarWidget *calendarWidget_3;
    QTimeEdit *timeEdit_4;
    QLabel *label_17;
    QComboBox *comboBox_6;
    QWidget *tabSuppression;
    QVBoxLayout *layoutAjout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QLineEdit *idInput_4;
    QPushButton *SuppButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1191, 659);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 40, 1201, 491));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabAjout = new QWidget();
        tabAjout->setObjectName("tabAjout");
        layoutAjout = new QVBoxLayout(tabAjout);
        layoutAjout->setObjectName("layoutAjout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label = new QLabel(tabAjout);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label);

        idInput = new QLineEdit(tabAjout);
        idInput->setObjectName("idInput");
        idInput->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(idInput);

        label_2 = new QLabel(tabAjout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox_2 = new QComboBox(tabAjout);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMaximumSize(QSize(16777215, 50));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_4 = new QLabel(tabAjout);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_4);

        comboBox = new QComboBox(tabAjout);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMaximumSize(QSize(16777215, 50));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));

        verticalLayout->addWidget(comboBox);

        label_3 = new QLabel(tabAjout);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_3);

        calendarWidget = new QCalendarWidget(tabAjout);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        label_5 = new QLabel(tabAjout);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_5);

        timeEdit_2 = new QTimeEdit(tabAjout);
        timeEdit_2->setObjectName("timeEdit_2");

        verticalLayout->addWidget(timeEdit_2);

        addButton = new QPushButton(tabAjout);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);


        layoutAjout->addLayout(verticalLayout);

        tabWidget->addTab(tabAjout, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout_2 = new QVBoxLayout(tabAffichage);
        verticalLayout_2->setObjectName("verticalLayout_2");
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


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(tabAffichage);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName("tableWidget");

        verticalLayout_2->addWidget(tableWidget);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");

        verticalLayout_2->addLayout(chartLayout);

        tabWidget->addTab(tabAffichage, QString());
        tabModification = new QWidget();
        tabModification->setObjectName("tabModification");
        label_13 = new QLabel(tabModification);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 125, 1173, 20));
        label_13->setMaximumSize(QSize(16777215, 30));
        addButton_3 = new QPushButton(tabModification);
        addButton_3->setObjectName("addButton_3");
        addButton_3->setGeometry(QRect(10, 400, 1173, 29));
        label_14 = new QLabel(tabModification);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 61, 1173, 20));
        label_14->setMaximumSize(QSize(16777215, 30));
        label_15 = new QLabel(tabModification);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, -1, 1173, 20));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMaximumSize(QSize(16777215, 30));
        label_16 = new QLabel(tabModification);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 187, 1173, 20));
        label_16->setMaximumSize(QSize(16777215, 30));
        comboBox_5 = new QComboBox(tabModification);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(10, 152, 1173, 28));
        comboBox_5->setMaximumSize(QSize(16777215, 50));
        comboBox_5->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));
        idInput_3 = new QLineEdit(tabModification);
        idInput_3->setObjectName("idInput_3");
        idInput_3->setGeometry(QRect(10, 26, 1173, 28));
        idInput_3->setMaximumSize(QSize(16777215, 50));
        calendarWidget_3 = new QCalendarWidget(tabModification);
        calendarWidget_3->setObjectName("calendarWidget_3");
        calendarWidget_3->setGeometry(QRect(10, 214, 1173, 116));
        timeEdit_4 = new QTimeEdit(tabModification);
        timeEdit_4->setObjectName("timeEdit_4");
        timeEdit_4->setGeometry(QRect(10, 364, 1173, 29));
        label_17 = new QLabel(tabModification);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 337, 1173, 20));
        label_17->setMaximumSize(QSize(16777215, 30));
        comboBox_6 = new QComboBox(tabModification);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(10, 94, 1171, 28));
        comboBox_6->setMaximumSize(QSize(16777215, 50));
        comboBox_6->setStyleSheet(QString::fromUtf8("background-color: #f1f1f1;"));
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

        verticalLayout_4->addWidget(label_18);

        idInput_4 = new QLineEdit(tabSuppression);
        idInput_4->setObjectName("idInput_4");
        idInput_4->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(idInput_4);

        SuppButton = new QPushButton(tabSuppression);
        SuppButton->setObjectName("SuppButton");

        verticalLayout_4->addWidget(SuppButton);


        layoutAjout_2->addLayout(verticalLayout_4);

        tabWidget->addTab(tabSuppression, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1191, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "code examen", nullptr));
        idInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "........", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "matiere", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "niveau", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "heure", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par code...", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        triButton->setText(QCoreApplication::translate("MainWindow", "Trier par Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "code examen", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "matiere", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "niveau", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "heure", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "niveau", nullptr));
        addButton_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "matiere", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "code examen", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));

        idInput_3->setPlaceholderText(QCoreApplication::translate("MainWindow", ".....", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "heure", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabModification), QCoreApplication::translate("MainWindow", "Modification", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "code examen", nullptr));
        idInput_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "....", nullptr));
        SuppButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSuppression), QCoreApplication::translate("MainWindow", "Suppression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
