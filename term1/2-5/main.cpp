#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shiftDown(int *array, int i, int last)
{
    bool isFinished = false;
    int iMaxChild = 0;
    int iLeftChild = i * 2 + 1;
    int iRightChild = i * 2 + 2;
    while (iLeftChild < last && !isFinished)
    {
        if (iLeftChild == last - 1)
            iMaxChild = iLeftChild;
        else if (array[iLeftChild] > array[iRightChild])
            iMaxChild = iLeftChild;
        else
            iMaxChild = iRightChild;

        if (array[i] < array[iMaxChild])
        {
            swap(array[i], array[iMaxChild]);
            i = iMaxChild;
        }
        else
            isFinished = true;

        iLeftChild = i * 2 + 1;
        iRightChild = i * 2 + 2;
    }
}

void heapSort(int *array, const int size)
{
    for (int q = size / 2 - 1; q >= 0; q--)
        shiftDown(array, q, size);

    for (int q = size - 1; q >= 0; q--)
    {
        swap(array[0], array[q]);
        shiftDown(array, 0, q);
    }
}

void getRandomDigits(int *array, const int size)
{
    srand (time(NULL));
    for (int q = 0; q < size; q++)
        array[q] = rand() % 100;
}

void printArray(int *array, const int size)
{
    cout << "Array:";
    for (int q = 0; q < size; q++)
        cout << " " << array[q];
    cout << endl;
}

int main()
{
    const int sizeOfArray = 16;
    int numbers[sizeOfArray];
    getRandomDigits(numbers, sizeOfArray);
    printArray(numbers, sizeOfArray);
    cout << endl;
    heapSort(numbers, sizeOfArray);
    printArray(numbers, sizeOfArray);
}
