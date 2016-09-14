#include <boost/math/common_factor.hpp>
#include <iostream>

int main()
{
	int lcm = 1;
	for (int i = 1; i <= 20; i++)
	{

		if (i <= 20)
		{
		lcm = boost::math::lcm<int>(lcm, i);
		}

	}

	std::cout << lcm << std::endl;

	system("pause");
}