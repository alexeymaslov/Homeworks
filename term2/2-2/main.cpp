#include "arraystacktest.h"
#include "linkedstacktest.h"
#include "calculatortest.h"


int main()
{
    freopen("testing.log", "w", stdout);

    ArrayStackTest testArrayStack;
    QTest::qExec(&testArrayStack);

    LinkedStackTest testLinkedStack;
    QTest::qExec(&testLinkedStack);

    CalculatorTest testCalculator;
    QTest::qExec(&testCalculator);
}
