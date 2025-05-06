QT += core gui
QT += sql
QT += printsupport
QT += widgets
QT += charts
QT += core gui widgets charts
QT += network

QT += serialport

SOURCES +=
HEADERS += qrcodegen.hpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    connexion.cpp \
    examen.cpp \
    main.cpp \
    windowexamen.cpp

HEADERS += \
    connexion.h \
    examen.h \
    windowexamen.h



FORMS += \
    windowexamen.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
