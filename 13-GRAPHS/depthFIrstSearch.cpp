#include "adjList.hpp"
#include "adjMatrix.hpp"

int main()
{
    AdjacencyListGraph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.display();

    std::cout << "--------------------------" << std::endl;
    AdjacencyMatrixGraph v(5);
    v.addEdge(0, 1);
    v.addEdge(0, 4);
    v.addEdge(1, 2);
    v.addEdge(1, 3);
    v.addEdge(1, 4);
    v.addEdge(2, 3);
    v.addEdge(3, 4);
    v.display();
    return 0;
}
