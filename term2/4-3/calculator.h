#pragma once
#include <QString>

class Calculator
{
public:
    ///Returns result of calculation of equation from string
    static double calculate(QString string);
private:
    ///Changes string to postfix
    static void changeToPostfix(QString &string);
    ///Returns priority of operation. 0 - for addition and subtraction, 1 - for multiplication and division
    static int getPriority(QChar symbol);
    ///Returns result of binary operation
    static double getResult(QChar symbol, double digitOne, double digitTwo);
    ///Returns number consisting integer and fractional parts
    static double getNumber(QString string, int& i);
};
