/* 
	Author : Vinay Kumar L

	Implementation of Graph in C++

	In C++, graphs are non-linear data structures that are used to represent the relationships
	between various objects. A graph is defined as a collection of vertices and edges. In this
	article,we will learn how to implement the graph data structure in C++.

	There are two primary ways to implement or represent graph data structures in C++:

	   - Using Adjacency Matrix
	   - Using Adjacency List

	Adjacency Matrix Representation of Graph in C++

	   An adjacency matrix is a square matrix (2D vector in C++) used to represent a finite graph.
	   It provides a straightforward way to describe the relationships between nodes (vertices) in
	   a graph.


	Rules to Create Adjacency Matrix of a Graph
	   
	   - Create an n x n 2d vector named matrix, where n is the number of nodes, with all entries
	   initialized to 0.
	   - For an undirected graph, set both matrix[i][j] and matrix[j][i] to 1 if there is an edge 
	   between vertices i and j.
	   - For a directed graph, set matrix[i][j] to 1 if there is an edge from vertex i to vertex j.
	   - For a weighted graph, set matrix[i][j] to the weight of the edge between vertices i and j.
	   - If there is a self-loop on vertex i, set matrix[i][i] to 1 (or the weight if weighted).
 */

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
	public :
	// Adjacency matrix to store graph edges
	vector<vector<int>> adj_matrix;

	public :
		
		// Constructor to initialize the graph with 'n' nodes
		Graph(int n)
		{
			adj_matrix = vector<vector<int>> (n , vector<int>(n,0));
		}

		// Function to add an edge between nodes and edges 'u' and 'v'
		// of the graph
		void add_edge(int u, int v)
		{
			// set edge from u to v
			adj_matrix[u][v] = 1;
			// set edge from v to u
			adj_matrix[v][u] = 1;
		}

		// Function to print the adjacency matrix representation
		void print()
		{
			cout<< "Adjacency Matrix for the Graph: "<<endl;
			int n = adj_matrix.size();
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<< adj_matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main()
{
	// Number of nodes
	int64_t n ;

	cout<<"Enter the number of nodes "<<endl;
	cin>>n;

	Graph g(n);

	int64_t m;
	cout<<"Enter the number of edges "<<endl;
	cin>>m;

	for(int i=0; i<n; i++)
	{
		int64_t u , v;

		g.add_edge(u,v);
	}

	g.print();

	return 0;

}



























	





















