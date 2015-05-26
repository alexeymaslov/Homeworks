#pragma once

class Calculator
{
public:
    static double calculate(char* line);
private:
    static void changeToPostfix(char* &line);
    static int getPriority(char symbol);
    static double getResult(char symbol, double digitOne, double digitTwo);
    static double getDigit(char* line, int& index);
};
