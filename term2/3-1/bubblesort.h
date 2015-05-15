#pragma once
#include "sorter.h"

class BubbleSort : public Sorter
{
public:
    BubbleSort();
    ~BubbleSort();
    void sort(int* numbers, int size);
};
