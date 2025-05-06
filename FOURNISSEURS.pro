QT+= core gui
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui sql printsupport
QT += core gui sql network
QT += charts
QT += core gui network
QT += core network
QT += core gui sql charts
QT += widgets sql charts network


QT += network





# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    fournisseur.cpp \
     main.cpp \
    mainwindowF.cpp \
    sms.cpp \
    smtpclient.cpp

HEADERS += \
    connexion.h \
    fournisseur.h \
    mainwindowF.h \
    sms.h \
    smtpclient.h

FORMS += \
    mainwindowF.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
