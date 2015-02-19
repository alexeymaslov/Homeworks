#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

enum
{
    start, hasSignInMantiss, hasMantiss, hasCommaAfterMantiss, hasFloatMantiss, hasExponent, hasSignInPower, hasPower
};

char* getLine()
{
    char symbol = 'a';
    int length = 0;
    Queue* queue = createQueue();
    cout << "Input expression: ";
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

int move(int state, char symbol, bool &legit)
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

bool lexicalCheck(char* line, int &position, int maxLength)
{
    int state = 0;
    bool legit = true;
    position--;
    while (legit)
    {
        position++;
        if (position == maxLength)
            break;
        state = move(state, line[position], legit);
    }
    if (state == hasMantiss || state == hasFloatMantiss || state == hasPower)
        return true;
    else
        return false;
}

//Я использовал следующую грамматику:
//A->BC
//C->+BC|eps
//B->DE
//E->*DE|eps
//D->(A)|digit
//Я не смог придумать подходящие имена, поэтому назвал функции соответствующе.

void A(char* line, int &position, int maxLength);

void D(char* line, int &position, int maxLength)
{
    if (position < maxLength)
    {
        if (line[position] == '(')
        {
            position++;
            A(line, position, maxLength);
            if (!(line[position] == ')' && position < maxLength))
            {
                cout << "Syntactic error in position " << position << endl;
                position = maxLength + 1;
                return;
            }
            position++;
        }
        else if (isdigit(line[position]) || line[position] == '+' || line[position] == '-')
        {
            if (!lexicalCheck(line, position, maxLength))
            {
                cout << "Lexical error in position " << position << endl;
                position = maxLength + 1;
            }
        }
        else
        {
            cout << "Syntactic error in position " << position << endl;
            position = maxLength + 1;
        }
    }
}

void E(char* line, int &position, int maxLength)
{
    if (position < maxLength)
    {
        if (line[position] == '*' || line[position] == '/')
        {
            position++;
            if (position == maxLength)
            {
                cout << "Syntactic error in position " << position << endl;
                position = maxLength + 1;
                return;
            }
            else
            {
                D(line, position, maxLength);
                E(line, position, maxLength);
            }
        }
    }
}

void B(char* line, int &position, int maxLength)
{
    if (position < maxLength)
    {
        D(line, position, maxLength);
        E(line, position, maxLength);
    }
}

void C(char* line, int &position, int maxLength)
{
    if (position < maxLength)
    {
        if (line[position] == '+' || line[position] == '-')
        {
            position++;
            if (position == maxLength)
            {
                cout << "Syntactic error in position " << position << endl;
                position = maxLength + 1;
                return;
            }
            else
            {
                B(line, position, maxLength);
                C(line, position, maxLength);
            }
        }
    }
}

void A(char* line, int &position, int maxLength)
{
    if (position < maxLength)
    {
        B(line, position, maxLength);
        C(line, position, maxLength);
    }
}

void syntacticCheck(char* line)
{
    int length = strlen(line);
    int position = 0;
    A(line, position, length);
    if (position == length)
        cout << "OK";
    else if (position < length)
        cout << "There is some uncaught error.";
}

int main()
{
    char *line = getLine();
    syntacticCheck(line);
    delete []line;
}

