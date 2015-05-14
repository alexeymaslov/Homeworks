#include "mystring.h"

struct MyString
{
    char *line;
};

int getLengthOfCharLine(char* line)
{
    int q = 0;
    while (line[q] != '\0')
        q++;
    return q;
}

char* getNewLine(char* line)
{
    int length = getLengthOfCharLine(line);
    char* newLine = new char[length + 1];
    for (int q = 0; q <= length; q++)
        newLine[q] = line[q];
    return newLine;
}

MyString* createString(char* line)
{
    MyString* newString = new MyString;
    newString->line = getNewLine(line);
    return newString;
}

void deleteString(MyString* string)
{
    delete []string->line;
    delete string;
}

MyString* clone(MyString* string)
{
    return createString(string->line);
}

void concat(MyString* stringOne, MyString* stringTwo)
{
    int lengthOne = length(stringOne);
    int lengthTwo = length(stringTwo);
    char* newLine = new char[lengthOne + lengthTwo + 1];
    for (int q = 0; q < lengthOne; q++)
        newLine[q] = stringOne->line[q];
    for (int q = lengthOne; q <= lengthTwo + lengthOne; q++)
        newLine[q] = stringTwo->line[q - lengthOne];
    delete []stringOne->line;
    stringOne->line = newLine;
}

bool isEqual(MyString* stringOne, MyString* stringTwo)
{
    for (int q = 0; q <= length(stringOne); q++)
        if (stringOne->line[q] != stringTwo->line[q])
            return false;
    return true;
}

int length(MyString* string)
{
    return getLengthOfCharLine(string->line);
}

bool isEmpty(MyString* string)
{
    if (string->line[0] == '\0')
        return true;
    else
        return false;
}

MyString* getSubstring(MyString* string, int start, int end)
{
    int lengthOfString = length(string);
    if (end >= lengthOfString)
        end = lengthOfString - 1;
    int length = end - start + 1;

    char* newLine = new char[length];
    for (int q = 0; q < length; q++)
        newLine[q] = string->line[start + q];
    newLine[length] = '\0';

    MyString* newString = new MyString;
    newString->line = newLine;
    return newString;
}

char* changeToChar(MyString* string)
{
    return getNewLine(string->line);
}

char getISymbol(MyString* string, int i)
{
    return string->line[i];
}
