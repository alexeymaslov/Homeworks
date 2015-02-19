#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

enum State
{
    start, hasSignInMantiss, hasMantiss, hasCommaAfterMantiss, hasFloatMantiss, hasExponent, hasSignInPower, hasPower
};

char* getLine()
{
    char symbol = 'a';
    int length = 0;
    Queue* queue = createQueue();
    cin.get(symbol);
    while (symbol != '\n')
    {
        length++;
        enqueue(symbol, queue);
        cin.get(symbol);
    }
    char* line = new char[length + 1];
    for (int q = 0; q < length; q++)
    {
        line[q] = dequeue(queue);
    }
    line[length] = '\0';
    deleteQueue(queue);
    return line;
}

int move(State state, char symbol, bool &legit)
{
    switch (state)
    {
        case start:
        {
            if (symbol == '+' || symbol == '-')
                state = hasSignInMantiss;
            else if (isdigit(symbol))
                state = hasMantiss;
            else
                legit = false;
            break;
        }
        case hasSignInMantiss:
        {
            if (isdigit(symbol))
                state = hasMantiss;
            else
                legit = false;
            break;
        }
        case hasMantiss:
        {
            if (isdigit(symbol))
                state = hasMantiss;
            else if (symbol == '.')
                state = hasCommaAfterMantiss;
            else if (symbol == 'e' || symbol == 'E')
                state = hasExponent;
            else
                legit = false;
            break;
        }
        case hasCommaAfterMantiss:
        {
            if (isdigit(symbol))
                state = hasFloatMantiss;
            else
                legit = false;
            break;
        }
        case hasFloatMantiss:
        {
            if (isdigit(symbol))
                state = hasFloatMantiss;
            else if (symbol == 'e' || symbol == 'E')
                state = hasExponent;
            else
                legit = false;
            break;
        }
        case hasExponent:
        {
            if (symbol == '+' || symbol == '-')
                state = hasSignInPower;
            else if (isdigit(symbol))
                state = hasPower;
            else
                legit = false;
            break;
        }
        case hasSignInPower:
        {
            if (isdigit(symbol))
                state = hasPower;
            else
                legit = false;
            break;
        }
        case hasPower:
        {
            if (isdigit(symbol))
                state = hasPower;
            else
                legit = false;
            break;
        }
    }
    return state;
}

bool lexical(char* line, int &position, int maxLength)
{
    State state = start;
    bool legit = true;
    position--;
    while (legit)
    {
        position++;
        if (position == maxLength)
            break;
        state = move(state, line[position], legit);
    }
    return (state == hasMantiss || state == hasFloatMantiss || state == hasPower);
}

int main()
{
    char* line = getLine();
    int length = strlen(line);
    int position = 0;
    if (lexical(line, position, length) && position == length)
            cout << "OK";
    else
    {
        cout << "Not OK" << endl << "Error in position " << position;
    }
    delete []line;
}

