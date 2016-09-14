#include <iostream>
#include <math.h>
#include <algorithm>



int main()
{
	using namespace std;

	int a =0; int b = 1; int c = 2;
	bool nfound = true;
	
	while (nfound)
	{
		for (b = 1 ;b < c; b++)
		{
			for (a = 0; a < b; a++)
			{
				
				int tmpa = 1000 - b - c;
				if  (tmpa == sqrt((b+c)*(c-b)))
				{
					a = tmpa;
					nfound = false;
					break;
				}
				
			}
			if (nfound == false)
			{
				break;
			}

		}
		if (nfound == false)
			{
				break;
			}
		c++;
	}
	cout << " a\t:"<< a <<endl;
	cout << " b\t:"<< b <<endl;
	cout << " c\t:"<< c <<endl;
	cout << a*b*c << endl;

	system("Pause");
}
