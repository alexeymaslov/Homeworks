#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T09:36:56
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = test_queue
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    priorityqueuetest.h \
    priorityqueue.h

QMAKE_CXXFLAGS += -std=c++0x
