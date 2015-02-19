#include <iostream>
#include "avlt.h"

enum AmountOfChildren
{
    leaf, onlyLeftChild, onlyRightChild, TwoChildren
};

struct Node
{
    int value;
    int height;
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
    newNode->height = 1;
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

int height(Node* node)
{
   return node ? node->height : 0;
}

int balanceFactor(Node *node)
{
   return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(Node *node)
{
   int heightLeft = height(node->leftChild);
   int heightRight = height(node->rightChild);
   node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

void rotateRight(Node* &node)
{
   Node* pivot = node->leftChild;
   node->leftChild = pivot->rightChild;
   pivot->rightChild = node;
   updateHeight(node);
   updateHeight(pivot);
   node = pivot;
}

void rotateLeft(Node* &node)
{
   Node* pivot = node->rightChild;
   node->rightChild = pivot->leftChild;
   pivot->leftChild = node;
   updateHeight(node);
   updateHeight(pivot);
   node = pivot;
}

void balance(Node* &node)
{
    updateHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->rightChild) < 0)
            rotateRight(node->rightChild);
        rotateLeft(node);
    }
    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->leftChild) > 0)
            rotateLeft(node->leftChild);

        rotateRight(node);
    }
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
    balance(node);
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
    node= node->leftChild;
    delete copyOfNode;
}

void removeElementWithOnlyRightChild(Node* &node)
{
    Node* copyOfNode = node;
    node= node->rightChild;
    delete copyOfNode;
}

Node* &getLeftmost(Node* &node)
{
    return node ? node->leftChild : node;
}

void removeElementWithTwoChildren(Node* &node)
{
    if (node->rightChild->leftChild == nullptr)
    {
        Node* copyOfNode = node;
        node = node->rightChild;
        node->leftChild = copyOfNode->leftChild;
        delete copyOfNode;
        balance(node->rightChild);
    }
    else
    {
        Node* &leftmost = getLeftmost(node->rightChild);
        node->value = leftmost->value;
        Node* copyOfLeftmost = leftmost;
        leftmost = leftmost->rightChild;
        delete copyOfLeftmost;
        balance(node->rightChild);
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
    balance(node);
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
    return findElement(tree->root, value);
}

void printAscending(Node* node)
{
    if (node == nullptr)
        return;
    printAscending(node->leftChild);
    std::cout << node->value << " ";
    printAscending(node->rightChild);
}

void printAscending(Tree *tree)
{
    printAscending(tree->root);
    std::cout << "\n";
}

void printDescending(Node* node)
{
    if (node == nullptr)
        return;
    printDescending(node->rightChild);
    std::cout << node->value << " ";
    printDescending(node->leftChild);
}

void printDescending(Tree *tree)
{
    printDescending(tree->root);
    std::cout << "\n";
}

void printPreorder(Node* node)
{
    if (node == nullptr)
    {
        std::cout << "null";
        return;
    }
    std::cout << node->value << " " << "(";
    printPreorder(node->leftChild);
    std::cout << " ";
    printPreorder(node->rightChild);
    std::cout << ")";
}

void printPreorder(Tree *tree)
{
    printPreorder(tree->root);
    std::cout << "\n";
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
