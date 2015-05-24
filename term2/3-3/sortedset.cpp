#include "sortedset.h"
#include "listscomparator.h"

SortedSet::SortedSetElement::SortedSetElement(LinkedList* list, SortedSetElement* next) : list(list), next(next)
{}

SortedSet::SortedSetElement::~SortedSetElement()
{
    delete list;
}

SortedSet::SortedSet() : top(new SortedSetElement(nullptr, nullptr))
{}

SortedSet::~SortedSet()
{
    SortedSetElement* current = top;
    while (current)
    {
        SortedSetElement* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}

void SortedSet::add(LinkedList* list)
{
    SortedSetElement* current = top;
    while (current->next && ListsComparator::compare(current->next->list, list) == ListsComparator::less)
        current = current->next;
    if (current->next && ListsComparator::compare(list, current->next->list) == ListsComparator::equal)
    {
        delete current->next->list;
        current->next->list = list;
        return;
    }
    SortedSetElement* newElement = new SortedSetElement(list, current->next);
    current->next = newElement;
}

LinkedList* SortedSet::at(int index)
{
    int j = -1;
    SortedSetElement* current = top;
    while (current->next && j < index)
    {
        current = current->next;
        j++;
    }
    if (j < index)
        return nullptr;
    else
        return current->list;
}
