/*
Author : Vinay Kumar

Depth First Search or DFS for a Graph

	In Depth First Search (or DFS) for a graph, we traverse all adjacent 
	vertices one by one. When we traverse an adjacent vertex, we completely
	finish the traversal of all vertices reachable through that adjacent 
	vertex. This is similar to a tree, where we first completely traverse 
	the left subtree and then move to the right subtree. The key difference
	is that, unlike trees, graphs may contain cycles (a node may be visited
	more than once). To avoid processing a node multiple times, we use a
	boolean visited array.
 
 
 */


#include <iostream>
#include <stack>
#include <map>
#include <list>

using namespace std;

class Graph
{
	map<int,list<int>> adj_list;

	public :
	
	  void add_edges(int u , int v)
	  {
		  adj_list[u].push_back(v);
		  adj_list[v].push_back(u);
	  }

	  void print()
	  {
		  for(auto i:adj_list)
		  {
			  cout<<i.first<<" -> ";
			  for(auto j: i.second)
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

	g.add_edges(0,1);
	g.add_edges(0,2);
	g.add_edges(0,3);
	g.add_edges(2,4);
	
	cout<<"---------------------------------------------"<<endl;
	g.print();
	cout<<"---------------------------------------------"<<endl;

	return 0;
}

