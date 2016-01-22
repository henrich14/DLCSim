#-------------------------------------------------
#
# Project created by QtCreator 2014-07-20T10:34:58
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia

TARGET = MyClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    strip.cpp \
    label.cpp \
    metar.cpp \
    time.cpp \
    timesyncdialog.cpp \
    stripinbound.cpp \
    stripoutbound.cpp \
    stripoverflight.cpp \
    radarwindow.cpp \
    radarview.cpp \
    mytextitem.cpp \
    cflwidget.cpp \
    directwidget.cpp

HEADERS  += mainwindow.h \
    strip.h \
    label.h \
    metar.h \
    time.h \
    timesyncdialog.h \
    stripinbound.h \
    stripoutbound.h \
    stripoverflight.h \
    radarwindow.h \
    radarview.h \
    mytextitem.h \
    cflwidget.h \
    directwidget.h

FORMS    += mainwindow.ui \
    strip.ui \
    label.ui \
    metar.ui \
    time.ui \
    timesyncdialog.ui \
    stripinbound.ui \
    stripoutbound.ui \
    stripoverflight.ui \
    radarwindow.ui \
    cflwidget.ui \
    directwidget.ui

RESOURCES += \
    resources.qrc

RC_FILE = MyClient.rc
