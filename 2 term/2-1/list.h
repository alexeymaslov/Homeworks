#pragma once

class List
{
public:
    ///Adds a new element with the value to the end of the list
    virtual void addElement(int value) = 0;

    ///Removes an element with such value
    virtual void removeElement(int value) = 0;

    ///Returns true if there is such value in the list, else returns false
    virtual bool exists(int value) = 0;

    ///Returns true if there are no elements in the list, else returns false
    virtual bool isEmpty() = 0;
};
