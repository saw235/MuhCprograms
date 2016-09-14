/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 30th 2014
Assignment:	 HW07

Simulates a dice game
People whom I assisted: Kyle

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iomanip>

using namespace std;


//Function Name: rand_INT
//This function takes in range of values and returns random number between that range
//Passed: min 
//		  max
//Return:  (rand()% (max-min + 1)) + min;  <---- random numbers in range min and max
int rand_INT(int min, int max)
{
	return (rand()% (max-min + 1)) + min;
}




int main()
{
	const int MAX_DICE_FACE = 6; //highest number on the dice
	const int MIN_DICE_FACE = 1; //lowest number on the dice
	time_t timer; //object for current time	
	srand(time(&timer));  //set current time as the seed for srand

	long nrolls(0); //number of rolls to simulate
	int sum(0); //sum of the 2 faces
	double percentage_of_eight(0); //percentage

	int count(0); //the number of times the eights appears

	cout << "This program simulates the rolls of 2 fair dice and approximates the precentage outcome of the rolls"<<endl;
	cout << "\n\nPlease enter the number of rolls to simulate. \n(For optimum speed please enter a value less than 9999999)" << endl;

	cout << "\n\nNumber of rolls :	"; //prompts for input (of number of rolls)
	cin >> nrolls;

	for (int iii = 0; iii < nrolls; iii++) //creates a loops
	{
		long first_result = rand_INT(MIN_DICE_FACE,MAX_DICE_FACE); //gets a random number in range min and max
		long second_result = rand_INT(MIN_DICE_FACE,MAX_DICE_FACE); // same 


		// if sum is 8 then add 1 to count
		sum = first_result + second_result;

		if (sum == 8)
		{
			count++;
		}

	}

	percentage_of_eight = ((double)count/nrolls)*100; //percentage formula = (count/total)*100

	//echo results
	cout << "\n\nThe percentage chance of getting eights is " << fixed <<setprecision(4)<< percentage_of_eight <<" %!" <<endl;
	

	system("Pause");
	return 0;
}
