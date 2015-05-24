#include <iostream>
#include "listscomparatortest.h"
#include "linkedlisttest.h"
#include "sortedsettest.h"


int main()
{
    freopen("testing.log", "w", stdout);
    LinkedListTest testLinkedList;
    QTest::qExec(&testLinkedList);
    ListsComparatorTest testListsComparator;
    QTest::qExec(&testListsComparator);
    SortedSetTest testSortedSet;
    QTest::qExec(&testSortedSet);

}
