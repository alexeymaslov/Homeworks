#pragma once
#include "sorter.h"

class SelectionSort : public Sorter
{
public:
    SelectionSort();
    ~SelectionSort();
    void sort(int* numbers, int size);
};
