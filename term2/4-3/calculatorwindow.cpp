#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include "calculator.h"

CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);

    QPushButton *buttons[16];
    buttons[0] = ui->value0Button;
    buttons[1] = ui->value1Button;
    buttons[2] = ui->value2Button;
    buttons[3] = ui->value3Button;
    buttons[4] = ui->value4Button;
    buttons[5] = ui->value5Button;
    buttons[6] = ui->value6Button;
    buttons[7] = ui->value7Button;
    buttons[8] = ui->value8Button;
    buttons[9] = ui->value9Button;
    buttons[10] = ui->additionButton;
    buttons[11] = ui->subtractionButton;
    buttons[12] = ui->multiplicationButton;
    buttons[13] = ui->divisionButton;
    buttons[14] = ui->pointButton;
    buttons[15] = ui->equalSignButton;
    for (int i = 0; i < 10; i++)
        signalMapper->setMapping(buttons[i], '0' + i);
    signalMapper->setMapping(buttons[10], '+');
    signalMapper->setMapping(buttons[11], '-');
    signalMapper->setMapping(buttons[12], '*');
    signalMapper->setMapping(buttons[13], '/');
    signalMapper->setMapping(buttons[14], '.');
    signalMapper->setMapping(buttons[15], '=');

    for (int i = 0; i < 16; i++)
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(newSymbolAppeared(int)));
}

CalculatorWindow::~CalculatorWindow()
{
    delete signalMapper;
    delete ui;
}

void CalculatorWindow::newSymbolAppeared(int symbol)
{
    if (symbol == '=')
        outputString = QString::number(Calculator::calculate(outputString));
    else
        outputString += symbol;
    ui->outputLine->setText(outputString);
}
