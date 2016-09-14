/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Jan 27st 2014
Assignment:	 HW3

This program This program calculates the surface area of the sector of a sphere 

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if I knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <iomanip> //for setprecision()



void main()
{
	using namespace std;
	double dSurfaceArea(0), dRadius(0); // declare and initialize
	const double PI = 3.14159;

	cout << "This program calculates the surface area of a sphere. \n" << endl; //Explanation on what the program does
	cout << "Please enter the following:	\n" << endl; // Prompts user to input

	while (1) // start loop
	{
			cout << "Radius, R(m)		: "; 
			cin >> dRadius;  //get value of radius from user and store it into the object cin


			// This block of codes checks from invalid input from user such as non-numerical entries and negative number and such
			{
				if (cin.fail()) //checks for type mismatch of input as in getting a char to an int
				{
					cin.clear(); // reset failbit
					cin.ignore(500, '\n'); // discard stream stored in cin
					cout <<"\nPlease enter a valid value.\n"<<endl;
					continue; //loops from first line
				}
			
				if (dRadius < 0 ) //checks for negative value
				{
					cout << "\nPlease enter a positive value.\n"<< endl;
					continue; //return to first line in loop if stuff went wrong
				}
			}//checking ends here

				break; //breaks out of loop if went well
				
	}//loop ends here
	

			


	dSurfaceArea = 4*((dRadius)*dRadius)*PI; // surface area of sphere formula

	cout << "\nArea is "<< fixed << setprecision(2) << dSurfaceArea << "m^2 when radius is "<< dRadius << " m."<< endl; //display area

	system("Pause");

}

