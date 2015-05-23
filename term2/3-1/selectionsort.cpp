#include <iostream>
#include "selectionsort.h"

SelectionSort::SelectionSort()
{}

SelectionSort::~SelectionSort()
{}

void SelectionSort::sort(int *numbers, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (numbers[j] < numbers[minIndex])
                minIndex = j;
        if (minIndex != i)
            std::swap(numbers[i], numbers[minIndex]);
    }
}
