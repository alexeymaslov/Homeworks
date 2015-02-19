#include <iostream>
#include <fstream>

using namespace std;

int findMin(int* distance, bool* seen, int size, const int typeMax)
{
    int min = typeMax;
    int minNo = 0;
    for (int q = 0; q < size; q++)
        if (!seen[q] && distance[q] <= min)
        {
            min = distance[q];
            minNo = q;
        }
    return minNo;
}

void printPath(int* path, int q)
{
    cout << q + 1;
    while (q != 0)
    {
        q = path[q];
        cout << " <- " << q + 1;
    }
}

int* sortDistances(int* distance, int size)
{
    int* number = new int[size];
    bool* seen = new bool[size];
    for (int q = 0; q < size; q++)
    {
        int index;
        int min = 2147483647;
        for (int w = 1; w < size + 1; w++)
        {
            if (distance[w] <= min && !seen[w])
            {
                min = distance[w];
                index = w;
            }
        }
        number[q] = index;
        seen[index] = true;
    }
    delete []seen;
    return number;
}

void algorithmOfDijkstra(int** graph, int size)
{
    const int intMax = 2147483647;
    int* distance = new int[size];
    bool* seen = new bool[size];
    int* path = new int[size];
    for (int q = 0; q < size; q++)
    {
        distance[q] = intMax;
        seen[q] = false;
        path[q] = 0;
    }
    distance[0] = 0;

    for (int i = 0; i < size; i++)
    {
        int w = findMin(distance, seen, size, intMax);
        seen[w] = true;
        for (int v = 0; v < size; v++)
            if (!seen[v] && graph[w][v] && distance[w] != intMax && distance[v] > distance[w] + graph[w][v])
            {
                distance[v] = distance[w] + graph[w][v];
                path[v] = w;
            }
    }
    delete []seen;

    int* distancesAscending = sortDistances(distance, size - 1);

    for (int q = 0; q < size - 1; q++)
    {
        cout << "Capture city: " << distancesAscending[q] + 1 << ", distance from first city: " << distance[distancesAscending[q]] << endl;
        cout << "Path to this city: ";
        printPath(path, distancesAscending[q]);
        cout << endl;
    }
    delete []path;
    delete []distance;
    delete []distancesAscending;
}

int main()
{
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\8-2 test.txt";
    //cout << "Input way to file: ";
    //cin.getline(address, sizeOfAddress);

    ifstream myFile;
    myFile.open(address);

    if (myFile)
    {
        int sizeOfGraph = 0;
        myFile >> sizeOfGraph;

        int** graph = new int*[sizeOfGraph];
        for (int q = 0; q < sizeOfGraph; q++)
            graph[q] = new int [sizeOfGraph];
        for (int q = 0; q < sizeOfGraph; q++)
            for (int w = 0; w < sizeOfGraph; w++)
                graph[q][w] = 0;

        int amountOfRoads = 0;
        myFile >> amountOfRoads;
        for (int q = 0; q < amountOfRoads; q++)
        {
            int i = 0;
            int j = 0;
            int length = 0;
            myFile >> i;
            myFile >> j;
            myFile >> length;
            graph[i - 1][j - 1] = length;
            graph[j - 1][i - 1] = length;
        }

        algorithmOfDijkstra(graph, sizeOfGraph);

        for (int q = 0; q < sizeOfGraph; q++)
            delete []graph[q];
        delete []graph;

        cout << endl << "Poland is conquered, my Fuehrer!";
    }
    else
        cout << "Error. Wrong way to file.";
    myFile.close();
}
