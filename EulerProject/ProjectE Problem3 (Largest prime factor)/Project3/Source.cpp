#include <iostream>

int main()
{
	using namespace std;
	long long number = 600851475143;
	long long divresult = number;
	long long factor = 0;
	for (long long iii = 2; divresult != 1 ;iii++)
	{
		while (divresult%iii == 0)
		{
			divresult = divresult/iii;
			factor = iii;
		}

	}
 
	cout<< factor << endl;
	system("pause");
}

