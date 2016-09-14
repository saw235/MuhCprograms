

#ifndef _RANDOMGRAPH_
#define _RANDOMGRAPH_

#include <list>

//Generates a random graph
class RandomGraph
{
	int nVertices;
	
	//pointer to a adjacency list for graph
	std::list<int> *adjlist;
	
	//pointer to a n by n matrix
	int** adjmat[];
	
	public:
	//Constructor - Creates a random graph based on the number of vertices and initial seed
	RandomGraph(int Vertices, double p)
	

};




#endif