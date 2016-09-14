/*
Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 15th 2014
Assignment:	 L10

This program gives the average, minimum and maximum of an random generated set of numbers

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream> // for cout cin etc
#include <cstdlib> //for rand()
#include <ctime> //for time()
#include <iomanip>

using namespace std;

//Fucntion Name: Rand_Float
//This function returns a random floating number between min and max
//Arguments passed: min =low limit of range
//                   max = upper limit of range
//Returns ((double)rand()/RAND_MAX)*(max-min)+min
double Rand_Float(double min, double max)
{
	return ((double)rand()/RAND_MAX)*(max-min)+min; //divide by RAND_MAX so that its between 0 and 1
}

//Fucntion Name: Maximum
//This function returns the maximum value given an array
//Arguments passed: number_set  --- the array
//                   size --- size of array
//Returns maximum
double Maximum(const double number_set[], int size)
{
	double maximum = number_set[0];
	for (int iii = 0; iii<size; iii++)
	{
		if (maximum < number_set[iii])
		{
			maximum = number_set[iii];
		}
	}

	return maximum;
}

//Fucntion Name: Minimum
//This function returns the minimum value given an array
//Arguments passed: number_set  --- the array
//                   size --- size of array
//Returns minimum
double Minimum(const double number_set[], int size)
{
	double minimum = number_set[0];
	for (int iii = 0; iii<size; iii++)
	{
		if (minimum > number_set[iii])
		{
			minimum = number_set[iii];
		}
	}

	return minimum;
}

//Fucntion Name: Average
//This function returns the average value given an array
//Arguments passed: number_set  --- the array
//                   size --- size of array
//Returns sum/(size +1)
double Average(const double number_set[], int size)
{
	double sum(0);

	for (int iii = 0; iii < size; iii++)
	{
		sum += number_set[iii];
	}

	return sum/size;  //takes the sum divided by the total number
}

int main()
{
	srand(time(0)); //seed random value
	const int MAX = 500; // size of arrays
	const double range_max = 20; // range for random floating points
	const double range_min = 70;

	double test[MAX] = {0}; //arrays of MAX floating numbers


	for (int jjj = 0; jjj < MAX; jjj++)
	{
		test[jjj] = Rand_Float(range_min,range_max); //generates random floating number 
													//then stores in array of floating numbers
	}

	cout << endl << endl;
	cout << "Set of " << MAX <<" random floating numbers between "<<range_min<<" and "<<range_max<<" is : \n" << endl;
	for (int jjj = 0; jjj < MAX; jjj++)
	{
		if (jjj % 10 == 0)
		{
			cout <<endl;
		}

		cout << fixed <<setprecision(3) <<setw(6) <<test[jjj] << " "; //echos floating number stored
		
	}

	
	//calls function and outputs
	cout << "\n\nMaximum value in the number set is " << Maximum(test, MAX) << endl;
	cout << "Minimum value in the number set is " << Minimum(test, MAX) << endl;
	cout << "The average of the number set is " << Average(test, MAX) << endl;
	
	system("Pause");

	return 0;


}
