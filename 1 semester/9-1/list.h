#pragma once
#include "mystring.h"

struct Element;

struct List;

List* createList();

void addElementToList(List* list, MyString* string);

void deleteList(List* list);

bool belongsToList(List* list, MyString* string);

void removeElementWithSuchString(List* list, MyString* string);

bool isEmpty(List* list);

MyString* pop(List* list);

void printList(List* list);
