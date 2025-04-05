QT += core gui
QT += sql
QT += printsupport
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    connexion.cpp \
    examen.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connexion.h \
    examen.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
