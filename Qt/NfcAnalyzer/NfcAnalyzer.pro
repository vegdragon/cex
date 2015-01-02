#-------------------------------------------------
#
# Project created by QtCreator 2014-12-14T19:05:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NfcAnalyzer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Utils.cpp

HEADERS  += mainwindow.h \
    Utils.h \
    hci.h

FORMS    += mainwindow.ui
