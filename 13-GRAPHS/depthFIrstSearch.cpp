#include <iostream>
#include <vector>
#include <list>

// recursice dfs function
void dfsUtil(int currentNode, const std::vector<std::list<int>> &adjList, std::vector<bool> &visited)
{
    visited[currentNode] = true;
    std::cout << currentNode << " ";
}