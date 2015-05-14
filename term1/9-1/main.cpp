#include <iostream>
#include <fstream>
#include "queue.h"
#include "mystring.h"
#include "list.h"

using namespace std;

char* getMyLine(ifstream &file)
{
    char symbol = 'a';
    int length = 0;
    Queue* queue = createQueue();
    file.get(symbol);
    while (symbol != '\n' && !file.eof())
    {
        length++;
        enqueue(symbol, queue);
        file.get(symbol);
    }
    char* line = new char[length + 1];
    for (int q = 0; q < length; q++)
    {
        line[q] = dequeue(queue);
    }
    line[length] = '\0';
    deleteQueue(queue);
    return line;
}

List* getListFromFirstFile()
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\9-1 1test.txt";
    //cout << "Input way to the first file: ";
    //cin.getline(address, sizeOfAddress);

    List* list = createList();

    ifstream myFile;
    myFile.open(address);
    if (myFile)
        while (!myFile.eof())
        {
            char* line = getMyLine(myFile);
            //Предполагаю, что если строка несколько раз содержится или в первом, или во втором файле, то в третий
            //нужно записывать только один образец данной строки, поэтому добавляю в список строк первого файла
            //каждую повторяющуюся строку лишь один раз.
            if (line[0] != '\0')
                addElementToList(list, createString(line));
            delete []line;
        }
    else
        cout << "Error. Wrong way to first file.";
    myFile.close();
    return list;
}

List* getListOfThirdFile(List* firstFileList)
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\9-1 2test.txt";
    //cout << "Input way to the second file: ";
    //cin.getline(address, sizeOfAddress);

    List* list = createList();

    ifstream myFile;
    myFile.open(address);
    if (myFile)
        while (!myFile.eof())
        {
            char* line = getMyLine(myFile);
            MyString* myLine = createString(line);
            if (belongsToList(firstFileList, myLine))
            {
                addElementToList(list, myLine);
                removeElementWithSuchString(firstFileList, myLine);
            }
            else
                deleteString(myLine);
            delete []line;
        }
    else
        cout << "Error. Wrong way to the second file.";
    myFile.close();
    return list;
}

void printListInFile(List* listOfThirdFile)
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\9-1 3test.txt";
    //cout << "Input way to the third file: ";
    //cin.getline(address, sizeOfAddress);

    ofstream myFile;
    myFile.open(address);
    if (myFile)
    {
        while (!isEmpty(listOfThirdFile))
        {
            MyString* line = pop(listOfThirdFile);
            myFile << changeToChar(line);
            myFile << endl;
            deleteString(line);
        }
    }
    else
        cout << "Error. Wrong way to the third file.";
    myFile.close();
}

int main()
{
    List* listFromFirstFile = getListFromFirstFile();
    if (isEmpty(listFromFirstFile))
    {
        cout << "Error. First file is empty.";
        deleteList(listFromFirstFile);
        return 0;
    }
    List* listOfThirdFile = getListOfThirdFile(listFromFirstFile);
    deleteList(listFromFirstFile);
    printListInFile(listOfThirdFile);
    deleteList(listOfThirdFile);
}

