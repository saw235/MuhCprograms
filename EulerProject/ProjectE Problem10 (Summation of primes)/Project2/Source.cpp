#include <iostream>
#include <vector>
#include <math.h>

bool isPrime(long long number);
int main()
{
	int sum = 2;
	for (long long number = 3; number < 2000000; number += 2)
	{
		if (isPrime(number))
		{
			sum += number;
		}
	}

	std::cout << sum << std::endl;
	system("Pause");
}	
