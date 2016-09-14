#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "math.h"
#include "Functions.h"

using namespace std;

highlow numbercheck(const int&, const int&, string&);
int compguess(const int&, highlow, const int&);
void gamemenu(char&);
void PlayerMode(const int MAX, const int MIN);
void CompMode(const int MAX, const int MIN);

int main()
{
	srand(unsigned(time(NULL))); //assign a seed for random number generator

	const int RANGE_MAX = 100;
	const int RANGE_MIN = 1;

	char gamemode = 'p';
	
	do
	{
		gamemenu(gamemode);

		if (gamemode == 'p')
		{
			PlayerMode(RANGE_MAX, RANGE_MIN);
		}
		else if (gamemode == 'c')
		{
			CompMode(RANGE_MAX, RANGE_MIN);
		}

	} while (gamemode == 'p' || gamemode == 'c');
		



	system("Pause");

}
	
