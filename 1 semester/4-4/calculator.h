#pragma once

int getPriority(char symbol);
void changeToPostfix(char *firstLine, char *secondLine);
double getResult(char symbol, double digitOne, double digitTwo);
double calculate(char *line, const int size);
