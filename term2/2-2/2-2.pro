#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T14:46:24
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 2-2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    calculator.cpp

HEADERS += stack.h \
    arraystack.h \
    arraystacktest.h \
    linkedstack.h \
    linkedstacktest.h \
    calculator.h \
    calculatortest.h

QMAKE_CXXFLAGS += -std=c++0x
