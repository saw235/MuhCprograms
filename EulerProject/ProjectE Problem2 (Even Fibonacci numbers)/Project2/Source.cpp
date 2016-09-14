#include <iostream>

int fibonacci(int);

int main()
{
	using namespace std;

	long fnumber = 0;
	int sum = 0;

	for (int iii = 1; fnumber <= 4000000; iii++)
	{
		fnumber = fibonacci(iii);

		if ((fnumber%2==0) && (fnumber<=4000000))
		{
			sum+= fnumber;
		}
	}
	
	cout<< sum <<endl;
	system("pause");
}

int fibonacci( int index)
{
	int fnumber = 0;
	if (index < 1)
	{
		return 0;
	}
	if (index == 1)
	{
		return 1;
	}
	if (index == 2)
	{
		return 2;
	}
	else 
	{
		fnumber = fibonacci(index - 2) + fibonacci(index -1);
		return fnumber;
	}
}