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
    void testNoOperatorsOne()
    {
        QVERIFY(Calculator::calculate("1") == 1);
    }
    void testNoOperatorsTwo()
    {
        QVERIFY(Calculator::calculate("0") == 0);
    }
    void testAddition()
    {
        QVERIFY(Calculator::calculate("1 + 1") == 2);
    }
    void testBigAddition()
    {
        QVERIFY(Calculator::calculate("1 + 22 + 333 + 4444") == 4800);
    }
    void testSubtraction()
    {
        QVERIFY(Calculator::calculate("2 - 2") == 0);
    }
    void testBigSubtraction()
    {
        QVERIFY(Calculator::calculate("1 - 22 - 333 - 4444") == -4798);
    }
    void testMultiplication()
    {
        QVERIFY(Calculator::calculate("2 * 2") == 4);
    }
    void testBigMultiplication()
    {
        QVERIFY(Calculator::calculate("1 * 22 * 333") == 7326);
    }
    void testDivision()
    {
        QVERIFY(Calculator::calculate("4 / 2") == 2);
    }
    void testBigDivision()
    {
        QVERIFY(Calculator::calculate("4444 / 2 / 11") == 202);
    }
    void testBracketsOne()
    {
        QVERIFY(Calculator::calculate("(1)") == 1);
    }
    void testBracketsTwo()
    {
        QVERIFY(Calculator::calculate("(1 + 3)") == 4);
    }
    void testOne()
    {
        QVERIFY(Calculator::calculate("(22 - 11) + (3 - 2 * 4) * (4 + 3) / 4") == 2.25);
    }
    void testTwo()
    {
        QVERIFY(Calculator::calculate("(1 + (1 + (1 + (1 + 2))))") == 6);
    }
    void testThree()
    {
        QVERIFY(Calculator::calculate("(1 / 10 + 2 / 10 + 3 / 10 + 4 / 10) / 2") == 0.5);
    }
};
