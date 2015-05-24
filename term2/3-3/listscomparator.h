#pragma once
#include "linkedlist.h"

class ListsComparator
{
public:
    enum Comparison
    {
        less = -1, equal, bigger
    };
    /// Compares two lists. Returns bigger = 1 if size of first list is bigger than second's size,
    /// returns less = -1 if first's size is less, else returns equal = 0 if lists' sizes are equal
    /// (even if lists have different values)
    static Comparison compare(LinkedList* listOne, LinkedList* listTwo);
};

