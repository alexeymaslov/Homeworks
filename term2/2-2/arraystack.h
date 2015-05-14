#pragma once
#include "stack.h"

template <typename T>
class ArrayStack : public Stack<T>
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    int getSize();
private:
    void expandStack();
    T* numbers;
    int topIndex;
    int size;
};

template <typename T>
ArrayStack<T>::ArrayStack()
{
    size = 10;
    numbers = new T[size];
    topIndex = -1;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    delete[] numbers;
}

template <typename T>
void ArrayStack<T>::expandStack()
{
    size = size * 2;
    T* newArray = new T[size];
    for (int i = 0; i < topIndex; i++)
        newArray[i] = numbers[i];
    delete[] numbers;
    numbers = newArray;
}

template <typename T>
void ArrayStack<T>::push(T value)
{
    topIndex++;
    if (topIndex == size)
        expandStack();
    numbers[topIndex] = value;
}

template <typename T>
bool ArrayStack<T>::isEmpty()
{
    return topIndex == -1;
}

template <typename T>
T ArrayStack<T>::pop()
{
    if (isEmpty())
        return 0;
    return numbers[topIndex--];
}

template <typename T>
T ArrayStack<T>::peek()
{
    if (isEmpty())
        return 0;
    return numbers[topIndex];
}

template <typename T>
int ArrayStack<T>::getSize()
{
    return topIndex + 1;
}
