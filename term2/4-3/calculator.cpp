#include "calculator.h"
#include "QStack"


int Calculator::getPriority(QChar symbol)
{
    if (symbol == '*' || symbol == '/')
        return 1;
    else
        return 0;
}

void Calculator::changeToPostfix(QString &string)
{
    QString postfixString;
    QStack<QChar> stack;
    for (int i = 0; i < string.length(); i++)
    {
        if (string[i].isDigit() || string[i] == '.')
            postfixString += string[i];
        else
        {
            int priorityOfOperand = getPriority(string[i]);
            while (!stack.isEmpty() && priorityOfOperand <= getPriority(stack.top()))
                postfixString += stack.pop();
            stack.push(string[i]);
            postfixString += ' ';
        }
    }
    while (!stack.isEmpty())
        postfixString += stack.pop();
    string = postfixString;
}

double Calculator::getResult(QChar symbol, double digitOne, double digitTwo)
{
    if (symbol == '+')
        return (digitOne + digitTwo);
    else if (symbol == '-')
        return (digitOne - digitTwo);
    else if (symbol == '*')
        return (digitOne * digitTwo);
    else if (symbol == '/')
        return (digitOne / digitTwo);
}

double Calculator::getNumber(QString string, int &i)
{
    double value = 0;
    while (string[i].isDigit())
    {
        value = value * 10 + string[i].digitValue();
        i++;
    }
    if (string[i] == '.')
    {
        i++;
        double divisor = 10;
        while (string[i].isDigit())
        {
            value = value + (string[i].digitValue()) / divisor;
            i++;
            divisor *= 10;
        }
    }
    i--;
    return value;
}

double Calculator::calculate(QString string)
{
    changeToPostfix(string);
    QStack<double> stack;
    for (int i = 0; i < string.length(); i++)
    {
        if (string[i].isSpace())
            continue;
        else if (string[i].isDigit())
            stack.push(getNumber(string, i));
        else
        {
            double top = stack.pop();
            double afterTop = stack.pop();
            stack.push(getResult(string[i], afterTop, top));
        }
    }
    double result = stack.pop();
    return result;
}

