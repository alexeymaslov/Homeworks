#include <iostream>

using namespace std;

int** getTable(int &size)
{
    cout << "Input amount of students: ";
    cin >> size;
    int** table = new int*[size];
    for (int q = 0; q < size; q++)
        table[q] = new int [size];

    for (int q = 0; q < size; q++)
        for (int w = 0; w < size; w++)
            table[q][w] = 0;

    return table;
}

void fillTable(int** table, int size)
{
    int value = 0;
    cout << "Input number of student whose solution was written by current student\n";
    cout << "If student has not written a solution then put 0\n";
    for (int q = 0; q < size; q++)
    {
        cout << "Student number " << q + 1 << ": ";     //Предполагаю, что первые три студента честно писали свой вариант
        cin >> value;
        if (value != 0)
            table[q][value - 1] = 1;
    }
}

int findOwner(int** table, int size, int currentStudent)
{
    if (currentStudent < 3)
        return currentStudent;
    for (int q = 0; q < size; q++)
        if (table[currentStudent][q] == 1)
            return findOwner(table, size, q);
    return -1;
}

void seek(int **table, int size)
{
    int *whoseWork = new int[size];
    for (int q = 0; q < size; q++)
    {
        if (q < 3)
        {
            whoseWork[q] = q;
            continue;
        }
        whoseWork[q] = -1;
    }

    for (int q = size - 1; q > 2; q--)
        whoseWork[q] = findOwner(table, size, q);

    for (int q = 0; q < size; q++)
    {
        if (whoseWork[q] == -1)
            cout << "Student number " << q + 1 << " should be expelled immediately!\n";
        else
            cout << "Student number " << q + 1 << " wrote " << whoseWork[q] + 1 << " variant\n";
    }
    delete []whoseWork;
}

int main()
{
    int size = 0;
    int** table = getTable(size);
    fillTable(table, size);
    seek(table, size);

    for (int q = 0; q < size; q++)
        delete []table[q];
    delete []table;
}

