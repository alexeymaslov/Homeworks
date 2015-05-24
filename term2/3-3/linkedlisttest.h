#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedlist.h"

class LinkedListTest : public QObject
{
    Q_OBJECT
public:
    explicit LinkedListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new LinkedList();
    }
    void cleanup()
    {
        delete list;
    }
    void testEmptyListSize()
    {
        QVERIFY(list->getSize() == 0);
    }
    void testAdd()
    {
        list->add(11);
        list->add(22);
        QVERIFY(list->at(0) == 11 && list->at(1) == 22);
    }
    void testAddChangesSize()
    {
        list->add(11);
        QVERIFY(list->getSize() == 1);
    }
    void testAtNonAvailableIndex()
    {
        QVERIFY(list->at(-100) == 0);
    }
    void testAtBorderIndex()
    {
        list->add(11);
        QVERIFY(list->at(1) == 0);
    }
private:
    LinkedList* list;
};
