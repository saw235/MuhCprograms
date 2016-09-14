#include <iostream>
#include "math.h"


void main()
{
	using namespace std;
	double dArea(0), dDegree(0), dRadius(0), dRadian(0); // declare and initialize
	const double PI = 3.14159;

	cout << "This program calculates the area of the sector of a circle. \n" << endl;
	cout << "Please enter the following:	\n" << endl;

	while (1)
	{
			cout << "Radius, R				:";
			cin >> dRadius; 

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout <<"\nPlease enter a valid number."<<endl;
				continue;
			}
			
			if (dRadius < 0 ) 
			{
				cout << "\nPlease enter a positive number."<< endl;
				continue;
			}

			break; 

			
	}		

	
	while (1)
	{

			cout << "Angle in degree, d			:";
			cin >> dDegree;	
			
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout <<"\nPlease enter a valid number."<<endl;
				continue;
			}

			
			if (dDegree < 0) 
			{
				cout << "\nPlease enter a positive number."<< endl;
				continue;
			}
			
			break; 
			
	}	

		dRadian = PI*dDegree/180;

		dArea = 0.5*((dRadius)*dRadius)*dRadian;

	cout << "\nArea is "<< dArea << endl;

	system("Pause");

}

