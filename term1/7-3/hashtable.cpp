#include "hashtable.h"
#include "list.h"
#include "mystring.h"
#include <iostream>
using namespace std;

struct HashTable
{
    List** arrayOfList;
    int size;
    int amountOfElements;
};

HashTable* createHashTable(int size)
{
    HashTable* newHashTable = new HashTable;
    List** arrayOfList = new List*[size];
    for (int q = 0; q < size; q++)
        arrayOfList[q] = createList();

    newHashTable->arrayOfList = arrayOfList;
    newHashTable->size = size;
    newHashTable->amountOfElements = 0;
    return newHashTable;
}

int hashFunction(MyString* string, int mod)
{
    int sum = 0;
    for (int q = 0; q < length(string); q++)
        sum = sum + getISymbol(string, q);
    return sum % mod;
}

void addElement(HashTable* hashTable, MyString* string)
{
    addElementToList(hashTable->arrayOfList[hashFunction(string, hashTable->size)], string);
    hashTable->amountOfElements++;
}

void deleteHashTable(HashTable* hashTable)
{
    for (int q = 0; q < hashTable->size; q++)
        deleteList(hashTable->arrayOfList[q]);
    delete []hashTable->arrayOfList;
    delete hashTable;
}

void printHashTable(HashTable* hashTable)
{
    for (int q = 0; q < hashTable->size; q++)
        printListInASpecialWayForHashTable(hashTable->arrayOfList[q]);
}

double getLoadFactor(HashTable* hashTable)
{
    return static_cast<double>(hashTable->amountOfElements) / hashTable->size;
}

double getAverageSizeOfList(HashTable* hashTable)
{
    int sum = 0;
    for (int q = 0; q < hashTable->size; q++)
        sum += howManyElements(hashTable->arrayOfList[q]);
    return static_cast<double>(sum) / (hashTable->size - getAmountOfEmptySlots(hashTable));
}

int getMaxLengthOfList(HashTable* hashTable)
{
    int max = 0;
    for (int q = 0; q < hashTable->size; q++)
        if (howManyElements(hashTable->arrayOfList[q]) > max)
            max = howManyElements(hashTable->arrayOfList[q]);
    return max;
}

void printElementsOfMaxLengthLists(HashTable* hashTable)
{
    int maxLength = getMaxLengthOfList(hashTable);
    if (maxLength == 0)
        return;
    for (int q = 0; q < hashTable->size; q++)
        if (howManyElements(hashTable->arrayOfList[q]) == maxLength)
        {
            cout << "List: ";
            printListInOneLine(hashTable->arrayOfList[q]);
        }
}

int getAmountOfElements(HashTable* hashTable)
{
    return hashTable->amountOfElements;
}

int getAmountOfEmptySlots(HashTable* hashTable)
{
    int amount = 0;
    for (int q = 0; q < hashTable->size; q++)
        if (howManyElements(hashTable->arrayOfList[q]) == 0)
            amount++;
    return amount;
}
