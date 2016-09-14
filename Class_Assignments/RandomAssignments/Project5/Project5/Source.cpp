#include <iostream>

using namespace std;




int nDivisor(int n1)
{
	int count = 0; //count of divisor
	for (int iii = 1; iii <= n1; iii++)
	{
		if ( (n1%iii) == 0)
		{
		  count++;
		}
	}

	return count; 
}


int trianglenumber(int n)
{
	return ((1+n)*n*0.5);
}

void main()
{
	int iii = 50;
	int nofdivisor(0);
	while (1)
	{
		
		nofdivisor = nDivisor(trianglenumber(iii));

		if (nofdivisor > 500)
		{
			break;
		}

		cout << iii;
		iii++;

	}

	cout << endl<< nofdivisor<< endl; 
	system("pause");


}