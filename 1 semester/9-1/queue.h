#pragma once

struct Queue;

struct Element;

Queue* createQueue();

void enqueue(int value, Queue* queue);

int dequeue(Queue* queue);

void deleteQueue(Queue* queue);

bool isEmpty(Queue* queue);
