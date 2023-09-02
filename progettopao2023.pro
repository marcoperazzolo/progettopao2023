QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/articolo.cpp \
    Model/cd.cpp \
    Model/disco.cpp \
    Model/dvd.cpp \
    Model/fumetto.cpp \
    Model/libro.cpp \
    Model/main.cpp \
    Model/manuale.cpp \
    Model/romanzo.cpp \
    View/finestraaggiungiarticolo.cpp \
    View/finestradettagliarticolo.cpp \
    View/finestramodificaarticolo.cpp \
    View/listaarticoli.cpp \
    View/main.cpp \
    View/mainwindow.cpp \
    View/widgetarticolo.cpp \
    articolo.cpp \
    cd.cpp \
    disco.cpp \
    dvd.cpp \
    fumetto.cpp \
    libro.cpp \
    main.cpp \
    manuale.cpp \
    romanzo.cpp

HEADERS += \
    Model/articolo.h \
    Model/cd.h \
    Model/disco.h \
    Model/dvd.h \
    Model/fumetto.h \
    Model/libro.h \
    Model/lista.h \
    Model/manuale.h \
    Model/romanzo.h \
    View/finestraaggiungiarticolo.h \
    View/finestradettagliarticolo.h \
    View/finestramodificaarticolo.h \
    View/listaarticoli.h \
    View/mainwindow.h \
    View/widgetarticolo.h \
    articolo.h \
    cd.h \
    disco.h \
    dvd.h \
    fumetto.h \
    libro.h \
    lista.h \
    manuale.h \
    romanzo.h

FORMS += \
    View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    View/untitled.pro

RESOURCES += \
    View/resources.qrc

DISTFILES += \
    View/dvd.png
