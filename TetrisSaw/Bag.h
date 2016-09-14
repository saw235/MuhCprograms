#pragma once

#include "Block.h"
#include <vector>
#include <random>

class Bag
{
private:
	std::vector<Block> _7BLOCS;

	
	long long m_nextseed;


public:

	int m_blocleft;
	//takes in random number
	//generates block in random order
	Bag(long long seed);
	
	
	Bag& GetBag();


	Block GetNextBloc(const Position &InitialPos);
	

	long long GetNextSeed();

	std::vector<Block>& Get_7Bloc();
	
};
	
