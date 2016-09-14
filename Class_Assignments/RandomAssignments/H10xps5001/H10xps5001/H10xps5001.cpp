/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 30th 2014
Assignment:	 HW10

This program calculates the average of a specified row of a 2D array

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

using namespace std;

//Global Constants
const int NROWS(10);
const int NCOLS(7);

//Function Name: row_ave
//This function calculates the average of a specified row of a 2D array
//Passed: x[][]  <-- 2D array
//		  row  <-- row to be calculated
//Return:  sum/NCOLS  <-- the average in a row
double row_ave(double x[][NCOLS], int row)
{
	int sum = 0;

	for (int iii = 0; iii < NCOLS; iii++)
	{
		sum += x[row][iii];	
	}

	return sum/NCOLS;
}

int main()
{
	//Open data file
	ifstream data("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\H10xps5001\\H10xps5001\\power1.txt");

	//Exits if fails to open file
	if (data.fail())
	{
		cout << "Failed to open file! Exiting..." <<endl;
		
		system("Pause");
		return 0;
	}

	//Declare and initialize the 2D array with 0s
	double data_array[NROWS][NCOLS] = {0};
	
	//Fill the 2D arrays with data from file
	for (int iii = 0; iii < NROWS; iii++)
	{
		for (int jjj = 0; jjj < NCOLS; jjj++)
		{
			data >> data_array[iii][jjj];
		}
	}

	//Calculates by calling the function row_ave and echos the results.
	for (int iii = 0; iii < NROWS; iii++)
	{
		cout << "Week " << iii+1 << "'s average is " << row_ave(data_array,iii)<<endl;
	}

	//close file
	data.close();

	system("Pause");
	return 0;

}