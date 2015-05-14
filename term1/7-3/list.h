#pragma once
#include "mystring.h"

struct Element;

struct List;

List *createList();

void addElementToList(List *list, MyString* string);

void deleteList(List *list);

int howManyOfSuchElement(List* list, MyString* string);

int howManyElements(List* list);

//void copyElementsFromOneListToAnother(List* listOne, List* listTwo);

void printList(List* list);

void printListInASpecialWayForHashTable(List* list);

void printListInOneLine(List* list);
