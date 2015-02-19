#include "stackOfChar.h"

struct StackCharElement
{
    char symbol;
    StackCharElement *next;
};


struct StackChar
{
    StackCharElement *top;
};

StackCharElement *createStackCharElement(char symbol, StackCharElement *next)
{
    StackCharElement *newStackElement = new StackCharElement;
    newStackElement->next = next;
    newStackElement->symbol = symbol;
    return newStackElement;
}

StackChar *createStackChar()
{
    StackChar *newStack = new StackChar;
    newStack->top = createStackCharElement('a', nullptr);
    return newStack;
}

void pushStackChar(StackChar *stack, char symbol)
{
    StackCharElement *newElement = createStackCharElement(symbol, stack->top->next);
    stack->top->next = newElement;
}

char popStackChar(StackChar *stack)
{
    char result = stack->top->next->symbol;
    StackCharElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

char peekStackChar(StackChar *stack)
{
    return stack->top->next->symbol;
}

bool isEmptyStackChar(StackChar *stack)
{
    return stack->top->next == nullptr;
}

void deleteStackChar(StackChar *stack)
{
    while (!isEmptyStackChar(stack))
        popStackChar(stack);
    delete stack->top;
    delete stack;
}

