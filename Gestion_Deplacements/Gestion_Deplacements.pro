#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T20:41:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gestion_Deplacements
TEMPLATE = app


QMAKE_CXXFLAGS += -Wall -Wextra -pedantic -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crobot.cpp \
    cprond.cpp \
    cprect.cpp \
    cpoint.cpp \
    cline.cpp \
    qviewtable.cpp \
    cetape.cpp

HEADERS  += mainwindow.h \
    crobot.h \
    cprond.h \
    cprect.h \
    cpoint.h \
    cline.h \
    qviewtable.h \
    cetape.h

FORMS    += mainwindow.ui

RESOURCES += \
    Ressources.qrc
