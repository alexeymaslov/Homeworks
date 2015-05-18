#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sortedset.h"
#include "linkedlist.h"

class SortedSetTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        set = new SortedSet();
    }
    void cleanup()
    {
        delete set;
    }
    void testEmptySet()
    {
        QVERIFY(!set->at(0));
    }
    void testAdd()
    {
        LinkedList* list = new LinkedList;
        list->add(1);
        set->add(list);
        QVERIFY(set->at(0)->at(0) == 1);
    }
    void testAddTwoLists()
    {
        LinkedList* listOne = new LinkedList;
        listOne->add(1);
        LinkedList* listTwo = new LinkedList;
        listTwo->add(2);
        listTwo->add(3);
        set->add(listOne);
        set->add(listTwo);
        QVERIFY(set->at(0)->at(0) == 1 && set->at(1)->at(0) == 2 && set->at(1)->at(1) == 3);
    }
    void testAddListWithSameSize()
    {
        LinkedList* listOne = new LinkedList;
        listOne->add(1);
        LinkedList* listTwo = new LinkedList;
        listTwo->add(2);
        set->add(listOne);
        set->add(listTwo);
        QVERIFY(set->at(0)->at(0) == 2 && !set->at(1));
    }
    void testThatSetIsSorted()
    {
        LinkedList* listOne = new LinkedList;
        listOne->add(1);
        LinkedList* listTwo = new LinkedList;
        listTwo->add(2);
        listTwo->add(3);
        LinkedList* listThree = new LinkedList;
        listThree->add(4);
        listThree->add(5);
        listThree->add(6);
        set->add(listThree);
        set->add(listOne);
        set->add(listTwo);
        QVERIFY(set->at(0)->at(0) == 1 && set->at(1)->at(0) == 2 &&
                set->at(1)->at(1) == 3 && set->at(2)->at(0) == 4 &&
                set->at(2)->at(1) == 5 && set->at(2)->at(2) == 6);
    }
private:
    SortedSet* set;
};
