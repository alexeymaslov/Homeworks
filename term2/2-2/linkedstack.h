#pragma once
#include "stack.h"

template <typename T>
struct LinkedStackElement
{
    LinkedStackElement* next;
    T value;
};

template <typename T>
class LinkedStack : public Stack<T>
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(const T &value);
    T pop();
    T peek();
    bool isEmpty();
    int getSize();
private:
    LinkedStackElement<T>* createLinkedStackElement(T value, LinkedStackElement<T>* next);
    int size;
    LinkedStackElement<T>* top;
};

template <typename T>
LinkedStackElement<T>* LinkedStack<T>::createLinkedStackElement(T value, LinkedStackElement<T>* next)
{
    LinkedStackElement<T>* newElement = new LinkedStackElement<T>;
    newElement->next = next;
    newElement->value = value;
    return newElement;
}

template <typename T>
LinkedStack<T>::LinkedStack() : size(0), top(createLinkedStackElement(0, nullptr))
{}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    LinkedStackElement<T>* current = top;
    while (current)
    {
        LinkedStackElement<T>* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}

template <typename T>
int LinkedStack<T>::getSize()
{
    return size;
}

template <typename T>
void LinkedStack<T>::push(const T &value)
{
    top->next = createLinkedStackElement(value, top->next);
    size++;
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
    return !top->next;
}

template <typename T>
T LinkedStack<T>::peek()
{
    if (isEmpty())
        return top->value;
    return top->next->value;
}

template <typename T>
T LinkedStack<T>::pop()
{
    if (isEmpty())
        return top->value;
    size--;
    LinkedStackElement<T>* pointerToRemoved = top->next;
    T poppedValue = pointerToRemoved->value;
    top->next = top->next->next;
    delete pointerToRemoved;
    return poppedValue;
}
