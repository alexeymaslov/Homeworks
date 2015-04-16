#include "singlylinkedlist.h"

struct SinglyLinkedListElement
{
    int value;
    SinglyLinkedListElement* next;
};

SinglyLinkedListElement* SinglyLinkedList::createElement(int value, SinglyLinkedListElement* next)
{
    SinglyLinkedListElement* newElement = new SinglyLinkedListElement;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}

SinglyLinkedList::SinglyLinkedList()
{
    top = createElement(0, nullptr);
}

void SinglyLinkedList::addElement(int value)
{
    SinglyLinkedListElement* current = top;
    while (current->next)
        current = current->next;
    current->next = createElement(value, nullptr);
}

bool SinglyLinkedList::exists(int value)
{
    SinglyLinkedListElement* current = top;
    while (current->next)
    {
        if (current->next->value == value)
            return true;
        current = current->next;
    }
    return false;
}

bool SinglyLinkedList::isEmpty()
{
    return !top->next;
}

void SinglyLinkedList::removeElement(int value)
{
    SinglyLinkedListElement* current = top;
    while (current->next)
    {
        if (current->next->value == value)
        {
            SinglyLinkedListElement* pointerToRemoved = current->next;
            current->next = current->next->next;
            delete pointerToRemoved;
            return;
        }
        current = current->next;
    }
}

SinglyLinkedList::~SinglyLinkedList()
{
    SinglyLinkedListElement* current = top;
    while (current->next)
    {
        SinglyLinkedListElement* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}

