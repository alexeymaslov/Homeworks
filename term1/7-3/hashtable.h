#pragma once
#include "mystring.h"

struct HashTable;

HashTable* createHashTable(int size);

void addElement(HashTable* hashTable, MyString* string);

void deleteHashTable(HashTable* hashTable);

double getLoadFactor(HashTable* hashTable);

double getAverageSizeOfList(HashTable* hashTable);

int getMaxLengthOfList(HashTable* hashTable);

void printElementsOfMaxLengthLists(HashTable* hashTable);

int getAmountOfElements(HashTable* hashTable);

int getAmountOfEmptySlots(HashTable* hashTable);

void printHashTable(HashTable* hashTable);
