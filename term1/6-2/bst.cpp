#include <iostream>
#include "bst.h"

using namespace std;

struct Node
{
    char symbol;
    double value;
    Node* leftChild;
    Node* rightChild;
};

struct Tree
{
    Node* root;
};

Node* createNode(char symbol, double value)
{
    Node* newNode = new Node;
    newNode->symbol = symbol;
    newNode->value = value;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

Tree* createTree()
{
    Tree* newTree = new Tree;
    newTree->root = nullptr;
    return newTree;
}

void printAscending(Node* node)
{
    if (node == nullptr)
        return;
    if (node->leftChild)
        cout << "(";
    printAscending(node->leftChild);
    if (node->symbol != 'a')
        cout << node->symbol;
    else
        cout << node->value;
    printAscending(node->rightChild);
    if (node->rightChild)
        cout << ")";
}

void printAscending(Tree *tree)
{
    printAscending(tree->root);
}

void deleteTree(Node* &node)
{
    if (node == nullptr)
        return;
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
}

void deleteTree(Tree* tree)
{
    deleteTree(tree->root);
    delete tree;
}

void buildTreeFromLine(Node* &node, char* line, int &q)
{
    if (line[q] == '(')
        q++;
    node = createNode(line[q], 0);
    q++;
    if (isspace(line[q]))
        q++;
    if (isdigit(line[q]))
    {
        int value = line[q] - '0';
        q++;
        while (isdigit(line[q]))
        {
            value = value*10 + line[q] - '0';
            q++;
        }
        node->leftChild = createNode('a', value);
    }
    else if (line[q] == '(')
    {
        buildTreeFromLine(node->leftChild, line, q);
        q++;
    }

    if (isspace(line[q]))
        q++;

    if (isdigit(line[q]))
    {
        int value = line[q] - '0';
        q++;
        while (isdigit(line[q]))
        {
            value = value*10 + line[q] - '0';
            q++;
        }
        node->rightChild = createNode('a', value);
    }
    else if (line[q] == '(')
        buildTreeFromLine(node->rightChild, line, q);
    if (line[q] == ')')
        q++;
}

void buildTreeFromLine(Tree* tree, char* line)
{
    int q = 0;
    buildTreeFromLine(tree->root, line, q);
}

double calculate(Node* &node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return node->value;
    if (node->symbol == '+')
        return calculate(node->leftChild) + calculate(node->rightChild);
    else if (node->symbol == '-')
        return calculate(node->leftChild) - calculate(node->rightChild);
    else if (node->symbol == '*')
        return calculate(node->leftChild) * calculate(node->rightChild);
    else if (node->symbol == '/')
        return calculate(node->leftChild) / calculate(node->rightChild);
}

double calculate(Tree* tree)
{
    return calculate(tree->root);
}

