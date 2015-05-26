#pragma once

template <typename T>
class Stack
{
public:
    virtual ~Stack() {}
    ///Adds a new element with the value
    virtual void push(const T &value) = 0;
    ///Gets and removes the top element
    virtual T pop() = 0;
    ///Gets the top element without removing it
    virtual T peek() = 0;
    ///Returns true if stack has no elements
    virtual bool isEmpty() = 0;
    ///Gets the size of the stack
    virtual int getSize() = 0;
};
