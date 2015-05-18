#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedlist.h"
#include "listscomparator.h"

class ListsComparatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ListsComparatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        listOne = new LinkedList;
        listTwo = new LinkedList;
    }
    void cleanup()
    {
        delete listOne;
        delete listTwo;
    }
    void testCompareLess()
    {
        listOne->add(1);
        listTwo->add(2);
        listTwo->add(3);
        QVERIFY(ListsComparator::compare(listOne, listTwo) == ListsComparator::less);
    }
    void testCompareBigger()
    {
        listOne->add(1);
        listTwo->add(2);
        listTwo->add(3);
        QVERIFY(ListsComparator::compare(listTwo, listOne) == ListsComparator::bigger);
    }
    void testCompareEqual()
    {
        listOne->add(1);
        listTwo->add(2);
        QVERIFY(ListsComparator::compare(listTwo, listOne) == ListsComparator::equal);
    }
    void testCompareEqualEmpty()
    {
        QVERIFY(ListsComparator::compare(listOne, listTwo) == ListsComparator::equal);
    }
private:
    LinkedList* listOne;
    LinkedList* listTwo;
};
