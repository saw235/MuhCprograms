/*

Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		March 18th 2014
Assignment:	 L07

This program suck in data and spit out data only with digits, space + and minus sign.

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
#include <cctype> //for isdigit isspace

using namespace std; 
int main()
{
   ifstream indata("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\L07xps5001\\data.txt"); //input data
   ofstream outdata("P:\\Private\\Documents\\Visual Studio 2012\\Projects\\L07xps5001\\fasdfghjiltereddata.txt"); // output data object

   //checks
   if (indata.fail())
   {
	   cout << "Failed to open file!"<<endl;
	   system("Pause");
	   return 0;
   }

   if (outdata.fail())
   {
	   cout << "Unable to create file!"<<endl;
	   system("Pause");
	   return 0;
   }
   /////////////////////////////


   char filter('0'); //char variable to read in 
   int filtercount(0); // for number for filtered character

   filter = indata.get(); //read characters
   while (!indata.eof()) //loops to filter
   {
	   

	   if (!isspace(filter) && !isdigit(filter) && filter != '+' && filter != '-') //if its not space digit + -
	   {
		   cout.put(filter); //put it on console
		   filtercount++; //add counts

	   }
	   else 
	   {
		   outdata.put(filter); //output it onto a file
	   }
	   
	   filter = indata.get(); //read characters
   }

   cout << "\n\nNumber of filtered input is	:" <<filtercount <<endl; //display counts of filter
   
   //close file
   indata.close();
   outdata.close();

   system("Pause");
   return 0;



}