#include "Bag.h"
	//takes in random number
	//generates block in random order
	Bag::Bag(long long seed)
	{
		using namespace std;

		mt19937 gen(seed);

		m_nextseed = gen();


		std::vector<Block> temp_7BLOCS;
		//populate bag with 7 diff types of blocks
		for (int i = 1; i <8; i++)
		{
			temp_7BLOCS.push_back(Block(static_cast<BLOCTYPE>(i),Position(-1,-1),gen()));
		}

		m_blocleft = 7;// initialize with 7

		//shuffle them with seeds number
		while (temp_7BLOCS.size() > 0)
		{
			int smallestindex = 0;
			long long smallestseed = temp_7BLOCS[0].GetInseed();
			for (vector<Block>::iterator it = temp_7BLOCS.begin(); it != temp_7BLOCS.end(); it++)
			{
				
				
				if (it->GetInseed() <= smallestseed)
				{
					smallestseed = it->GetInseed();
					smallestindex = it - temp_7BLOCS.begin();
				}
			}

			_7BLOCS.push_back(temp_7BLOCS[smallestindex]);
			temp_7BLOCS.erase(temp_7BLOCS.begin() + smallestindex);

		}


	}
	
	Bag& Bag::GetBag()
	{
		return *this;
	}

	Block Bag::GetNextBloc(const Position& InitialPos)
	{
		Block temp = _7BLOCS.back();
		_7BLOCS.pop_back();

		m_blocleft -= 1;

		temp.SetBlocPos(InitialPos);

		return temp;
	}

	long long Bag::GetNextSeed()
	{
		return m_nextseed;
	}

	std::vector<Block>& Bag::Get_7Bloc()
	{
		return _7BLOCS;
	}
