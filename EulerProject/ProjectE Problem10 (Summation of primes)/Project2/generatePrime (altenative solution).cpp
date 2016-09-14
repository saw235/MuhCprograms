#include <set>

long long generatePrime(long long range)
{
std::set<long long> erased;
long long sum = 2;
for (long long i = 3; i < range; i+= 2)
{
	if (!erased.count(i))
	{
		sum += i;
		for (long long j =  1, count = i; j*count < range; j += 2)
		{
			erased.insert(j*count);
		}

	}
}
return sum;
}


