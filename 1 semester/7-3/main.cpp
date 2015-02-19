#include <iostream>
#include <fstream>
#include "hashtable.h"
#include "mystring.h"

using namespace std;

int main()
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\7-3 test.txt";
    const int sizeOfHashTable = 10000;
    //cout << "Input way to file: ";
    //cin.getline(address, sizeOfAddress);
    ifstream myFile;
    myFile.open(address);

    if (myFile)
    {
        HashTable* hashTable = createHashTable(sizeOfHashTable);
        char word[30];
        while (!myFile.eof())
        {
            myFile >> word;
            MyString* string = createString(word);
            addElement(hashTable, string);
        }
        cout << "Elements: " << endl;
        printHashTable(hashTable);
        cout << endl;
        cout << "Load factor = " << getLoadFactor(hashTable) << endl;
        cout << "Average length = " << getAverageSizeOfList(hashTable) << endl;
        cout << "Max length = " << getMaxLengthOfList(hashTable) << endl;
        cout << "Elements of max lenght lists: " << endl;
        printElementsOfMaxLengthLists(hashTable);
        cout << "Amount of elements = " << getAmountOfElements(hashTable) << endl;
        cout << "Amount of empty slots = " << getAmountOfEmptySlots(hashTable) << endl;
        deleteHashTable(hashTable);
    }
    else
        cout << "File does not exist.";

    myFile.close();
}

