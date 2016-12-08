#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T17:14:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShortPathMap_CQU_A
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    list.cpp \
    mgraph.cpp \
    pointer.cpp

HEADERS  += mainwindow.h \
    list.h \
    mgraph.h \
    dijkstra.h \
    pointer.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
