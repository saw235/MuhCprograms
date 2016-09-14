#include "RandomGraph.h"
#include <limits>	
#include <random>
#include <chrono>

//Constructor - Generates a random graph
RandomGraph::RandomGraph(int Vertices, double p)
{
	
	//creates a adjacency list of nVertices
	this->nVertices = Vertices;
	adjlist = new std::list<int>[nVertices];
	


	//Get the current system clock and use it as a seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	
	

	//generate a list of random edges
	//Traverse the entire matrix 
	for (int i = 0; i < nVertices; i++)
	{
		for (int j = 0; j < nVertices; j++)
		{
			//generate a probability between 0 and 1
			double random = (double)generator()/generator.max();
			
			//if the random number is less than p
			if ( random < p )
			{
				//add a edge between the two vertex
				adjlist[i].push_back(j);
			}
		}
	}

}