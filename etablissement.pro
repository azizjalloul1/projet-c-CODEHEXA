QT       += core gui
QT += core gui widgets charts sql printsupport
QT += core gui sql
QT += printsupport
QT += network
QT       += charts
QT += core gui widgets sql positioning quick location quickwidgets
QT += quick widgets quickcontrols2 location positioning
QT += positioning
QT += positioning location quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    connexion.cpp \
    etablissement.cpp \
    main.cpp \
    mainwindow.cpp \
    pathview.cpp \
    statswindow.cpp

HEADERS += \
    connexion.h \
    etablissement.h \
    mainwindow.h \
    pathview.h \
    statswindow.h

FORMS += \
    mainwindow.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

DISTFILES += \
        map.html


