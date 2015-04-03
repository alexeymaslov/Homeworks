#include "priorityqueuetest.h"


int main()
{
    freopen("testing.txt", "w", stdout);

    PriorityQueueTest testPriorityQueue;
    QTest::qExec(&testPriorityQueue);
}
