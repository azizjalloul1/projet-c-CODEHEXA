QT       += core gui
QT += core gui widgets charts sql printsupport
QT += core gui sql
QT += printsupport
QT += network
QT += core gui widgets sql printsupport network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    etablissement.cpp \
    main.cpp \
    mainwindow.cpp \
    statswindow.cpp

HEADERS += \
    connexion.h \
    etablissement.h \
    mainwindow.h \
    statswindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
