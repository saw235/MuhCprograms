/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Feb 5th 2014
Assignment:	 HW4

This program This program evaluates the truth and false for the expression !((a||b) && c))

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
#include <string> // string class


using namespace std;

void inputtobool(bool& variable) //function for char input then set bool variable accordingly
{

	char input;
	bool invalidinput = true; 
	
	while (invalidinput) //set up a loop in the case of invalid input
	{
	cin >> input;
	
		if ((input == 'T')||(input == 't')) //if input is either T or t then make the variable passed true
			{
				variable = true;
				invalidinput = false;
				
			}else
				if ((input == 'F')||(input == 'f')) // if it is f make it false
					{
						variable = false;
						invalidinput = false;
					}
					else // anything else displays error message and loops
						{
							cout << "Invalid input. Please try again.		:  ";
							invalidinput = true;
							cin.clear();
							cin.ignore(500, '\n'); // clear fail bit and extract out the garbage input
						}
	}
}

string printtruefalse(bool variable) // return true or false string depending on variable so that it could be appended to the end of << operator
{
	if (variable)
	{
	return "TRUE";
	}
	else
	{
		return "FALSE";
	}
}


void main() //program starts here
{
	
	
	bool a,b,c; //boolean variables

	cout << "\n\n This program evaluate the truth and false for the expression !((a||b) && c))" << endl; 
	cout << "\nPlease type in \"T/F\" (TRUE or FALSE) for each a, b, and c.\n" << endl; // prompt user what to do with the program

	cout << "a  :  "; // prompt user to enter									//
	inputtobool(a); // change t/f input to boolean								//
																				//   a
	cout << "a is "<< printtruefalse(a) << ".\n"<< endl;						//

	
	cout << "b  :  ";															// 
	inputtobool(b);																//
																				//   b
	cout << "b is "<< printtruefalse(b) << ".\n"<< endl;						//
	
	cout << "c  :  ";															//
	inputtobool(c);																//   c
																				//
	cout << "c is "<< printtruefalse(c) << ".\n"<< endl;	
	
	cout << "\n!((a||b)&& c) is "<< printtruefalse(!((a||b)&& c))<< " when a is "<< printtruefalse(a) << ", b is "<< printtruefalse(b)<< ", and c is "<< printtruefalse(c) << ".\n" << endl; //display result


	system("pause");

}
