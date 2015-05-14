#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    const int sizeOfLine = 1000;
    char line[sizeOfLine];
    cout << "Input expression: ";
    cin.getline(line,sizeOfLine);
    cout << "Result: " << calculate(line, sizeOfLine);
}

