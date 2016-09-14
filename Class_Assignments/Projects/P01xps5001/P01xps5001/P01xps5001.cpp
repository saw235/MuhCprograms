/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		Feb 17th 2014
Assignment:	 P01

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream>
#include <string>
#include "math.h"
using namespace std;

void problem1() // problem 1 (Simulation of a portion of the control software for the vehicle)
{
		cout << "\n\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\PROBLEM 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n";


	cout << "This program simulates a portion of the control software for a vehicle\n\n";
	
	//variables to simulate switches and gearshift
	bool childLock(0), masterLock(0); 
	char gear = 'P';

	//door structure with switches which influences it.
	struct door
	{
		bool dBSwitch; // 1 for activated, else 0
		bool inHandle;  // 1 for handle pulled, 0 for idle
		bool outHandle;

		string bState; 
	};

	door doorR = {0, 0, 0}; // initialization list *everything is set to 0 
	door doorL = {0, 0, 0};

	
	
	while (1)
	{
    cout << "Please input the settings for switches and gear shift in the order:";
	cout << "\n\nDashboard switches for left and right sliding door, \nchild lock and master lock (0 for off and 1 for activated).";
	cout << "\nInside and outside hands on the left and right doors (1 and 0).";
	cout << "\nAnd the gear shift setting (one of P N D 1 2 3 R).";
	cout << "\n\nTypical input would be  0 0 0 1 0 1 0 0 P.";
	
	cout << "\n\nInput	:		";
	cin >> doorL.dBSwitch >> doorR.dBSwitch >> childLock >> masterLock >> doorL.inHandle >> doorL.outHandle >> doorR.inHandle
		>> doorR.outHandle >> gear; //input
		if (cin.fail()) // chk for invalid input
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout << string(5, '\n');
				cout << "Invalid input. Please try again.\n\nTypical input would be  0 0 0 1 0 1 0 0 P." << endl; 
				continue;
			}
		switch (gear) //chk for valid gears
			{
			case 'P':
			case 'N':
			case 'D':
			case '1':
			case '2':
            case '3':
			case 'R':
				{
					break;
				}
			default: 
				{
				 cout << string(5, '\n');
				 cout << "Invalid input. Please try again.\n\nNote that gear can only take (P N D 1 2 3 R) as input." << endl; 	
				 continue;
				}
			}
	break;

	}
	
	//evaluation of combination starts here

	if ( !masterLock || gear != 'P') //either one of these is true, both door is locked 
	{
		doorR.bState = "CLOSED";
		doorL.bState = "CLOSED";
	}
	else if (masterLock && gear == 'P') // if masterLock is activated and gear is set to P 
	{
		if (childLock) // if childlock activated inHandle does not work
		{
			doorL.inHandle = 0;
			doorR.inHandle = 0;
		}

		//evaluate doorL
		if (doorL.dBSwitch || doorL.inHandle || doorL.outHandle) // either one of these is true, the door is open
		{
			doorL.bState = "OPENED";
		}
		else
		{
			doorL.bState = "CLOSED";
		}

		//evaluate doorR
		if (doorR.dBSwitch || doorR.inHandle || doorR.outHandle) // either one of these is true, the door is open
		{
			doorR.bState = "OPENED";
		}
		else
		{
			doorR.bState = "CLOSED";
		} 

	}

	std::cout << "Right door is "<< doorR.bState << " and left door is " << doorL.bState << endl;

}

void problem2() // problem 2 (simulation of crop temperature alarm circuit)
{
	const int INITIAL_R(33192);
	const double INITIAL_T_KELVIN(313); // initial T is 30+273 kelvin
	const double TEMPERATURE_CONSTANT(3310); //in kelvin
	const int R1(156300);
	const int R2(156300);
	const int R3(156300);
	const int R4(156300);

	double dTempKel(0), dTempF(0);
	
	cout << "\n\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\PROBLEM 2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n";


	cout << "This program simulates crop temperature alarm circuit\n\n";


	while (1)
	{	
		cout << "Enter Temperature (Farenheit)	:	";
		cin >> dTempF; //prompt for input

		

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}	
		else if (dTempF <= -459.67) // So that 1/T does not divide by zero
		{
			cout << "Temperature needs to be more than absolute zero!! :(" <<endl;
			continue;
		}

		cout << "\nEntered Temperature is "<< dTempF << " F"<< endl;

		break;
	}

	
	dTempKel= (dTempF + 459.67)*static_cast<double>(5)/9; // convert input (farenheit to kelvin) 

	double dRThermister = INITIAL_R*exp(TEMPERATURE_CONSTANT*((1/dTempKel)-(1/INITIAL_T_KELVIN)));

	if (static_cast<double>(R2)/(dRThermister+R2)<static_cast<double>(R4)/(R3+R4)) //cast to perform decimal divisions
	{
		cout << "\nALARM RANG!! PREPARE FOR BATTLE!!!\n" <<endl;
	}
	else
	{
		cout << "\nALARM DIDNT RANG!! EVERYTHING\'S FINE!!\n"<< endl;
	}

}

//Entry point of program
int main()
{
	problem1();
	problem2();


	system("Pause");
	return 0;
}