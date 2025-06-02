#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    vector<vector<int64_t>> adj_matrix;

    Graph(int64_t n)
    {
        adj_matrix = vector<vector<int64_t>>(n, vector<int64_t>(n, 0));
    }

    void add_edges(int64_t u, int64_t v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    void print()
    {
        cout << "Adjacency Matrix for the Graph" << endl;
        int64_t n = adj_matrix.size();

        for (int64_t i = 0; i < n; i++)
        {
            for (int64_t j = 0; j < n; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int64_t n;
    cout << "Enter the number of nodes " << endl;
    cin >> n;

    Graph g(n);

    int64_t m;
    cout << "Enter the number of edges " << endl;
    cin >> m;

    for (int64_t i = 0; i < n; i++)
    {
        int64_t u, v;
        cin >> u >> v;
        g.add_edges(u, v);
    }

    g.print();

    return 0;
}