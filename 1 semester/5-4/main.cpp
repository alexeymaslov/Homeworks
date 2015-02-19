#include <iostream>
#include "phonebookList.h"

using namespace std;

enum UserInput
{
    quit, addNote, findName, findNumber, save
};

void printInstructions()
{
    cout << "********************" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Add note" << endl;
    cout << "2 - Find notes with name" << endl;
    cout << "3 - Find note with phonenumber" << endl;
    cout << "4 - Save phonebook into file" << endl;
    cout << "Input a command: ";
}

int main()
{
    PhonebookList *list = createList();

    char letter = 'a';
    cout << "To get the phonebook from the file? (y / n): ";
    cin >> letter;
    if (letter == 'y')
    {
        getListFromFile(list);
    }

    char name[30];
    unsigned int number = 0;
    int digit = addNote;
    while (digit)
    {
        printInstructions();
        cin >> digit;
        UserInput input = (UserInput)digit;
        switch (input)
        {
            case quit:
            {
                deleteList(list);
                cout << "Bye.";
                break;
            }
            case addNote:
            {
                cout << "Input a name: ";
                cin >> name;
                cout << "Input a phonenumber: ";
                cin >> number;
                addElement(list, name, number);
                break;
            }
            case findName:
            {
                cout << "Input a name: ";
                cin >> name;
                printElementsWithName(list, name);
                break;
            }
            case findNumber:
            {
                cout << "Input a phonenumber: ";
                cin >> number;
                printElementWithNumber(list, number);
                break;
            }
            case save:
            {
                putListIntoFile(list);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

