#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T13:23:21
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4-3
TEMPLATE = app


SOURCES += main.cpp\
        calculatorwindow.cpp \
    calculator.cpp

HEADERS  += calculatorwindow.h \
    calculator.h \
    calculatortest.h

FORMS    += calculatorwindow.ui

