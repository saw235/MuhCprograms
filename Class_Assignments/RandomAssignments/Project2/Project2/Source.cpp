/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Jan 21st 2014
Assignment:	 Lab #2: Constant and Variable Statement

This program defines a constant, defines and initializes some variables and prints out the values.

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/


#include <iostream> //input output stream library
#include <iomanip> // for setprecision
using namespace std;

int main() //entry point for program
{
	
	const double ELECRADIUS = 2.8179403267e-15; // set the radius of electron as constant 

	float area(2.5), volume(6.6); //declare and initialize variables
	int count(10);

	//displays output 
	cout << setprecision(11) << "The electron radius is: " << ELECRADIUS << "m\n"<< endl; //setprecision to increase the decimals
	cout << "The area is: " << area << "m^2\n"<< endl;
	cout << setprecision(3)<< "The volume is: " << volume << "m^3\n"<< endl;
	cout << "The number of electron is: " << count << "\n" <<  endl; // backslash for formatting

	system("pause");

	return 0; //return control to windows

}