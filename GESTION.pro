QT += core gui
QT += sql
QT += charts
QT += printsupport
QT += network

# Ajouter le chemin des en-têtes
#INCLUDEPATH += C:/Users/Nadim/Desktop/PROJET_QT/GESTION/include

# Lier la bibliothèque statique
#LIBS += -L"C:/Users/Nadim/Desktop/PROJET_QT/GESTION/lib" -lbcrypt -lmingw32


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    employee.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mdprestwindow.cpp

HEADERS += \
    connexion.h \
    employee.h \
    loginwidget.h \
    mainwindow.h \
    mdprestwindow.h

FORMS += \
    MDP_rest.ui \
    form.ui \
    loginwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
