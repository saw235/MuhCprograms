#include <iostream>
#include <vector>

int noffactor(int number)
{
	int iii = 1;
	std::vector<int> factorlist;

	while (iii <= number)
		{   
			if (number%iii == 0)
			{
			factorlist.push_back(iii);
			}
			iii++;
		}

	return factorlist.size();
}