#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T00:43:46
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 3-3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    linkedlist.cpp \
    sortedset.cpp \
    listscomparator.cpp

HEADERS += \
    linkedlist.h \
    listscomparator.h \
    sortedset.h \
    linkedlisttest.h \
    listscomparatortest.h \
    sortedsettest.h

QMAKE_CXXFLAGS += -std=c++0x
