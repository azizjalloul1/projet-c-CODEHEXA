QT       += core gui
QT+= sql
QT+= charts
QT += quick widgets positioning location
QT += quickwidgets
QT += quick qml
QT += serialport


pannes_txt.files = $$PWD/pannes.txt
pannes_txt.path = $$OUT_PWD
INSTALLS += pannes_txt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    vehicules.cpp

HEADERS += \
    connexion.h \
    issue.h \
    mainwindow.h \
    vehicules.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

DISTFILES +=
