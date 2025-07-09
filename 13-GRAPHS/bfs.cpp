/*
Breadth-First Search (BFS) for Graphs - Adjacency List Representation
=======================================================================

Theory:
-------
    Breadth-First Search (BFS) is a fundamental graph traversal algorithm used to
    explore nodes and edges of a graph systematically. It is especially useful for
    finding the shortest path in unweighted graphs and for traversing or searching
    tree or graph data structures.

How BFS Works:
--------------
    1. BFS starts at a selected node (called the 'source' or 'start' node).
    2. It explores all the immediate neighbors of the start node first, before moving to the next level neighbors.
    3. BFS uses a queue data structure to keep track of nodes to visit next.
    4. Each node is marked as 'visited' once it is enqueued, to avoid processing it multiple times.

Adjacency List:
---------------
    - An adjacency list is an array (or vector) of lists. Each index represents a node, and the list at that index contains all the nodes it is connected to.
    - This representation is memory efficient for sparse graphs.

BFS Algorithm Steps:
--------------------
1. Create a queue and enqueue the starting node. Mark it as visited.
2. While the queue is not empty:
   a. Dequeue a node from the queue.
   b. For each neighbor of the dequeued node (check the adjacency list):
      - If the neighbor has not been visited, mark it as visited and enqueue it.

Applications of BFS:
--------------------
- Finding the shortest path in unweighted graphs
- Checking graph connectivity
- Web crawlers
- Social networking sites (finding people within a certain distance)

Below is a simple, beginner-friendly C++ implementation of BFS for a graph using an adjacency list.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS on a graph represented by an adjacency list
void bfs(const vector<vector<int>> &adjList, int start)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        std::cout << node << " ";

        for (int neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    std::cout << endl;
}

int main()
{
    // Example: Graph with 5 nodes (0 to 4)
    // Adjacency list representation
    vector<vector<int>> adjList = {
        {1, 2},    // Node 0 is connected to 1 and 2
        {0, 3},    // Node 1 is connected to 0 and 3
        {0, 3, 4}, // Node 2 is connected to 0, 3, and 4
        {1, 2, 4}, // Node 3 is connected to 1, 2, and 4
        {2, 3}     // Node 4 is connected to 2 and 3
    };

    int startNode = 0; // Starting node for BFS
    bfs(adjList, startNode);

    return 0;
}
