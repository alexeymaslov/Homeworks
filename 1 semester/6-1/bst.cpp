#include <iostream>
#include "bst.h"

using namespace std;

enum AmountOfChildren
{
    leaf, onlyLeftChild, onlyRightChild, TwoChildren
};

struct Node
{
    int value;
    Node* leftChild;
    Node* rightChild;
};

struct Tree
{
    Node* root;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
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

void addElement(Node* &node, int value)
{
    if (node == nullptr)
    {
        node = createNode(value);
        return;
    }

    if (node->value < value)
        addElement(node->rightChild, value);
    else if (node->value > value)
        addElement(node->leftChild, value);
}

void addElement(Tree* tree, int value)
{
    addElement(tree->root, value);
}

AmountOfChildren calculateSiblings(Node* node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return leaf;
    if (node->rightChild == nullptr)
        return onlyLeftChild;
    if (node->leftChild == nullptr)
        return onlyRightChild;
    else
        return TwoChildren;

}

void removeLeaf(Node* &node)
{
    delete node;
    node = nullptr;
}

void removeElementWithOnlyLeftChild(Node* &node)
{
    Node* copyOfNode = node;
    node = node->leftChild;
    delete copyOfNode;
}

void removeElementWithOnlyRightChild(Node* &node)
{
    Node* copyOfNode = node;
    node = node->rightChild;
    delete copyOfNode;
}

Node* &getLeftmost(Node* &node)
{
    Node* current = node;
    while (current->leftChild->leftChild != nullptr)
        current = current->leftChild;
    return current->leftChild;
}

void removeElementWithTwoChildren(Node* &node)
{
    if (node->rightChild->leftChild == nullptr)
    {
        Node* copyOfNode = node;
        node = node->rightChild;
        node->leftChild = copyOfNode->leftChild;
        delete copyOfNode;
    }
    else
    {
        Node* &leftmost = getLeftmost(node->rightChild);
        node->value = leftmost->value;
        Node* copyOfLeftmost = leftmost;
        leftmost = leftmost->rightChild;
        delete copyOfLeftmost;
    }
}

void removeElement(Node* &node, int value)
{
    if (node == nullptr)
        return;
    if (value > node->value)
        removeElement(node->rightChild, value);
    else if (value < node->value)
        removeElement(node->leftChild, value);
    else if (value == node->value)
    {
        switch (calculateSiblings(node))
        {
        case leaf:
            removeLeaf(node);
            break;
        case onlyLeftChild:
            removeElementWithOnlyLeftChild(node);
            break;
        case onlyRightChild:
            removeElementWithOnlyRightChild(node);
            break;
        case TwoChildren:
            removeElementWithTwoChildren(node);
            break;
        }
    }
}

void removeElement(Tree *tree, int value)
{
    removeElement(tree->root, value);
}

Node* &findElement(Node* &node, int value)
{
    if (node == nullptr)
        return node;
    if (node->value > value)
        findElement(node->leftChild, value);
    else if (node->value < value)
        findElement(node->rightChild, value);
    else if (node->value == value)
        return node;
}

bool exists(Tree *tree, int value)
{
    return (findElement(tree->root, value) != nullptr);
}

void printAscending(Node* node)
{
    if (node == nullptr)
        return;
    printAscending(node->leftChild);
    cout << node->value << " ";
    printAscending(node->rightChild);
}

void printAscending(Tree *tree)
{
    printAscending(tree->root);
    cout << endl;
}

void printDescending(Node* node)
{
    if (node == nullptr)
        return;
    printDescending(node->rightChild);
    cout << node->value << " ";
    printDescending(node->leftChild);
}

void printDescending(Tree *tree)
{
    printDescending(tree->root);
    cout << endl;
}

void printPreorder(Node* node)
{
    if (node == nullptr)
    {
        cout << "null";
        return;
    }
    cout << node->value;
    cout << " ";
    cout << "(";
    printPreorder(node->leftChild);
    cout << " ";
    printPreorder(node->rightChild);
    cout << ")";
}

void printPreorder(Tree *tree)
{
    printPreorder(tree->root);
    cout << endl;
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
