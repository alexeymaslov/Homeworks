#pragma once

struct Node;

struct Tree;

Tree* createTree();

void addElement(Tree* tree, int value);

void removeElement(Tree* tree, int value);

bool exists(Tree* tree, int value);

void printAscending(Tree* tree);

void printDescending(Tree* tree);

void printPreorder(Tree* tree);

void deleteTree(Tree* tree);
