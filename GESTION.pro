QT += core gui
QT += sql
QT += charts
QT += printsupport
QT += network
QT += serialport
QT += quick
QT += positioning
QT += location
QT += quickwidgets



pannes_txt.files = $$PWD/pannes.txt
pannes_txt.path = $$OUT_PWD
INSTALLS += pannes_txt
HEADERS += qrcodegen.hpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    employee.cpp \
    vehicules.cpp\
    stock.cpp \
    examen.cpp \
    fournisseur.cpp \
    loginwidget.cpp \
    main.cpp\
    mainwindow.cpp \
    mainwindowv.cpp \
    mainwindowstock.cpp\
    windowexamen.cpp \
    mainwindowF.cpp \
    mdprestwindow.cpp \
    sms.cpp \
    smtpclient.cpp \
    accueil.cpp

HEADERS += \
    connexion.h \
    employee.h \
    vehicules.h \
    stock.h \
    examen.h \
    AnimatedDialog.h \
    CustomComboBox.h \
    mainwindow.h \
    mainwindowv.h\
    mainwindowstock.h \
    windowexamen.h \
    loginwidget.h \
    accueil.h \
    fournisseur.h \
    mainwindowF.h \
    sms.h \
    smtpclient.h \
    mdprestwindow.h

FORMS += \
    MDP_rest.ui \
    accueil.ui \
    loginwidget.ui \
    mainwindowv.ui\
    mainwindowstock.ui\
    windowexamen.ui \
    mainwindowF.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
 qrc.qrc
DISTFILES +=
