#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arraystack.h"

class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        stack = new ArrayStack<int>();
    }
    void cleanup()
    {
        delete stack;
    }
    void testEmptyStack()
    {
        QVERIFY(stack->isEmpty());
    }
    void testEmptyStackHasNoSize()
    {
        QVERIFY(stack->getSize() == 0);
    }
    void testPush()
    {
        stack->push(1);
        QVERIFY(!stack->isEmpty());
    }
    void testSizeAfterPush()
    {
        stack->push(1);
        QVERIFY(stack->getSize() == 1);
    }
    void testPeekOne()
    {
        stack->push(1);
        QVERIFY(stack->peek() == 1);
    }
    void testPeekTwo()
    {
        stack->push(1);
        stack->push(2);
        QVERIFY(stack->peek() == 2);
    }
    void testPeekIsNotPopOne()
    {
        stack->push(2);
        stack->peek();
        QVERIFY(stack->getSize() == 1);
    }
    void testPeekIsNotPopTwo()
    {
        stack->push(1);
        stack->peek();
        QVERIFY(!stack->isEmpty());
    }
    void testPopOne()
    {
        stack->push(1);
        stack->pop();
        QVERIFY(stack->isEmpty());
    }
    void testPopTwo()
    {
        stack->push(1);
        stack->push(2);
        stack->pop();
        QVERIFY(stack->peek() == 1);
    }
    void testPopThree()
    {
        stack->push(1);
        stack->push(2);
        QVERIFY(stack->pop() == 2);
    }
    void testPopFour()
    {
        stack->push(1);
        stack->push(2);
        stack->push(3);
        stack->pop();
        stack->pop();
        QVERIFY(stack->getSize() == 1);
    }
    void testPopEmptyStackOne()
    {
        stack->pop();
        QVERIFY(stack->isEmpty() && stack->getSize() == 0);
    }
    void testPopEmptyStackTwo()
    {
        QVERIFY(stack->pop() == 0);
    }

    void testPoppedIsSameAsPeeked()
    {
        stack->push(1);
        QVERIFY(stack->peek() == stack->pop());
    }
    void testStackExpand()
    {
        for (int i = 0; i < 100; i++)
            stack->push(i);
        QVERIFY(stack->getSize() == 100 && stack->peek() == 99);
    }

private:
    ArrayStack<int>* stack;
};
