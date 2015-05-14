#include "stackOfDouble.h"

struct StackDoubleElement
{
    double value;
    StackDoubleElement *next;
};


struct StackDouble
{
    StackDoubleElement *top;
};

StackDoubleElement *createStackDoubleElement(double value, StackDoubleElement *next)
{
    StackDoubleElement *newStackElement = new StackDoubleElement;
    newStackElement->next = next;
    newStackElement->value = value;
    return newStackElement;
}

StackDouble *createStackDouble()
{
    StackDouble *newStack = new StackDouble;
    newStack->top = createStackDoubleElement(0, nullptr);
    return newStack;
}

void pushStackDouble(StackDouble *stack, double value)
{
    StackDoubleElement *newElement = createStackDoubleElement(value, stack->top->next);
    stack->top->next = newElement;
}

double popStackDouble(StackDouble *stack)
{
    double result = stack->top->next->value;
    StackDoubleElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

double peekStackDouble(StackDouble *stack)
{
    return stack->top->next->value;
}

bool isEmptyStackDouble(StackDouble *stack)
{
    return stack->top->next == nullptr;
}

void deleteStackDouble(StackDouble *stack)
{
    while (!isEmptyStackDouble(stack))
        popStackDouble(stack);
    delete stack->top;
    delete stack;
}



