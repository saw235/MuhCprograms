#include <vector>

int productof5digits(const std::vector<int> &vectorlist, int upperlimit, int lowerlimit)
{
	int product = 1;
	
	for (int i = lowerlimit; i < upperlimit; i++)
	{
		product *= vectorlist[i];
	}
	return product;
}