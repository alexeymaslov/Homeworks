#pragma once

struct MyString;

MyString* createString(char* line);

MyString* createString();

MyString* createString(int size);

char index(MyString* string, int i);

void deleteString(MyString* string);

MyString* clone(MyString* string);

void concat(MyString* stringOne, MyString* stringTwo);

bool isEqual(MyString* stringOne, MyString* stringTwo);

int length(MyString* string);

bool isEmpty(MyString* stringOne);

MyString* getSubstring(MyString* string, int start, int end);

char* changeToChar(MyString* string);
