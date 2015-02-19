#include <iostream>
using namespace std;

void printDecompositions(int left, int currentValue, int positionCounter, int number, int *values)
{
    if (left < 0 || currentValue == number)
    {
        return;
    }
    values[positionCounter] = currentValue;
    if (currentValue != 0)
    {
        printDecompositions(left - currentValue, currentValue, positionCounter + 1, number, values);
    }
    printDecompositions(left - 1, currentValue + 1, positionCounter, number, values);
    if (left == 0)
    {
        for (int w = 0; w <= positionCounter; w++)
        {
            cout << values[w];
            if (w != positionCounter)
            {
                cout << "+";
            }
            else
                cout << endl;
        }
    }
}

int main()
{
    int number = 0;
    int values[100];
    cout << "Input number: ";
    cin >> number;
    cout << "Decompositions:" << endl;
    printDecompositions(number, 0, 0, number, values);
    return 0;
}
