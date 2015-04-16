#include "singlylinkedlisttest.h"
#include "doublylinkedlisttest.h"

int main()
{
    freopen("testing.log", "w", stdout);

    SinglyLinkedListTest testSinglyLinkedList;
    QTest::qExec(&testSinglyLinkedList);

    DoublyLinkedListTest testDoublyLinkedList;
    QTest::qExec(&testDoublyLinkedList);
    return 0;
}
