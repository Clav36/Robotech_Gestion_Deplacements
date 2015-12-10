#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T19:38:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppDeplacement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cpoint.cpp \
    cprect.cpp \
    cprond.cpp \
    cline.cpp \
    crobot.cpp

HEADERS  += mainwindow.h \
    cpoint.h \
    cprect.h \
    cprond.h \
    cline.h \
    crobot.h

FORMS    += mainwindow.ui
