/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 25th 2014
Assignment:	 HW06

Generates a temperature table in a month

People whom I assisted: None

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Function Name: TempDiff
//This function takes in hi-lo temperature and returns the difference between the 2 temperature
//Passed: temp_low
//		  temp_high
//Return: temp_high-templow       <---- difference of 2 temperatures
double TempDiff(double temp_low, double temp_high)
{
	return temp_high-temp_low;
}


//program entry point
int main()
{
	fstream data; //ofstream object
	data.open("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\H06xps5001\\H06xps5001\\data.txt");

	if (data.fail()) //check file
	{
		cout << "Failed to open file! Exiting..." <<endl;
		
		system("Pause");

		return 0;
	}


	int day(0);
	double TEMP_HIGH(0);
	double TEMP_LOW(0);

	//table format
	cout <<setw(5) << "DAY" << setw(9) << "TempHi" << setw(9) <<"TempLo" 
			<< setw(9) <<"TempDiff" <<endl; 

	while(1) //loops until...
	{
		data >> day >> TEMP_HIGH >> TEMP_LOW; //reads in data

		if ( day == -999 || TEMP_HIGH == -999 || TEMP_LOW == -999) //any of these is -999
		{
			break; //then exit loop
		}

		// if not -999 output the compiled data
	
		cout << setw(5) << day <<setw(9) << TEMP_HIGH << setw(9) <<TEMP_LOW 
			<< setw(9) <<TempDiff(TEMP_LOW,TEMP_HIGH)<<endl; 

	}

	system("PAUSE");
	return 0;
}