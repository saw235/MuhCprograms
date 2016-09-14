/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Feb 11th 2014
Assignment:	 L04

This program This program will prompt for input and use a selection statement to determine results.

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <iomanip> //for setprecision()


using namespace std;


void main() //program starts here
{
	
	int iVolt(0);

	cout << "\n\n This program accepts time and displays the appropriate voltage depending on the input value." << endl; 
	cout << "\nPlease enter a value for time (t) in seconds." << endl; // prompt user what to do with the program

									//
	
	double dTime(0);

	

	while (1)
	{
		cout << "t (s) :  "; // prompt user to enter	
		cin >> dTime;
		if ((dTime < 2) && (dTime >= 0)) // if between 0 to inclusive of 0 means 0 volts
		{
			iVolt = 0;
			break;
		}
		else if (dTime >= 2) // more than or equal to 2 means 3 volts
		{
			iVolt = 3;
			break; 
		}
		else if (cin.fail())// anything non numeric
		{
			cout << "Invalid input. Please try again. (t must numerical and positive!) \n" << endl; // error message
			cin.clear();
			cin.ignore(500, '\n'); // clear fail bit and extract out the garbage input
			continue; // loops
		}
		else // if t is negative
		{
			cout << "Invalid input. Please try again. (t must numerical and positive!) \n" << endl; // error message
			continue;
		}
	}


	cout << "\nThe voltage is "<< iVolt << " V"<< " when 't' is "<< fixed << setprecision(2)<< dTime<< " s.\n" ; 
	system("pause");

}
