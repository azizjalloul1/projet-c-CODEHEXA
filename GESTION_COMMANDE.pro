QT += core gui \
    quick \
    sql \
    charts  # ✅ Add this line for Qt Charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Uncomment to disable deprecated APIs before Qt 6
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindowstock.cpp \
    stock.cpp

HEADERS += \
    AnimatedDialog.h \
    CustomComboBox.h \
    connexion.h \
    mainwindowstock.h \
    stock.h

FORMS += \
    mainwindowstock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
