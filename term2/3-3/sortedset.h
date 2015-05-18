#pragma once
#include "linkedlist.h"

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();
    ///Adds list to set with ascending order. If there is list with same size in set,
    ///deletes old list and adds new one instead
    void add(LinkedList* list);
    ///Returns pointer to the list with such index
    LinkedList* at(int index);
private:
    class SortedSetElement
    {
    public:
        SortedSetElement(LinkedList* list, SortedSetElement* next);
        ~SortedSetElement();
        LinkedList* list;
        SortedSetElement* next;
    };
    SortedSetElement* top;
};

