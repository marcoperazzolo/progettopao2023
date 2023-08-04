QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    articolo.cpp \
    cd.cpp \
    disco.cpp \
    dvd.cpp \
    fumetto.cpp \
    libro.cpp \
    lista.cpp \
    main.cpp \
    mainwindow.cpp \
    manuale.cpp \
    romanzo.cpp

HEADERS += \
    articolo.h \
    cd.h \
    disco.h \
    dvd.h \
    fumetto.h \
    libro.h \
    lista.h \
    mainwindow.h \
    manuale.h \
    nodo.h \
    romanzo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
