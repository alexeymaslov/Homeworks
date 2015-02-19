#include <iostream>
#include <fstream>

using namespace std;

int** getGraph(int &size)
{
    const int intMax = 2147483647;
    const int sizeOfAddress = 100;
    char address[sizeOfAddress] = "c:\\users\\alex\\9-3 test.txt";
    //cout << "Input way to file: ";
    //cin.getline(address, sizeOfAddress);

    ifstream myFile;
    myFile.open(address);

    if (myFile) //Пусть первая строка - размер графа; далее граф задан матрицей смежности
    {
        myFile >> size;
        int** graph = new int*[size];
        for (int q = 0; q < size; q++)
            graph[q] = new int [size];

        for (int q = 0; q < size; q++)
        {
            for (int w = 0; w < size; w++)
            {
                myFile >> graph[q][w];
                if (graph[q][w] == 0)
                    graph[q][w] = intMax;
            }
        }

        myFile.close();
        return graph;
    }
    else
    {
        cout << "Error. Wrong way to file.";
        myFile.close();
        return nullptr;
    }
}

void algorithmOfPrim(int** graph, int size)
{
    cout << "These nodes should be connected to build a minimal spanning tree:" << endl;

    const int intMax = 2147483647;
    bool* seen = new bool[size];
    int* minEdgeValue = new int[size];
    int* minEdgeEnd = new int[size];
    for (int q  = 0; q < size; q++)
    {
        seen[q] = false;
        minEdgeValue[q] = intMax;
        minEdgeEnd[q] = -1;
    }
    minEdgeValue[0] = 0;
    int lengthOfTree = 0;

    for (int q = 0; q < size; q++)
    {
        int indexOfCurrentClosentNode = -1;
        for (int w = 0; w < size; w++)
            if (!seen[w] && (indexOfCurrentClosentNode == -1 || minEdgeValue[w] < minEdgeValue[indexOfCurrentClosentNode]))
                indexOfCurrentClosentNode = w;

        if (minEdgeValue[indexOfCurrentClosentNode] == intMax)
        {
            cout << "Error. Minimal spanning tree can't be built.";
            return;
        }

        seen[indexOfCurrentClosentNode] = true;
        if (minEdgeEnd[indexOfCurrentClosentNode] != -1)
        {
            cout << indexOfCurrentClosentNode + 1 << " - " << minEdgeEnd[indexOfCurrentClosentNode] + 1 << endl;
            lengthOfTree += minEdgeValue[indexOfCurrentClosentNode];
        }

        for (int e = 0; e < size; e++)
            if (graph[indexOfCurrentClosentNode][e]  < minEdgeValue[e])
            {
                minEdgeValue[e] = graph[indexOfCurrentClosentNode][e];
                minEdgeEnd[e] = indexOfCurrentClosentNode;
            }
    }
    cout << "Length of minimal spanning tree: " << lengthOfTree;
    delete []seen;
    delete []minEdgeValue;
    delete []minEdgeEnd;
}

int main()
{
    int size = 0;
    int** graph = getGraph(size);

    if (graph)
    {
        algorithmOfPrim(graph, size);

        for (int q = 0; q < size; q++)
            delete []graph[q];
        delete []graph;
    }
}

