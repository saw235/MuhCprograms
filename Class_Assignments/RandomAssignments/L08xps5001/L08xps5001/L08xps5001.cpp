/*


Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 25th 2014
Assignment:	 L08

This program generates a table of the coversion of Pesos to Dollars for up to N times with X increments.

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

//Fucntion Name: PesoCalc
//This function generates a table of the coversion of Pesos to Dollars given
// the intial value,increments and number of increments
// 
//Arguments passed: initial_peso = initial value of peso which the table starts at
//                   increment = the amount which the table increase by
//					 Nsize = size of table

//Return none 
void PesoCalc(double initial_peso, double increment, int N_size)
{
	const double DOLLAR_PESO_RATE = 9.02; //rate of dollar to peso 
	
	cout << "\nPESO\t||\tDOLLARS"<<endl;
	cout << "---------------------------"<<endl;

	for (int iii = 0; iii < N_size; iii++)  //if loop count is less than the size required, loop more
	{
		cout << fixed << setprecision(2) << initial_peso + (iii * increment) << "\t||\t" << 
		setprecision(3) <<(initial_peso + (iii * increment))/DOLLAR_PESO_RATE <<endl;
	}

	return;
}

//entry point of program
int main()
{

	cout << "This program generates a table of the coversion of Pesos to Dollars\nfor up to N times with X increments.\n\n";

	

	double initial_peso(5); 
	double increment(5);
	int nLines(10);

	while (1)
	{
		cout << "Please enter the initial peso amount:	"; //prompts user to enter the initial amount of peso
		cin >> initial_peso; //assign value to initial_peso

		if (cin.fail() || initial_peso < 0) //if failbit is set or negative number, display error message
			{
				cout << "\n\nInitial peso amount must be more than or equal to 0!\n\n";
				cin.clear(); //clear failbit
				cin.ignore(50,'\n');
				continue; //loops
			}

		break;
	}

	

	while (1)
	{
		cout << "Please enter the increment of the table:	";  //prompts user to enter the amount to be increased by
		cin >> increment;  //assign value to increment
		if (cin.fail() || increment <= 0)
			{
				cout << "\n\nIncrement must be a positive number!\n\n";
				cin.clear();
				cin.ignore(50,'\n');
				continue;
			}

		break;
	}



	

	while (1)
	{
		cout << "Please enter the size of the table (number of lines):	";  //prompts user to enter the size of the table
		cin >> nLines; //assign value to nLines
		if (cin.fail() || nLines < 0)
			{
				cout << "\n\nSize must be a positive integer!\n\n";
				cin.clear();
				cin.ignore(50,'\n');
				continue;
			}

		break;
	}

	cout << "\n\nYou've entered "<< initial_peso << " for initial amount of peso \n"
		<< increment << " for the increment\n"
		<< "and " << nLines << " for the size of the table.\n";

	PesoCalc(initial_peso,increment,nLines); //calls the function to calculate and display stuff

	system("Pause");

	return 0;
	
}