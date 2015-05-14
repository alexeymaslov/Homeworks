#include <iostream>
#include <cstring>
#include <cmath>
#include "queue.h"

using namespace std;

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

void updateHash(int &hash, char* line, int positionOfNewSymbol, int size, const int mod, const int power)
{
    int positionOfOldSymbol = positionOfNewSymbol - size;
    const int maxExponent = (int)pow(power, size - 1) % mod;
    hash = ((((hash - (line[positionOfOldSymbol] * maxExponent) % mod) * 7) % mod) + line[positionOfNewSymbol]) % mod;
}

int hashFunction(char* line, int start, int size, const int mod, const int power)
{
    int exponent = 1;
    int sum = 0;
    for (int i  = start + size - 1; i >= 0; i--)
    {
        sum = (sum + (line[i] * exponent) % mod) % mod;
        exponent = (exponent * power) % mod;
    }
    return sum;
}

void algorithmOfRabinKarp(char* line, char* subLine)
{
    int lengthOfLine = strlen(line);
    int lengthOfSubLine = strlen(subLine);

    const int mod = 83;
    const int power = 7;
    int hashSubLine = hashFunction(subLine, 0, lengthOfSubLine, mod, power);
    int hashLine = hashFunction(line, 0, lengthOfSubLine, mod, power);
    bool foundNothing = true;
    for (int q = 0; q <= lengthOfLine - lengthOfSubLine; q++)
    {
        if (hashLine == hashSubLine)
        {
            char* cutLine = new char[lengthOfSubLine];
            strncpy(cutLine, line + q, lengthOfSubLine);
            cutLine[lengthOfSubLine] = '\0';
            if (!strcmp(cutLine, subLine))
            {
                foundNothing = false;
                cout << "Subline appears at " << q << " symbol" << endl;
            }
            delete []cutLine;
        }
        updateHash(hashLine, line, lengthOfSubLine + q, lengthOfSubLine, mod, power);
    }
    if (foundNothing)
        cout << "Have not found any appearances.";\
}

//nafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhgnafclaldskhgifaluhg

int main()
{
    cout << "Input a line: ";
    char* line = getLine();
    cout << "Input a subline: ";
    char* subLine = getLine();
    algorithmOfRabinKarp(line, subLine);
    delete []line;
    delete []subLine;

}

