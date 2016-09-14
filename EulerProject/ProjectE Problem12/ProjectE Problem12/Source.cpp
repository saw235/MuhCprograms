#include <iostream>
#include <set>


std::set<long long> Prime_Factor(long long number);

using namespace std;




int nDivisor(long long n1) 
{
	int nDivisor = 0;
	for (int iii = 1; iii <= n1; iii++)
	{
		if (n1 % iii == 0)
		{
			nDivisor++;
		}
	}

	return nDivisor;
}

long long trianglenumber(long long n)
{
	return ((1+n)*n*0.5);
}

void main()
{
	long long iii = 2;
	
	for (; nDivisor(trianglenumber(iii))<= 500; iii++)
	{
	}

	cout << trianglenumber(iii);
	system("pause");


}