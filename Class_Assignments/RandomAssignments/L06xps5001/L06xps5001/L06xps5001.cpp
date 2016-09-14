/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 4th 2014
Assignment:	 L06

This program search a file of numbers and write the largest and smallest numbers to the screen.

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
int main()
{
	cout << "This program search a file of numbers and write the largest and\nsmallest numbers to the screen.\n\n";
	ifstream inputfile; //file object

	inputfile.open("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\L06xps5001\\Value.txt"); //open file

	if (inputfile.fail()) //check file
	{
		cout << "Failed to open file" << endl;
		system("pause");
		return 0;
	}
	
	int ncount(0);

	inputfile >> ncount;

	int* data = new int[ncount]; //allocate memory for data
	int nMin(0);
	int nMax(0);

	for (int iii = 1; iii <= ncount ; iii++) // get data from text file
	{
		inputfile >> data[iii-1];	 
		cout << data[iii-1] << "\t"; // echo data

		if (iii%3 == 0)  // new lines every 3 data
		{
			cout << endl;
		}

		if (iii ==1) //if loop count is 1 set nMin and nMax to initial data
		{
			nMin = data[iii-1];
			nMax = data[iii-1];
		}
		else //else loopcount is not 1
		{
			if (data[iii-1] < nMin) // then compare values
				{
					nMin = data[iii-1];
				}
			else if (data[iii-1] > nMax)
				{
					nMax = data[iii-1];
				}
		}
	}


	inputfile.close(); //close file
	delete[] data; //deallocate data

	cout << "\n\nThe maximum and minimum values in the data file are "<< nMax << " and " << nMin << endl <<endl;

	system("pause");
	return 0;

}

