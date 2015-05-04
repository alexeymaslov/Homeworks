#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublylinkedlist.h"

class DoublyLinkedListTest : public QObject
{
    Q_OBJECT
public:
    explicit DoublyLinkedListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new DoublyLinkedList();
    }
    void cleanup()
    {
        delete list;
    }
    void testEmptyList()
    {
        QVERIFY(list->isEmpty());
    }
    void testAddElement()
    {
        list->addElement(1);
        QVERIFY(!list->isEmpty());
    }
    void testNotEmptyList()
    {
        list->addElement(1);
        QVERIFY(!list->isEmpty());
    }
    void testExistance()
    {
        list->addElement(1);
        QVERIFY(list->exists(1));
    }
    void testNotExistanceOne()
    {
        QVERIFY(!list->exists(2));
    }
    void testNotExistanceTwo()
    {
        list->addElement(1);
        QVERIFY(!list->exists(2));
    }
    void testAddingManyElements()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        QVERIFY(list->exists(1) && list->exists(2) && list->exists(3) && !list->isEmpty());
    }
    void testRemove()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->removeElement(2);
        QVERIFY(!list->exists(2));
    }
    void testRemoveFirstElement()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->removeElement(1);
        QVERIFY(!list->exists(1));
    }
    void testRemoveLastElement()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->removeElement(3);
        QVERIFY(!list->exists(3));
    }
    void testRemoveFromEmptyList()
    {
        list->removeElement(1);
        list->removeElement(2);
        QVERIFY(list->isEmpty());
    }
    void testThatListAllElementsOfWhichAreRemovedIsEmpty()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->removeElement(1);
        list->removeElement(2);
        list->removeElement(3);
        QVERIFY(list->isEmpty());
    }

    void testExistanceOfAnotherExampleOfRemovedValue()
    {
        list->addElement(1);
        list->addElement(1);
        list->removeElement(1);
        QVERIFY(list->exists(1));
    }
    void testAddingAfterRemovement()
    {
        list->addElement(1);
        list->removeElement(1);
        list->addElement(2);
        QVERIFY(list->exists(2));
    }

    void testAddingElementWhichHasBeenRemoved()
    {
        list->addElement(1);
        list->removeElement(1);
        list->addElement(1);
        QVERIFY(list->exists(1));
    }
    void testThatNothingHappensToNonRemovedValues()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->removeElement(1);
        QVERIFY(list->exists(2) && list->exists(3));
    }

private:
    DoublyLinkedList* list;
};
