#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T15:03:32
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 3-1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bubblesort.cpp \
    insertsort.cpp \
    selectionsort.cpp

HEADERS += \
    sorter.h \
    bubblesort.h \
    insertsort.h \
    selectionsort.h \
    sortertest.h
