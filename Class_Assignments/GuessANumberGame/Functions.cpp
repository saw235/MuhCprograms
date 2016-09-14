#include "Functions.h"

//accepts 2 numbers and compares them
//also accepts msg to output the correct msg accordingly to each case
//returns true when found, false otherwise
highlow numbercheck(const int &number, const int &numbercompared, string& msg)
{
	highlow found = TOOLOW;

	cout << "You've have entered " << numbercompared << "."<<endl; 

	if (number > numbercompared)
	{
		msg = "Sorry, your guess is too low, try again.\n\n";
		found = TOOLOW;
	}
	else if (number < numbercompared)
	{
		msg = "Sorry, your guess is too high, try again.\n\n";
		found = TOOHIGH;
	}
	else if (number == numbercompared)
	{
		msg = "Congrats, you've guessed the correct number!\n\n";
		found = FOUND;
	}

	return found;
}

//highlow - 0 for too low, 1 for too high, 2 for found, 3 for first time guessing

int compguess(int& MAX, int& MIN, highlow status = INITIAL, const int& previousguess = 0)
{

	switch (status)
	{
	case INITIAL:
	{
					break;
	}
	case TOOLOW:
	{
				   MIN = previousguess; //change range from previous guess to MAX
				   break;
	}
	case TOOHIGH:
	{
					MAX = previousguess; // change range from MIN to previousguess
					break;
	}
	}

	

	return (MAX + MIN)/2;
}

void gamemenu(char& gamemode)
{
	while (1)
	{
		cout << "Would you like to (p)lay or watch the (c)omputer play? \n\t(Type anything else to exit game)" << endl;
		cin >> gamemode;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(50, '\n');
			continue;
		}
		else
		{
			break;
		}
	}
}

void PlayerMode(const int MAX, const int MIN)
{
	int guess;
	int random_number;
	string msg = "";
	highlow guessstate = INITIAL;

	random_number = (rand() % (MAX-MIN+1)) + MIN; //assign a random number from MIN to MAX
	while (guessstate != FOUND)
	{
		//check if integer is entered
		while (1)
		{

			cout << "Enter your guess in between " << MAX << " and " << MIN << " (integer):	";
			cin >> guess;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(50, '\n');
				continue;
			}
			else
			{
				break;
			}
		}

		guessstate = numbercheck(random_number, guess, msg);
		cout << msg;
	}



}

void CompMode(const int MAX, const int MIN)
{
	int guess;
	int random_number;
	int range_max = MAX;
	int range_min = MIN;
	int previous_guess = 0; 
	string msg = "";
	highlow guessstate = INITIAL;

	random_number = (rand() % (MAX - MIN + 1)) + MIN; //assign a random number from MIN to MAX
	while (guessstate != FOUND)
	{
		

		cout << "Enter your guess in between " << MAX << " and " << MIN << " (integer)." << endl;;
		guess = compguess(range_max, range_min, guessstate, previous_guess);
		
		previous_guess = guess; 
		
		guessstate = numbercheck(random_number, guess, msg);
		cout << msg;
	}

}