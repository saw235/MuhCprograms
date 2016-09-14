/*
Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 8th 2014
Assignment:	 L09

This program do some stuff with arrays

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

int main()
{
	srand(time(0)); //seed random value
	const int MAX = 10; // size of arrays
	const double range_max = 20; // range for random floating points
	const double range_min = 2;

	int sample[MAX] = {0}; // arrays of MAX integers
	double test[MAX] = {0}; //arrays of MAX floating numbers


	cout << "Please enter a set of 10 integer numbers	:" << endl; //prompt user to input numbers

	for (int iii = 0; iii < MAX; iii++)
	{
		cout << "#" << iii + 1 << "\t: "; 
		cin >> sample[iii]; //stores in array of integers
	}

	cout << endl; 

	for (int jjj = 0; jjj < MAX; jjj++)
	{
		test[jjj] = Rand_Float(range_min,range_max); //generates random floating number 
													//then stores in array of floating numbers
	}


	cout <<"Set of integer numbers is : \n"<<endl;

	for (int iii = 0; iii < MAX; iii++)
	{
		cout << sample[iii] <<" "; // echo integers stored using a loop
	}

	cout << endl << endl;
	cout << "Set of 10 random floating numbers between 2 and 20 is : \n" << endl;
	for (int jjj = 0; jjj < MAX; jjj++)
	{
		cout << test[jjj] << endl; //echos floating number stored
	}

	system("Pause");

	return 0;
}
