#include "sortertest.h"

int main()
{
    freopen("testing.log", "w", stdout);
    SorterTest testSorter;
    QTest::qExec(&testSorter);
    return 0;
}
