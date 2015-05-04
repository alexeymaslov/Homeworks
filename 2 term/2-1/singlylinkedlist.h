#pragma once
#include "list.h"

struct SinglyLinkedListElement;

class SinglyLinkedList : public List
{
public:
    SinglyLinkedList();
    void addElement(int value);
    void removeElement(int value);
    bool exists(int value);
    bool isEmpty();
    ~SinglyLinkedList();
private:
    SinglyLinkedListElement* top;
    SinglyLinkedListElement* createElement(int value, SinglyLinkedListElement* next);
};
