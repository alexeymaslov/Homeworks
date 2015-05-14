#pragma once
#include "list.h"

struct DoublyLinkedListElement;

class DoublyLinkedList : public List
{
public:
    DoublyLinkedList();
    void addElement(int value);
    void removeElement(int value);
    bool exists(int value);
    bool isEmpty();
    ~DoublyLinkedList();
private:
    DoublyLinkedListElement* top;
    DoublyLinkedListElement* createElement(DoublyLinkedListElement* previous, int value, DoublyLinkedListElement* next);
};
