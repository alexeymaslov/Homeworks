#include "linkedlist.h"

LinkedList::LinkedListElement::LinkedListElement(int value, LinkedListElement* next) : value(value), next(next)
{}

LinkedList::LinkedListElement::~LinkedListElement()
{}

LinkedList::LinkedList() : top(new LinkedListElement(0, nullptr)), size(0)
{}

LinkedList::~LinkedList()
{
    LinkedListElement* current = top;
    while (current->next)
    {
        LinkedListElement* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}

void LinkedList::add(int value)
{
    LinkedListElement* current = top;
    while (current->next)
        current = current->next;
    current->next = new LinkedListElement(value, nullptr);
    size++;
}

int LinkedList::at(int index)
{
    int j = -1;
    LinkedListElement* current = top;
    while (current->next && j < index)
    {
        current = current->next;
        j++;
    }
    if (j < index)
        return 0;
    else
        return current->value;
}

int LinkedList::getSize()
{
    return size;
}
