#pragma once
#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = 0);
    ~CalculatorWindow();
    QString inputLine;

private slots:
    void newSymbolAppeared(int symbol);

private:
    Ui::CalculatorWindow *ui;
    QSignalMapper *signalMapper;
    QString outputString;
};

