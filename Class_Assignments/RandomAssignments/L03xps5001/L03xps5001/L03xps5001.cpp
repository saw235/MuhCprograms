/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Feb 4th 2014
Assignment:	 Lab #3: Input/Output

This program calculates the Celsius and Fahrenheit temperature at a given depth.
Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/
#include <iostream> // input output stream library
#include <iomanip> //for set percision


void main()
{
	using namespace std;
	double dCelcius(0), dFarenheit(0), dDepth(0); // declare and initialize variables
	

	cout << "This program calculates the Celsius and Fahrenheit temperature at a given depth." << endl; //description of program
	cout << "Please enter the following:	\n" << endl; // prompts user to enter data

	while (1)
	{
			cout << "Depth, D (km)	: ";
			cin >> dDepth; // input command 

			if (cin.fail()) // check for invalid input such as alphabets or anything non numerical
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout <<"\nPlease enter a valid number."<<endl;
				continue; // return to start of loop
			}

			break;  //break out of loop
	}		

	

		dCelcius = 10*dDepth+ 20; // calculations

		dFarenheit = 1.8*dCelcius+32; // convert celcius to farenheit

	//echos data
	cout<< "\nAt the depth of "<< fixed<< std::setprecision(2) << dDepth<< "km into the earth, the Celsius temperature is "<< dCelcius;
	cout<< "\nand the Fahrenheit temperature is "<<fixed << setprecision(2)<< dFarenheit<<".\n"<<endl;

	system("Pause");

}

