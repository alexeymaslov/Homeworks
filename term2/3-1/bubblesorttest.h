#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include "bubblesort.h"

class BubbleSortTest : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        sorter = new BubbleSort();
        srand(time(NULL));
        for (int i = 0; i < size; i ++)
            numbers[i] = rand();
    }
    void cleanup()
    {
        delete sorter;
    }
    void testSortedArrayIsSorted()
    {
        sorter->sort(numbers, size);
    }

private:
    BubbleSort* sorter;
    const int size = 15;
    int numbers[size];
};
