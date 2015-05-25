#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testNoOperators()
    {
        QVERIFY(Calculator::calculate("1") == 1);
    }
    void testAddition()
    {
        QVERIFY(Calculator::calculate("1+1+2+3.3") == 7.3);
    }
    void testSubtraction()
    {
        QVERIFY(Calculator::calculate("5.88-0.88-2") == 3);
    }
    void testMultiplication()
    {
        QVERIFY(Calculator::calculate("2*0.2*2") == 0.8);
    }
    void testDivision()
    {
        QVERIFY(Calculator::calculate("4/2/0.2") == 10);
    }
};
