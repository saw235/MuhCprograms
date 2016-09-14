#include <iostream>
#include <vector>
#include <math.h>

bool isPrime(long long number) // take a number and determine if it is or not prime
{
   std::vector<long long> factorlist;
   for ( long long i = 2 ; i <= sqrt(number) ; i++)
   {
	   if (number%i == 0)
	   {
		   factorlist.push_back(i);
		   {
			if (factorlist.size() > 0)
					
				{
					//std::cout << factorlist.size() <<std::endl;
					return false;
				}
		   }
	   }
   }
	return true;
}