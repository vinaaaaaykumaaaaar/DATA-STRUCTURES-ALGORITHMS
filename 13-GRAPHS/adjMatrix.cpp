#include <iostream>
#include <vector>

class AdjacencyMatrixGraph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // constructor
    AdjacencyMatrixGraph(int vertices) : numVertices(vertices)
    {
        // Initialize the matrix with all zeros
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    // Add an undirected edge between u and v
    void addEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // For undirected graph
        }
        else
        {
            std::cout << "Invalid vertices for adding edge!" << std::endl;
        }
    }

    // Remove an undirected edge between u and v
    void removeEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0; // For undirected graph
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

int main()
{
    AdjacencyMatrixGraph g(5); // Graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.display(); //
    return 0;
}