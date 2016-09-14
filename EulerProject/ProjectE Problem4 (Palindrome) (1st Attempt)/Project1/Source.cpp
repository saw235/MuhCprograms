
#include <iostream>
#include <sstream>
#include <string>

bool isPalindrome(int);
bool isPofnumbersof3digit(int number, int llimitofnumber);

int main()
{
	const int ulimit = 999*999;
	const int llimit = 100*100;
	int count = ulimit;
	int maxpalin = 0;
	while (count >= llimit)
	{
		if (isPalindrome(count) && isPofnumbersof3digit(count, ulimit/999))
		{
			maxpalin = count;
			break;
		}
		count--;
	}

	std::cout << maxpalin << std::endl;


	system("pause");
}


bool isPofnumbersof3digit(int number, int ulimitofnumber)
{
	for (int i= ulimitofnumber ;i > 99; i--)
	{
		int resultantnumber = 0;
		if (number%i == 0)
		{
			resultantnumber = number/i;
			if (resultantnumber >99 && resultantnumber <1000)
			{
				return true;
			}
		}
	}
	return false;
}

		

bool isPalindrome(int number)
{
	using namespace std;
	string converted="";
	stringstream convert;
	convert << number;
	convert >> converted;
    int strlength = converted.length();
    for (int iii = 0; iii< strlength/2; iii++)
	{
		if (converted[iii] != converted[strlength - 1 - iii]) 
		{
			return false;
		}
	}

	return true;

}
