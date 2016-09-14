#include <iostream>
#include <list>

using namespace std;

//Definition of Graphs
//Vertices 
//Edges -> stored as integers
void dfs_visit(int vertices,list<int>* adj_list, bool* parent);
void DFS(int start_vertex, int nVertices, list<int>* adj_list);

void main()
{
	
	enum Vertices{
		A,
		B,
		C,
		D,
		E,
		F
	};

	int nVertices = 9;
	list<int> *adj_list = new list<int>[nVertices]; //Creates a adjacency list of nVertices
	
	
	

	//creates directed graph
	adj_list[A].push_back(B);
	adj_list[A].push_back(C);

	adj_list[B].push_back(C);
	adj_list[C].push_back(D);

	adj_list[E].push_back(B);
	adj_list[E].push_back(D);
	adj_list[E].push_back(F);

	adj_list[6].push_back(7);
	

	//end of graph 
	
	
	DFS(1, nVertices, adj_list);
	system("PAUSE");
}

//Depth First Search Implementation
//Input: The graph <V, adj_list> , array of visited vertices
void dfs_visit(int vertices,list<int>* adj_list, int* parent)
{
	list<int>::iterator it; 

	//calls dfs_visit for each neighbour connected to the vertex, skips if vertex have been visited
	for( it = adj_list[vertices].begin(); it != adj_list[vertices].end(); it++)
	{
		if (parent[*it] == -1)
		{
			parent[*it] = vertices;
			cout << "visiting " << *it << " ..." << endl;
			dfs_visit( *it,adj_list, parent);

			
		}
	}
}

//Top level to guarantee visit to every vertex even if it is unconnected
void DFS(int start_vertex, int nVertices, list<int>* adj_list)
{
	int* parent = new int[nVertices]; //list of if vertices have been visited
	for (int i = 0; i < nVertices; i++)
	{
		parent[i] = -1; //set to -1 to indicate not seen
	}

	cout << "visiting new vertex" << start_vertex << " ..." << endl;
	dfs_visit(start_vertex, adj_list, parent);
	parent[start_vertex] = NULL; 
	
	//for each vertices in the graph visit it using dfs
	for (int i = 0; i < nVertices; i++)
		{
			if (parent[i] == -1) 
				{
					cout << "visiting new vertex" << i << " ..." << endl;
					parent[i] = -1;
					dfs_visit(i, adj_list, parent);
				}


	}
}


