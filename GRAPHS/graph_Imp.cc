#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph
{
    map<int64_t, list<int64_t>> adj_list;

public:
    void add_edges(int64_t u, int64_t v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void print()
    {
        for (auto i : adj_list)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.add_edges(1, 0);
    g.add_edges(2, 0);
    g.add_edges(1, 2);

    g.print();

    return 0;
}