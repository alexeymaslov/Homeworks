#include "queue.h"

struct Queue
{
    Element *top;
};

struct Element
{
    Element *next;
    int value;
};

Element *createElement(int value, Element *next)
{
    Element *newElement = new Element;
    newElement->next = next;
    newElement->value = value;
    return newElement;
}

Queue *createQueue()
{
    Queue *queue = new Queue;
    queue->top = createElement(0, nullptr);
    return queue;
}

void enqueue(int value, Queue *queue)
{
    Element *current = queue->top;
    while (current->next != nullptr)
        current = current->next;
    current->next = createElement(value, nullptr);
}

int dequeue(Queue *queue)
{
    Element *current = queue->top->next;
    queue->top->next = queue->top->next->next;
    int value = current->value;
    delete current;
    return value;
}

void deleteQueue(Queue *queue)
{
    while (queue->top->next != nullptr)
        dequeue(queue);
    delete queue->top;
    delete queue;
}

bool isEmpty(Queue *queue)
{
    return !queue->top->next;
}


