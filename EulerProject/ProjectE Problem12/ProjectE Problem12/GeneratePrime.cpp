#include <set>
//Generate Prime List using sieve of atkin

//std::set<long long> GeneratePrimeList(long long ceiling, std::set<long long> &PreviousPrimeList)


std::set<long long> GeneratePrimeList(long long ceiling)
{
	std::set<long long> Prime_List;

	Prime_List.insert(2);
	for (long long iii = 3; iii<= ceiling; iii = iii +2) //populate list with odd numbers up to ceiling
	{
		Prime_List.insert(iii);
	}

	if (ceiling == 1) //if its 1 then no list
	{
		Prime_List.empty();
		return Prime_List;
	}

	else if (ceiling == 2) //if 2 then erase 1 return list
	{
		Prime_List.erase(1);
		return Prime_List;
	}
	
	else //otherwise
	{

		for (long long iii = 3; iii <= ceiling ; iii+= 2) //erase multiple of odd numbers
		{
			for (long long jjj = 2; iii*jjj <= ceiling; jjj++)
			{
			Prime_List.erase(iii*jjj);
			}

		}

		return Prime_List; //return left over list
	}

}