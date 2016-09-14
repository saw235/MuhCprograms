#include <iostream>
#include "isPrime.h"

int main()
{
	using namespace std;
	int upperlimit = 10001;
	int startingnumber = 3;
	int number = startingnumber;
	int latestprime = 0;
	for (int index = 2; index <= upperlimit; number = number + 2)
	{
		if (isPrime(number))
		{
			index++;
			latestprime = number;
		}
	}

	cout << latestprime << endl;
	system ("pause");
}