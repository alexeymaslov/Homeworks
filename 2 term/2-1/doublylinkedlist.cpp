#include "doublylinkedlist.h"

struct DoublyLinkedListElement
{
    DoublyLinkedListElement* previous;
    int value;
    DoublyLinkedListElement* next;
};

DoublyLinkedListElement* DoublyLinkedList::createElement(DoublyLinkedListElement* previous, int value,
                                                         DoublyLinkedListElement* next)
{
    DoublyLinkedListElement* newElement = new DoublyLinkedListElement;
    newElement->previous = previous;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}

DoublyLinkedList::DoublyLinkedList()
{
    top = createElement(nullptr, 0, nullptr);
}

void DoublyLinkedList::addElement(int value)
{
    DoublyLinkedListElement* current = top;
    while (current->next)
        current = current->next;
    current->next = createElement(current, value, nullptr);
}

void DoublyLinkedList::removeElement(int value)
{
    DoublyLinkedListElement* current = top;
    while (current->next)
    {
        if (current->next->value == value)
        {
            DoublyLinkedListElement* pointerToRemoved = current->next;
            current->next = current->next->next;
            if (current->next)
                current->next->previous = current;
            delete pointerToRemoved;
            return;
        }
        current = current->next;
    }
}

bool DoublyLinkedList::exists(int value)
{
    DoublyLinkedListElement* current = top;
    while (current->next)
    {
        if (current->next->value == value)
            return true;
        current = current->next;
    }
    return false;
}

bool DoublyLinkedList::isEmpty()
{
    return !top->next;
}

DoublyLinkedList::~DoublyLinkedList()
{
    DoublyLinkedListElement* current = top;
    while (current->next)
    {
        DoublyLinkedListElement* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}

