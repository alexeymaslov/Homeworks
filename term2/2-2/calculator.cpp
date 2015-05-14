#include <cstring>
#include <ctype.h>
#include "calculator.h"
#include "stack.h"
#include "arraystack.h"
#include "linkedstack.h"


int Calculator::getPriority(char symbol)
{
    if (symbol == '*' || symbol == '/')
        return 2;
    else
        return 1;
}

void Calculator::changeToPostfix(char* &line)
{
    int size = strlen(line);
    char* postfixLine = new char[2 * size];
    Stack<char>* charStack = new LinkedStack<char>();
    int currentIndexOfPostfixLine = 0;

    for (int i = 0; i < size; i++)
    {
        if (isspace(line[i]))
            continue;
        else if (isdigit(line[i]))
            postfixLine[currentIndexOfPostfixLine++] = line[i];
        else if (line[i] == '(')
            charStack->push(line[i]);
        else if (line[i] == ')')
        {
            while (charStack->peek() != '(')
                postfixLine[currentIndexOfPostfixLine++] = charStack->pop();
            charStack->pop();
        }
        else
        {
            int priorityOfOperand = getPriority(line[i]);
            while (!charStack->isEmpty() && charStack->peek() != '(' && priorityOfOperand <= getPriority(charStack->peek()))
                postfixLine[currentIndexOfPostfixLine++] = charStack->pop();
            charStack->push(line[i]);
            postfixLine[currentIndexOfPostfixLine++] = ' ';
        }
    }

    while (!charStack->isEmpty())
        postfixLine[currentIndexOfPostfixLine++] = charStack->pop();
    postfixLine[currentIndexOfPostfixLine] = '\0';
    delete charStack;
    delete[] line;
    line = postfixLine;
}

double Calculator::getResult(char symbol, double digitOne, double digitTwo)
{
    switch (symbol)
    {
    case '+':
        return (digitOne + digitTwo);
    case '-':
        return (digitOne - digitTwo);
    case '*':
        return (digitOne * digitTwo);
    case '/':
        return (digitOne / digitTwo);
    }
}

double Calculator::getDigit(char* line, int &index)
{
    double value = line[index] - '0';
    while (isdigit(line[++index]))
        value = value * 10 + line[index] - '0';
    index--;
    return value;
}

double Calculator::calculate(char* line)
{
    changeToPostfix(line);
    Stack<double>* doubleStack = new LinkedStack<double>();

    for (int i = 0; i < strlen(line); i++)
    {
        if (isspace(line[i]))
            continue;
        else if (isdigit(line[i]))
            doubleStack->push(getDigit(line, i));
        else
        {

            double top = doubleStack->pop();
            double afterTop = doubleStack->pop();
            doubleStack->push(getResult(line[i], afterTop, top));
        }
    }
    double result = doubleStack->pop();
    delete doubleStack;
    return result;
}

