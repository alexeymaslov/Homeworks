#include "insertsort.h"

InsertSort::InsertSort()
{}

InsertSort::~InsertSort()
{}

void InsertSort::sort(int* numbers, int size)
{
    for (int i = 1; i < size; i++)
    {
        int currentElement = numbers[i];
        int previousIndex = i - 1;
        while (previousIndex >= 0 && numbers[previousIndex] > currentElement)
        {
            numbers[previousIndex + 1] = numbers[previousIndex];
            numbers[previousIndex] = currentElement;
            previousIndex--;
        }
    }
}
