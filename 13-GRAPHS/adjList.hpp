#include <iostream>
#include <vector>
#include <list>

class AdjacencyListGraph
{
private:
    int numVertices;
    std::vector<std::list<int>> adjList; // Using vector of lists

public:
    // Constructor
    AdjacencyListGraph(int vertices) : numVertices(vertices)
    {
        // Resize the vector to hold lists for each vertex
        adjList.resize(numVertices);
    }

    // Add an undirected edge between u and v
    void addEdge(int u, int v)
    {
        if (u > 0 && u <= numVertices && v > 0 && v <= numVertices)
        {
            adjList[u].push_back(v); // Add v to u's list
            adjList[v].push_back(u); // Add u to v's list (for undirected graph)
        }
        else
        {
            std::cout << "Invalid vertices for adding edge!" << std::endl;
        }
    }

    // Display the adjacency list
    void display()
    {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; ++i)
        {
            std::cout << i << ": ";
            for (int neighbor : adjList[i])
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};
