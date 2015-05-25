#include "calculatorwindow.h"
#include <QApplication>
#include "calculatortest.h"

int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    CalculatorTest testCalculator;
    QTest::qExec(&testCalculator);

    QApplication a(argc, argv);
    CalculatorWindow w;
    w.show();

    return a.exec();
}
