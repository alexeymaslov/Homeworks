#pragma once

struct StackCharElement;

struct StackChar;

StackChar *createStackChar();

void pushStackChar(StackChar *stack, char symbol);

char popStackChar(StackChar *stack);

char peekStackChar(StackChar *stack);

void deleteStackChar(StackChar *stack);

bool isEmptyStackChar(StackChar *stack);

