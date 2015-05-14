#pragma once

template <typename T>
struct PriorityQueueElement;

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue();
    ///Adds an element with such value and priority to the queue
    void enqueue(T value, int priorityValue);
    ///Returns the first value with max priority (from the top of the queue)
    T dequeue();
    ///Returns current size of queue
    int getSize();
    ~PriorityQueue();
private:
    ///Returns true if there are no elements in queue, else returns false
    bool isEmpty();
    int size;
    PriorityQueueElement<T>* top;
    PriorityQueueElement<T>* createPriorityQueueElement(T value, int priorityValue, PriorityQueueElement<T>* next);
};

template <typename T>
struct PriorityQueueElement
{
    PriorityQueueElement* next;
    int priorityValue;
    T value;
};

template <typename T>
PriorityQueueElement<T>* PriorityQueue<T>::createPriorityQueueElement(T value, int priorityValue, PriorityQueueElement<T>* next)
{
    PriorityQueueElement<T>* newElement = new PriorityQueueElement<T>;
    newElement->next = next;
    newElement->priorityValue = priorityValue;
    newElement->value = value;
    return newElement;
}

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    top = createPriorityQueueElement(0, 0, nullptr);
    size = 0;
}

template <typename T>
void PriorityQueue<T>::enqueue(T value, int priorityValue)
{
    PriorityQueueElement<T>* current = top;
    while (current->next && current->next->priorityValue >= priorityValue)
        current = current->next;
    if (current->next)
        current->next = createPriorityQueueElement(value, priorityValue, current->next);
    else
        current->next = createPriorityQueueElement(value, priorityValue, nullptr);
    size++;
}

template <typename T>
bool PriorityQueue<T>::isEmpty()
{
    return !top->next;
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    if (isEmpty())
        return 0;
    else
    {
        PriorityQueueElement<T>* pointerToRemoved = top->next;
        T removedValue = pointerToRemoved->value;
        top->next = top->next->next;
        delete pointerToRemoved;
        size--;
        return removedValue;
    }
}

template <typename T>
int PriorityQueue<T>::getSize()
{
    return size;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    PriorityQueueElement<T>* current = top;
    while (current)
    {
        PriorityQueueElement<T>* pointerToRemoved = current;
        current = current->next;
        delete pointerToRemoved;
    }
}
