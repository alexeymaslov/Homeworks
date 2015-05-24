#pragma once

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    ///Adds integer value to end of list
    void add(int value);
    ///Returns value with such index. If index is bigger than size of list or negative returns 0
    int at(int index);
    ///Returns size of list
    int getSize();
private:
    class LinkedListElement
    {
    public:
        LinkedListElement(int value, LinkedListElement* next);
        ~LinkedListElement();
        int value;
        LinkedListElement* next;
    };
    LinkedListElement* top;
    int size;
};
