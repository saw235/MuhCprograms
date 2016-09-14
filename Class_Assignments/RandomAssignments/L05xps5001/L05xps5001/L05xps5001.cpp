/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Feb 25th 2014
Assignment:	 L05

This program displays a table of expansion lengths for a steel bridge that is
7365 meters long at 0 degrees Celsius, as the temperature increases to 40 degrees in 5 degree increments.

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <iomanip>

using namespace std;
void main()
{
	const double EXPANSION_COEFFICIENT(11.7E-6); //variables and constants
	const int INITIAL_TEMP(0);
	const int FINAL_TEMP(40);
	const int INITIAL_LENGTH(7365);
	const int TEMP_INCREMENT = 5; 
	int iTemp(0);

	cout << "This program displays a table of expansion lengths for a steel bridge that is \n7365 meters long at \'T\' degrees Celsius\n\n";

	cout << "   | T (C)\t|   dL(m)\t|" <<endl;
	cout << "   |____________________________|"<<endl;

	for (; iTemp <= FINAL_TEMP; iTemp += TEMP_INCREMENT) // loops starts
	{
		double delta_length = EXPANSION_COEFFICIENT*INITIAL_LENGTH*(iTemp-INITIAL_TEMP); //formula for increase in length
		cout << "   |\t" <<iTemp <<"\t|   " << fixed<< setprecision(3) <<delta_length <<"\t|"<< endl; //output
	}

	system("pause");
}
