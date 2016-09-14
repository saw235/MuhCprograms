/*
Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 23rd 2014
Assignment:	 H09

This program generates 2 arrays of 500 floating numbers with predetermined variance and average

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <cstdlib> //rand() srand()
#include <iostream> // cout cin
#include <iomanip> 
#include <ctime> //time()
#include <cmath> //pow


//Fucntion Name: Rand_Float
//This function returns a random floating number between min and max
//Arguments passed: min =low limit of range
//                   max = upper limit of range
//Returns ((double)rand()/RAND_MAX)*(max-min)+min
double rand_float(double min, double max)
{
	return (((double)rand()/RAND_MAX)*(max - min) + min);
}

//Fucntion Name: Average
//This function returns the average of an array of doubles
//Arguments passed: array
//                  size
//Returns sum/size
double Average(const double array[], int size)
{
	double sum(0);

	for (int iii = 0; iii < size; iii++)
	{
		sum += array[iii];
	}

	return sum/size; 
}

//Function for variance, NOT USED.
/*double Variance(const double array[], int size)
{
	double sum(0);
	for (int iii = 0; iii < size; iii++)
	{
		sum += array[iii]*array[iii];
	}

	return (sum/size - pow(Average(array, size),2));
}*/      


int main()
{

	using namespace std;
	const int SIZE = 500; // set the determined number of arrays


	cout << "This program generates 2 sets of 500 random floating numbers with average of 4"
		<< "\nand variances of 0.5 and 2" <<endl<<endl;
	srand(time(0)); //seed

	//declare 2 arrays to store 500 floating points each
	double sample1[SIZE] = {0};
	double sample2[SIZE] = {0};

	// range for random numbers with average 4, variance 0.5
	const double MIN1 = 4 - 0.5*sqrt(6);
	const double MAX1 = 4 + 0.5*sqrt(6);

	// range for random numbers with average 4, variance 2
	const double MIN2 = 4 - (2 * sqrt(3));
	const double MAX2 = 4 + (2 * sqrt(3));


	//Fill the arrays with random floating point numbers betwwen the upper limit and lower limit
	for (int iii = 0; iii < SIZE; iii++)
	{
		sample1[iii] = rand_float(MIN1,MAX1);
		sample2[iii] = rand_float(MIN2,MAX2);
	}

	//echo the arrays
	cout << "Set 1:\n ";
	for (int iii = 0; iii < SIZE; iii++)
	{

		//new line every 5 numbers
		if (iii%5 == 0) 
		{
			cout << endl;
		}
		cout << fixed << setprecision(3) <<setw(7)<< sample1[iii];
	}

	cout << "\n\nSet 2:\n ";
	for (int iii = 0; iii < SIZE; iii++)
	{
		if (iii%5 == 0)
		{
			cout << endl;
		}
		cout<< fixed<< setprecision(3) <<setw(7)<< sample2[iii];
	}

	cout << "\n\nCalculated average of the first 500 samples is " <<Average(sample1, SIZE) << endl;
	cout << "Calculated average of the second 500 samples is " << Average(sample2, SIZE) << endl; //echo the Average of both arrays
	system("Pause");

	return 0; 

}
