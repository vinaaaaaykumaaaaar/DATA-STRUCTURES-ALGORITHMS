/*

Author : Vinay Kumar L


Adjacency List Representation of Graph in C++

	An Adjacency List is a common way to represent a graph in computer science. Specifically,
	it’s a way of representing a graph as a map from vertices to lists of edges. The adjacency 
	list representation of a graph is linked to the degree of the vertices, and hence is quite
	space efficient. It only uses space proportional to the number of edges, which can be much
	less than the square of the number of vertices (which is the space complexity of the
	adjacency matrix representation).

Rules to Create Adjacency List of a Graph
	
	- Create a list of n elements, where n is the number of vertices.
	- For an undirected graph, add vertex j to the list of vertex i and add vertex i to the list
	  of vertex j if there is an edge between i and j.
	- For a directed graph, add vertex j to the list of vertex i if there is an edge from vertex
	  i to vertex j.
	- For a weighted graph, add a tuple (j, weight) to the list of vertex i to represent an edge
	  from i to j with the given weight.
	- If there is a self-loop on vertex i, add i to the list of vertex i (or (i, weight) if 
	  weighted).

*/


#include <iostream>
#include <list>
#include <map>

using namespace std;

class Graph
{
	map<int64_t , list<int64_t>> adj_list;

	public :
		
		// Function to add an edge between nodes u and v
		void add_edge(int64_t u, int64_t v)
		{
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}


		// function to print the adjacency list 
		void print()
		{
			cout<<"Adjacency list for the Graph :"<<endl;

			for(auto i : adj_list)
			{
				cout<<i.first<<" -> ";

				for(auto j : i.second)
				{
					cout<<j<<" ";
				}
				cout<<endl;
			}
		}
};



int main()
{
	Graph g;

	g.add_edge(1,0);
	g.add_edge(2,0);
	g.add_edge(1,2);

	g.print();
	return 0;
}

