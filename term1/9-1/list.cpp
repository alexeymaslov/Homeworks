#include <iostream>
#include "list.h"
#include "mystring.h"

using namespace std;

struct Element
{
    MyString* string;
    Element* next;
};

struct List
{
    Element* head;
};

Element* createElement(MyString* string, Element* next)
{
    Element* newElement = new Element;
    newElement->string = string;
    newElement->next = next;
    return newElement;
}

List* createList()
{
    List* list = new List;
    list->head = createElement(nullptr, nullptr);
    return list;
}

void addElementToList(List* list, MyString* string)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        if (isEqual(string, current->string))
            return;
    }
    current->next = createElement(string, nullptr);
}

void removeElementWithSuchString(List* list, MyString* string)
{
    Element* current = list->head;
    Element* previous = list->head;
    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;
        if (isEqual(current->string, string))
        {
            previous->next = current->next;
            deleteString(current->string);
            delete current;
        }
    }
}

bool isEmpty(List* list)
{
    return !list->head->next;
}

void deleteList(List* list)
{
    if (!isEmpty(list))
    {
        Element* current = list->head->next;
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

bool belongsToList(List* list, MyString* string)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        if (isEqual(current->string, string))
            return true;
    }
    return false;
}

MyString* pop(List* list)
{
    Element* top = list->head->next;
    list->head->next = list->head->next->next;
    MyString* line = top->string;
    delete top;
    return line;
}

void printList(List* list)
{
    Element* current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        cout << changeToChar(current->string) << endl;
    }
}
