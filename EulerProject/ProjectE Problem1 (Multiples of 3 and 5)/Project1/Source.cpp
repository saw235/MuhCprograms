#include <iostream>
int summultiples (int,int); 
int lcm (int, int);
int gcd (int, int);

int main()
{
    using namespace std;
	cout<< "Enter multiples to be summed \n" << endl;
    cout<< "Number 1: \t";
	int number1 = 0;
	int number2 = 0;
	cin >> number1;
	cout<< "Number 2: \t";
	cin >> number2;
	cout<< "Enter upperlimit: \t";
	int upperlim =0;
	cin >> upperlim;

	long sum1 = summultiples(number1, upperlim);
	long sum2 = summultiples(number2, upperlim);
	int lcmultiple = lcm(number1,number2);
	long sumlcm = summultiples(lcmultiple, upperlim);

	int tsum = sum1 + sum2 - sumlcm;
	cout<< "Lowest common multiple is " << lcmultiple << endl;

	cout<< sum1<< endl;
	cout<< sum2<< endl;

	cout << "Sum of multiples of " << number1 << " or " << number2 << " below 1000 is: \t"
		 << tsum << endl;

	system("pause");

}


int summultiples (int numberinput, int upperlim)
{
	long sum = 0;
	int currentvalue = 0;
	for ( int i = 1; currentvalue < upperlim ;i++)
	{
		currentvalue = numberinput*i;
		
		if (currentvalue < upperlim)
		
		{
		sum += currentvalue;
		}
	}
	return sum;
}

int gcd (int n1, int n2)
{ 
	int gdivisor = 0;
	
	for (int i = 1; (i <= n2)|| (i <= n1); i++)
	{
		if ((n1%i == 0) && (n2%i == 0))
		{
			gdivisor = i;
		}
	}
	return gdivisor;
}


int lcm (int n1, int n2)
  {
	  return (n1*n2)/gcd(n1,n2);
  }
