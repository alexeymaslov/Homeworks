#include <iostream>
#include "list.h"
#include "mystring.h"

using namespace std;

struct Element
{
    MyString* string;
    int amount;
    Element *next;
};

struct List
{
    Element *head;
};

Element *createElement(MyString* string, Element *next)
{
    Element *newElement = new Element;
    newElement->string = string;
    newElement->next = next;
    newElement->amount = 1;
    return newElement;
}

List *createList()
{
    List *list = new List;
    list->head = createElement(nullptr, nullptr);
    return list;
}

void addElementToList(List *list, MyString* string)
{
    Element *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        if (isEqual(string, current->string))
        {
            current->amount++;
            return;
        }
    }
    current->next = createElement(string, nullptr);
}

bool isEmpty(List* list)
{
    return !list->head->next;
}

void deleteList(List *list)
{
    if (!isEmpty(list))
    {
        Element *current = list->head->next;
        while (current->next != nullptr)
        {
            Element *pointerToCurrent = current;
            current = current->next;
            deleteString(pointerToCurrent->string);
            delete pointerToCurrent;
        }
    }
    delete list;
}

int howManyOfSuchElement(List* list, MyString* string)
{
    int amount = 0;
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        if (isEqual(current->string, string))
            amount++;
    }
    return amount;
}

int howManyElements(List* list)
{
    int amount = 0;
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        amount++;
    }
    return amount;
}

/*void copyElementsFromOneListToAnother(List* listOne, List* listTwo)
{
    Element* current = listOne->head;
    while (current->next != nullptr)
    {
        current = current->next;
        addElementToList(listTwo, current->string);
    }
}*/

void printList(List* list)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        cout << changeToChar(current->string) << endl;
    }
}

void printListInOneLine(List* list)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        cout << changeToChar(current->string);
        if (current->next != nullptr)
            cout << ", ";
    }
    cout << endl;
}

void printListInASpecialWayForHashTable(List* list)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        cout << changeToChar(current->string) << " " << current->amount << " times" << endl;
    }
}
