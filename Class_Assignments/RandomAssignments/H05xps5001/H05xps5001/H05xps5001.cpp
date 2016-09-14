/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 18th 2014
Assignment:	 HW5

This program takes in a task timetable and prints a project completion timetable.

People whom I assisted: Luke Arron, this other guy

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	std::ifstream data("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\H05xps5001\\data.txt");
	if (data.fail())
	{
		cout << "Cannot open file!\n\n";
		system("pause");
		return 0;
	}

	int event_task_nday [3] = {0, 0 ,0};  // arrays for event task day
	int event_task_nday_compared [3] = {0 ,0 ,0}; // arrays for next event task day in line
	int max_days(0);
	int total_days(0);

	data >> event_task_nday[0] >> event_task_nday[1] >> event_task_nday[2]; //read in initial data
	cout << "Event" << "	|	"<<"Days to complete event"<<endl; 
	cout << "----------------------------------------------"<<endl;

	while (!data.eof()) //loop to end of file
	{
		//read in next line of data and stored it elsewhere
		data >> event_task_nday_compared[0] >> event_task_nday_compared[1] >> event_task_nday_compared[2];
		
		if (event_task_nday_compared[0] != event_task_nday[0]) // if event being read is not the same as previous print the maximum 
		{
			total_days += max_days; //add to total days
			cout << event_task_nday[0] << "	|	"<<max_days<<endl; //output eventno and the max days 
			max_days = event_task_nday_compared[2]; //set max days to the next event being considered
		}
		else if (event_task_nday_compared[2] >= event_task_nday[2]) // else compare ndays for longest day
				{
					max_days = event_task_nday_compared[2]; //set max days to the the biggest one
				}

		for (int iii = 0; iii<3; iii++) // make the previous one the one being compared
		{
		 	event_task_nday[iii] = event_task_nday_compared[iii];
		}
	}
	
	//if data ended before event change 
	total_days += max_days; //add max days to total
	cout << event_task_nday[0] << "	|	"<< max_days<<endl; //prints anyway  

	cout <<"Days needed for project completion	 :	"<< total_days <<endl;

	
	data.close(); //close file
	
	system("pause");
	return 0;
}