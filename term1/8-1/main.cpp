#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

char* getMyLine(ifstream &file)
{
    char symbol = 'a';
    int length = 0;
    Queue *queue = createQueue();
    file.get(symbol);
    while (symbol != '\n' && !file.eof())
    {
        length++;
        enqueue(symbol, queue);
        file.get(symbol);
    }
    char *line = new char[length + 1];
    for (int q = 0; q < length; q++)
    {
        line[q] = dequeue(queue);
    }
    line[length] = '\0';
    deleteQueue(queue);
    return line;
}

int amountOfDigitsInLine(char* line)
{
    int q = 0;
    int amount = 0;
    while (line[q] != '\0')
    {
        if (isdigit(line[q]))
            amount++;
        q++;
    }
    return amount;
}

void fillLineOfGraph(int** graph, char* line, int lineNo)
{
    int q = 0;
    int w = 0;
    while (line[q] != '\0')
    {
        if (isdigit(line[q]))
        {
            graph[lineNo][w] = line[q] - '0';
            w++;
        }
        q++;
    }
}

void breadthFirstSearch(int** table, int sizeOfGraph, bool* visited, int start, char &letter)
{
    Queue *queue = createQueue();
    enqueue(start, queue);
    while (!isEmpty(queue))
    {
        int current = dequeue(queue);
        visited[current] = true;
        cout << letter << "(" << current + 1 << ")" << "  ";
        letter++;
        for (int q = 0; q < sizeOfGraph; q++)
            if (table[current][q] == 1 && !visited[q])
            {
                enqueue(q, queue);
                visited[q] = true;
            }
    }
    deleteQueue(queue);
}

int main()
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\8-1 test.txt";
    //cout << "Input way to file: ";
    //cin.getline(address, sizeOfAddress);
    int startNode = 0;
    cout << "Input start node: ";
    cin >> startNode;
    startNode--;

    ifstream myFile;
    myFile.open(address);

    if (myFile)
    {
        char* line = getMyLine(myFile);
        int size = amountOfDigitsInLine(line);
        int** graph = new int*[size];
        for (int q = 0; q < size; q++)
            graph[q] = new int [size];

        fillLineOfGraph(graph, line, 0);
        delete []line;

        for (int q = 1; q < size; q++)
        {
            line = getMyLine(myFile);
            fillLineOfGraph(graph, line, q);
            delete []line;
        }

        bool *isVisited = new bool[size];
        for (int q = 0; q < size; q++)
            isVisited[q] = false;

        char currentLetter = 'A';
        breadthFirstSearch(graph, size, isVisited, startNode, currentLetter);

        for (int q = 0; q < size; q++) //Вывод непосещенных вершин графа
            if (!isVisited[q])
            {
                cout << endl;
                breadthFirstSearch(graph, size, isVisited, q, currentLetter);
            }

        delete []isVisited;

        for (int q = 0; q < size; q++)
            delete []graph[q];
        delete []graph;
    }
    else
        cout << "Error. Wrong way to file.";
    myFile.close();
}
