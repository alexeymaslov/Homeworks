#include <iostream>
#include "bst.h"

using namespace std;

enum UserInput
{
    quit, addDigitToSet, removeDigitFromSet, checkIfDigitIs, printSetAscending, printSetDescending, printSetPreorder
};

void printInstructions()
{
    cout << "**********\n";
    cout << "0 - exit\n";
    cout << "1 - add digit\n";
    cout << "2 - remove digit\n";
    cout << "3 - check if digit is in the set\n";
    cout << "4 - print ascending\n";
    cout << "5 - print descending\n";
    cout << "6 - print in (a b c) way\n";
}

void addDigit(Tree* tree)
{
    int digit = 0;
    cout << "Input a digit: ";
    cin >> digit;
    addElement(tree, digit);
}

void removeDigit(Tree* tree)
{
    int digit = 0;
    cout << "Input a digit: ";
    cin >> digit;
    removeElement(tree, digit);
}

void checkDigit(Tree* tree)
{
    int digit = 0;
    cout << "Input a digit: ";
    cin >> digit;
    if (exists(tree, digit))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    Tree* tree = createTree();
    UserInput number = addDigitToSet;
    while (number != quit)
    {
        printInstructions();
        cout << "Enter a command: ";
        int inputValue = 0;
        cin >> inputValue;
        number = (UserInput)inputValue;
        switch (number)
        {
            case quit:
                deleteTree(tree);
                break;
            case addDigitToSet:
                addDigit(tree);
                break;
            case removeDigitFromSet:
                removeDigit(tree);
                break;
            case checkIfDigitIs:
                checkDigit(tree);
                break;
            case printSetAscending:
                printAscending(tree);
                break;
            case printSetDescending:
                printDescending(tree);
                break;
            case printSetPreorder:
                printPreorder(tree);
                break;
        }
    }
}
