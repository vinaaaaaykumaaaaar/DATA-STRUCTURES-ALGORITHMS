#include <iostream>
#include <vector>

class AdjacencyMatrixGraph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Constructor
    AdjacencyMatrixGraph(int vertices) : numVertices(vertices)
    {
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    // Add an undirected edge between u and v
    void addEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        else
        {
            std::cout << "Invalid vertices for removing edge!" << std::endl;
        }
    }

    // Remove an undirected edge between u and v
    void removeEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0;
        }
        else
        {
            std::cout << "Invalid vertices for removing edge!" << std::endl;
        }
    }

    // Display the adjacency matrix
    void display()
    {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};