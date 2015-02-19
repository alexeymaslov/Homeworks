#include "phonebookList.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

struct Element
{
    char name[30];
    unsigned int number;
    Element *next;
};

struct PhonebookList
{
    Element *head;
};

Element *createElement(char name[], unsigned int number, Element *next)
{
    Element *newElement = new Element;
    unsigned int q = 0;
    while (q < strlen(name))
    {
        newElement->name[q] = name[q];
        q++;
    }
    newElement->name[q] = '\0'; //Пришлось добавить, потому что иногда программа сама добавляла к имени случайные символы
    newElement->number = number;
    newElement->next = next;
    return newElement;
}

PhonebookList *createList()
{
    PhonebookList *list = new PhonebookList;
    char name[2] = "0";
    list->head = createElement(name, 0, nullptr);
    return list;
}

void addElement(PhonebookList *list, char name[], unsigned int number)
{
    Element *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    Element *newElement = createElement(name, number, nullptr);
    current->next = newElement;
}

void printElementsWithName(PhonebookList *list, char name[])
{
    Element *current = list->head->next;
    unsigned int length = strlen(name);
    bool somethingWasPrinted = false;
    while (current != nullptr)
    {
        if (strlen(current->name) == length)
        {
            bool areSame = true;
            unsigned int q = 0;
            while (areSame && q < length)
            {
                if (current->name[q] != name[q])
                {
                    areSame = false;
                }
                q++;
            }
            if (areSame)
            {
                cout << current->name << " " << current->number << endl;
                somethingWasPrinted = true;
            }
        }
        current = current->next;
    }
    if (!somethingWasPrinted)
    {
        cout << "No notes with such name." << endl;
    }
}

void printElementWithNumber(PhonebookList *list, unsigned int number)
{
    Element *current = list->head->next;
    bool somethingWasPrinted = false;
    while (current != nullptr)
    {
        if (current->number == number)
        {
            cout << current->name << " " << number << endl;
            somethingWasPrinted = true;
        }
        current = current->next;
    }
    if (!somethingWasPrinted)
    {
        cout << "No notes with such number" << endl;
    }
}

void putListIntoFile(PhonebookList *list)
{
    const int lengthOfAddress = 100;
    char address[lengthOfAddress];
    char letter = 'a';
    ofstream file;
    cout << "(1)Create a new file or (2)add notes to an old one?" << endl
         << "Enter 1 / 2: ";
    cin >> letter;
    cout << "Input way to file: ";
    cin.ignore();
    cin.getline(address, lengthOfAddress);
    if (letter == '2')
    {
        file.open(address, ios::app);
    }
    else
    {
        file.open(address, ios::out);
    }
    Element *current = list->head->next;
    while (current != nullptr)
    {
        file << current->name << " " << current->number << endl;
        current = current->next;
    }
    file.close();
}

void deleteList(PhonebookList *list)
{
    Element *current = list->head;
    while(current != nullptr)
    {
        Element *previous = current;
        current = current->next;
        delete previous;
    }
    delete list;
}

void getListFromFile(PhonebookList *list)
{
    const int lengthOfAddress = 100;
    char address[lengthOfAddress];
    cout << "Input way to file: ";
    cin.ignore();
    cin.getline(address, lengthOfAddress);
    ifstream file;
    file.open(address, ios::in);
    if (file)
    {
        while(!file.eof())
        {
            char name[30];
            unsigned int number = 0;
            file >> name;
            file >> number;
            addElement(list, name, number);
        }
    }
    else
    {
        cout << "Error. File does not exist." << endl;
    }
    file.close();
}

