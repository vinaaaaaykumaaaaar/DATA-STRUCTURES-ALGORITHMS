/*
 given n and m where n is no of nodes and m is no of edges

 input :
            [1, 2]
            [1, 3]
            [2, 4]
            [3, 4]
            [2, 5]
            [4, 5]

    ====

    1  --------  2 -
    |            |   -
    |            |    - 5
    |            |   -
    3  --------  4 -


*/

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
