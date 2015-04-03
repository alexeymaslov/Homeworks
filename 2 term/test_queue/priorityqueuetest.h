#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "priorityqueue.h"


class PriorityQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityQueueTest(QObject* parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        queue = new PriorityQueue<int>();
    }
    void cleanup()
    {
        delete queue;
    }
    void testEmptyQueueHasNoSize()
    {
        QVERIFY(queue->getSize() == 0);
    }
    void testEnqueueSize()
    {
        queue->enqueue(11, 2);
        QVERIFY(queue->getSize() == 1);
    }
    void testEnqueueDequeue()
    {
        queue->enqueue(11, 2);
        QVERIFY(queue->dequeue() == 11);
    }
    void testDequeueOne()
    {
        queue->enqueue(1, 0);
        queue->enqueue(2, 1000000);
        QVERIFY(queue->dequeue() == 2);
    }
    void testDequeueTwo()
    {
        queue->enqueue(1, 0);
        queue->enqueue(2, 0);
        QVERIFY(queue->dequeue() == 1);
    }
    void testDequeueThree()
    {
        queue->enqueue(1, 1000000);
        queue->enqueue(2, 0);
        QVERIFY(queue->dequeue() == 1);
    }
    void testGetSize()
    {
        queue->enqueue(1, 1);
        queue->enqueue(2, 2);
        queue->enqueue(3, 3);
        QVERIFY(queue->getSize() == 3);
    }
    void testDequeueDecreasesSize()
    {
        queue->enqueue(11, 2);
        queue->enqueue(11, 1);
        queue->dequeue();
        QVERIFY(queue->getSize() == 1);
    }
    void testMassEnqueueWithDifferentPriority()
    {
        queue->enqueue(1, 10);
        queue->enqueue(2, 0);
        queue->enqueue(3, 0);
        queue->enqueue(4, 20);
        queue->enqueue(5, 5);
        queue->enqueue(6, 5);
        queue->enqueue(7, 1);
        queue->enqueue(8, 10);
        int numbers[8];
        for (int i = 0; i < 8; i++)
            numbers[i] = queue->dequeue();
        QVERIFY(numbers[0] == 4 && numbers[1] == 1 && numbers[2] == 8 && numbers[3] == 5 &&
                numbers[4] == 6 && numbers[5] == 7 && numbers[6] == 2 && numbers[7] == 3);
    }
    void testDequeueEmptyQueue()
    {
        queue->dequeue();
        QVERIFY(queue->getSize() == 0);
    }

    void testDequeueEmptyQueueTwo()
    {
        QVERIFY(queue->dequeue() == 0);
    }
    void testDequeueEmptyQueueTwoForDoubleQueue()
    {
        PriorityQueue<double> doubleQueue;
        QVERIFY(doubleQueue.dequeue() == 0);
    }
    void testDequeueEmptyQueueTwoForCharQueue()
    {
        PriorityQueue<char> charQueue;
        QVERIFY(charQueue.dequeue() == 0);
    }
    void testQueueing()
    {
        queue->enqueue(1, 0);
        queue->enqueue(2, 0);
        queue->enqueue(3, 0);
        queue->enqueue(4, 0);
        int numbers[4];
        for (int i = 0; i < 4; i++)
            numbers[i] = queue->dequeue();
        QVERIFY(numbers[0] == 1 && numbers[1] == 2 && numbers[2] == 3 && numbers[3] == 4);
    }
private:
    PriorityQueue<int>* queue;
};
