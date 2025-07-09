#include <iostream>
#include <vector>
#include <stack> // Include stack for iterative DFS
using namespace std;

/*
Depth-First Search (DFS) for Graphs - Adjacency List Representation
====================================================================

Theory:
-------
    Depth-First Search (DFS) is a fundamental graph traversal algorithm used
    to explore nodes and edges of a graph. Unlike BFS, which explores neighbors
    level by level, DFS explores as far as possible along each branch before
    backtracking. DFS can be implemented using recursion or an explicit stack.

How DFS Works:
--------------
1. Start at a selected node (the 'source' or 'start' node).
2. Mark the current node as visited.
3. For each neighbor of the current node (from the adjacency list):
   - If the neighbor has not been visited, recursively perform DFS on that neighbor.
4. The process continues until all nodes reachable from the start node are visited.

Adjacency List:
---------------
- An adjacency list is an array (or vector) of lists. Each index represents a node, and
  the list at that index contains all the nodes it is connected to.
- This representation is memory efficient for sparse graphs.

DFS Algorithm Steps (Recursive):
--------------------------------
1. Create a visited array to keep track of visited nodes.
2. Call the DFS function for the starting node.
3. In the DFS function:
   a. Mark the current node as visited.
   b. For each neighbor, if not visited, call DFS for that neighbor.

Applications of DFS:
--------------------
- Detecting cycles in a graph
- Topological sorting
- Finding connected components
- Solving puzzles and games (like mazes)

Below is a simple, beginner-friendly C++ implementation of DFS for a graph using an adjacency list.
*/

// Recursive function to perform DFS on a graph represented by an adjacency list
// (This is the classic recursive solution, kept for reference)
void dfsUtil(const vector<vector<int>> &adjList, int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    // Visit all neighbors of the current node
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfsUtil(adjList, neighbor, visited);
        }
    }
}

// Iterative DFS using an explicit stack (preferred for this implementation)
// void dfs(const vector<vector<int>> &adjList, int start)
// {
//     int n = adjList.size();
//     vector<bool> visited(n, false);
//     stack<int> s;
//     s.push(start);
//     cout << "DFS Traversal starting from node " << start << ": ";
//     while (!s.empty())
//     {
//         int node = s.top();
//         s.pop();
//         if (!visited[node])
//         {
//             visited[node] = true;
//             cout << node << " ";
//             // Push neighbors to stack (in reverse order for same order as recursion)
//             for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it)
//             {
//                 if (!visited[*it])
//                 {
//                     s.push(*it);
//                 }
//             }
//         }
//     }
//     cout << endl;
// }

void dfs(const vector<vector<int>> &adjList, int start)
{
    int n = adjList.size();
    vector<bool> visited(n, false);

    stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        std::cout << node << " ";

        for (int neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                s.push(neighbour);
            }
        }
    }

    std::cout << std::endl;
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

    int startNode = 0; // Starting node for DFS
    dfs(adjList, startNode);

    // Uncomment below to use the recursive version instead:
    // vector<bool> visited(adjList.size(), false);
    // cout << "DFS Traversal (recursive) starting from node " << startNode << ": ";
    // dfsUtil(adjList, startNode, visited);
    // cout << endl;

    return 0;
}