#include <set>

std::set<long long> GeneratePrimeList(long long ceiling);

std::set<long long> Prime_Factor(long long number)
{
	std::set<long long> FactorList = GeneratePrimeList(number);

	for (std::set<long long>::iterator it = FactorList.begin(); it != FactorList.end();)
	{
		if ( (number%(*it)) != 0)
		{
			FactorList.erase(*it); //remove the useless prime
			it = FactorList.begin(); //set iterator to beginning again
		}
		else
		{
			it++;
		}
	}

	return FactorList;
}