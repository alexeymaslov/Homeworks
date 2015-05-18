#include "listscomparator.h"

ListsComparator::Comparison ListsComparator::compare(LinkedList* listOne, LinkedList* listTwo)
{
    int sizeOne = listOne->getSize();
    int sizeTwo = listTwo->getSize();
    if (sizeOne > sizeTwo)
        return bigger;
    else if (sizeOne < sizeTwo)
        return less;
    else
        return equal;
}
