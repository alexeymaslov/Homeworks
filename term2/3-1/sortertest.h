#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include "bubblesort.h"
#include "insertsort.h"
#include "selectionsort.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        numbers = new int[size];
        srand(time(NULL));
        for (int i = 0; i < size; i ++)
            numbers[i] = rand();
    }
    void cleanup()
    {
        delete []numbers;
        delete sorter;
    }
    void testBubbleSortedArrayIsSorted()
    {

        sorter = new BubbleSort;
        sorter->sort(numbers, size);
        bool valid = true;
        for (int i = 0; i < size - 1; i++)
            if (numbers[i] > numbers[i + 1])
                valid = false;
        QVERIFY(valid);
    }
    void testInsertSortedArrayIsSorted()
    {
        sorter = new InsertSort;
        sorter->sort(numbers, size);
        bool valid = true;
        for (int i = 0; i < size - 1; i++)
            if (numbers[i] > numbers[i + 1])
                valid = false;
        QVERIFY(valid);
    }
    void testSelectionSortedArrayIsSorted()
    {
        sorter = new SelectionSort;
        sorter->sort(numbers, size);
        bool valid = true;
        for (int i = 0; i < size - 1; i++)
            if (numbers[i] > numbers[i + 1])
                valid = false;
        QVERIFY(valid);
    }
private:
    Sorter* sorter;
    int* numbers;
    static const int size = 100;
};
