#pragma once

struct Node;

struct Tree;

Tree* createTree();

void deleteTree(Tree* tree);

void buildTreeFromLine(Tree* tree, char* line);

void printAscending(Tree* tree);

double calculate(Tree* tree);
