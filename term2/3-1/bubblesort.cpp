#include <iostream>
#include "bubblesort.h"

BubbleSort::BubbleSort()
{}

BubbleSort::~BubbleSort()
{}

void BubbleSort::sort(int* numbers, int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - 1; j++)
            if(numbers[j] > numbers[j + 1])
                std::swap(numbers[j], numbers[j + 1]);
}
