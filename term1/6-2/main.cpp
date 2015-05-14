#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

void printResult(char* address, const int sizeOfLine)
{
    ifstream myFile;
    myFile.open(address);
    if (myFile)
    {
        char line[sizeOfLine];
        Tree* tree = createTree();
        myFile.getline(line, sizeOfLine);
        cout << "Input: " << line << "\n";
        buildTreeFromLine(tree, line);
        cout << "Edited input: ";
        printAscending(tree);
        cout << "\nResult: " << calculate(tree)<< "\n";
        deleteTree(tree);
    }
    else
        cout << "File does not exist.";
    myFile.close();
}

int main()
{
    const int sizeOfLine = 10000;

    //char line[sizeOfLine];
    //cout << "Input way to file: ";
    //cin.getline(line, sizeOfLine);

    char address1[sizeOfLine] = "c:\\users\\alex\\6-2 test1.txt";
    printResult(address1, sizeOfLine);
    char address2[sizeOfLine] = "c:\\users\\alex\\6-2 test2.txt";
    printResult(address2, sizeOfLine);
}
