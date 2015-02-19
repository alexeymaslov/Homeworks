#pragma once

struct Element;

struct PhonebookList;

PhonebookList *createList();

void addElement(PhonebookList *list, char name[], unsigned int number);

void printElementsWithName(PhonebookList *list, char name[]);

void printElementWithNumber(PhonebookList *list, unsigned int number);

void deleteList(PhonebookList *list);

void putListIntoFile(PhonebookList *list);

void getListFromFile(PhonebookList *list);
