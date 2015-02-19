#include "stackOfChar.h"
#include "stackOfDouble.h"
#include <cstring>
#include <ctype.h>

int getPriority(char symbol)
{
    if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void changeToPostfix(char *firstLine, char *secondLine)
{

    int counter = 0;
    StackChar *stack = createStackChar();
    char topSymbol = 'a';
    for (unsigned q = 0; q <= strlen(firstLine); q++)
    {
        if (isspace(firstLine[q]))
        {
            continue;
        }
        if (isdigit(firstLine[q]))
        {
            secondLine[counter] = firstLine[q];
            counter++;
        }
        else if (firstLine[q] == '(')
        {
            pushStackChar(stack, firstLine[q]);
        }
        else if (firstLine[q] == ')')
        {
            topSymbol = popStackChar(stack);
            while (topSymbol != '(')
            {
                secondLine[counter] = topSymbol;
                counter++;
                topSymbol = popStackChar(stack);
            }
        }
        else //Остается случай, когда символ - оператор
        {
            int priorityOfLineOperand = getPriority(firstLine[q]);
            while (!isEmptyStackChar(stack))
            {
                if (peekStackChar(stack) == '(' || !(priorityOfLineOperand <= getPriority(peekStackChar(stack))))
                {
                    break;
                }
                topSymbol = popStackChar(stack);
                secondLine[counter] = topSymbol;
                counter++;
            }
            pushStackChar(stack, firstLine[q]);
        }
    }
    while (!isEmptyStackChar(stack))
    {
        topSymbol = popStackChar(stack);
        secondLine[counter] = topSymbol;
        counter++;
    }
    deleteStackChar(stack);
}

double getResult(char symbol, double digitOne, double digitTwo)
{
    if (symbol == '+')
    {
        return (digitOne + digitTwo);
    }
    else if (symbol == '-')
    {
        return (digitOne - digitTwo);
    }
    else if (symbol == '*')
    {
        return (digitOne * digitTwo);
    }
    else
    {
        return (digitOne / digitTwo);
    }
}

double calculate(char *line, const int size)
{
    char postfixLine[size];
    changeToPostfix(line, postfixLine);
    StackDouble *stack = createStackDouble();
    for (unsigned q = 0; q < strlen(postfixLine); q++)
    {
        if (isspace(postfixLine[q]))
        {
            continue;
        }
        if (isdigit(postfixLine[q]))
        {
            pushStackDouble(stack, static_cast<double>(postfixLine[q]) - 48);
        }
        else
        {
            double current = popStackDouble(stack);
            double previous = popStackDouble(stack);
            pushStackDouble(stack, getResult(postfixLine[q], previous, current));
        }
    }
    double result = popStackDouble(stack);
    deleteStackDouble(stack);
    return result;
}

