#pragma once

struct StackDoubleElement;

struct StackDouble;

StackDouble *createStackDouble();

void pushStackDouble(StackDouble *stack, double value);

double popStackDouble(StackDouble *stack);

double peekStackDouble(StackDouble *stack);

void deleteStackDouble(StackDouble *stack);

bool isEmptyStackDouble(StackDouble *stack);
