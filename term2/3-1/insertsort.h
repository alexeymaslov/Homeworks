#pragma once
#include "sorter.h"

class InsertSort : public Sorter
{
public:
    InsertSort();
    ~InsertSort();
    void sort(int* numbers, int size);
};
