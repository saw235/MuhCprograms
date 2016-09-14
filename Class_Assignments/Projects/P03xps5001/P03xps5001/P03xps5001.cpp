/*
Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 20thh 2014
Assignment:	 P03

This program generates a light intensity field for a basketball court given initial data

People whom I assisted: Zack, Mac, Luke, etc..

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream> 
#include <cmath> //for pow() abs()
#include <fstream> //io of files
#include <cstdlib> //for rand() srand()
#include <iomanip> //for setprecision() setw() 
#include <ctime> //for time(0)

using namespace std;

const int NMAXLIGHT = 3; //maximum number of floodlights
const int SIZE_LENGTH = 94; //length of basketball court
const int SIZE_WIDTH = 50; //width of basketball court

//Fucntion Name: PrintField
//This function prints the light intensity field of a 94/50 sized basketball court
//Arguments passed: results <----array of light intensity
//					row  (94)
//					column (50)
//					outputfile <--- file object to be written to 
//Returns none
void PrintField(double results[][SIZE_WIDTH], int row, int column, ofstream& outputfile)
{
	//output the top labelling 1 to 50
	outputfile << setw(5) << " " ;
	for (int iii = 0; iii < column; iii++)
	{
		outputfile <<"|"<< setw(3) << iii+1 << " |"; 

	}

	outputfile << endl;
	
	//output a line
	for (int iii = 0; iii < column; iii++)
	{
		if (iii == 0)
		{
			//no lines if its the first column because values starts at 2nd column
			outputfile << setw(5) << " ";
		}
		else
		{
			outputfile << "------";
		}
	}

	outputfile <<endl;
	//-------------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------//

	
	for (int iii = 0; iii < row; iii++)
	{
		//outputs the labelling on the left
		outputfile << setw(4) << iii+1 << "|";
		
		for (int jjj = 0; jjj < column; jjj++)
		{
			//output the light intensity values with 2 decimal places
			outputfile << fixed << setw(5) << setprecision(2) << results[iii][jjj] <<" ";
		}

		outputfile << endl;
	}


	outputfile << endl << endl;
	return;
}

//Fucntion Name: LightIntensity
//This function calculates the light intensity of a spot given 
//		the distance between the spot and the source of light
//Arguments passed: dPower <--- power rating of light source
//					dDistance <--- distance between light source and spot
//Returns dPower/dDistance^2
double LightIntensity(double dPower, double dDistance)
{
	return dPower/(pow(dDistance,2));
}

//Fucntion Name: Rand_Int
//This function generates random number between range (min,max)
//Arguments passed: min
//					max
//Return (rand()%(max-min+1) + min)  
int Rand_Int(int min, int max)
{
	return (rand()%(max-min+1) + min);
}

//Fucntion Name: Distance_to_Floor
//This function calculates the y-plane distance from light source to the square
//Arguments passed: h_Distance <----horizontal distance
//					v_Distance <----height
//Return sqrt(pow(v_Distance,2)+pow(h_Distance,2))  <---- Pythagorean theorem
double Distance_to_Floor(double h_Distance, double v_Distance)
{
	return sqrt(pow(v_Distance,2)+pow(h_Distance,2));
}

//Fucntion Name: HorizontalDistance
//This function calculates the horizontal distance from light source to the square
//Arguments passed: x <----delta x in top down view
//					y <----delta y in top down view
//Return sqrt(pow(x,2)+pow(y,2))  <---- Pythagorean theorem
double HorizontalDistance(double x, double y)
{
	return sqrt(pow(x,2)+pow(y,2));
}

//Fucntion Name: ClearIntensityField
//This function resets the intensity array to 0s
//Arguments passed: A <--- intensity array

//Return None
void ClearIntensityField(double A[][SIZE_WIDTH])
{
	//loops through all values in A
	for (int iii = 0; iii < SIZE_LENGTH; iii++)
	{
		for (int jjj = 0; jjj <SIZE_WIDTH; jjj++)
		{
			//and set value to 0
			A[iii][jjj] = 0;
		}
	}
	return;
}

/* FUNCTION NOT USED!!!
void MatrixSum(double A[][SIZE_WIDTH], double B[][SIZE_WIDTH], double C[][SIZE_WIDTH])
{
	for (int iii = 0; iii < SIZE_LENGTH; iii++)
	{
		for (int jjj = 0; jjj < SIZE_WIDTH; jjj++)
		{
			C[iii][jjj] = A[iii][jjj] + B[iii][jjj];
		}
	}

	return;
}*/

int main()
{
	using namespace std;
	srand(time(0)); //seed RNG
	/*----------------------------------------------------------------------------------*/
	// Read-in variables
	/*----------------------------------------------------------------------------------*/

	char option('A'); //option name
	int nFloodlight = 0; //number of floodlights
	int light_position_x[NMAXLIGHT] = {0}; //position x of floodlight (x is in the direction of 94)
	int light_position_y[NMAXLIGHT] = {0}; //position y of floodlight (y is in the direction of 50)
	

	char rand_or_given = 'R'; // R for random , G for given (R by default, anything else regarded as R)

	double dPower = 0; //power rating of lights
	double dHeight = 0; //distance the lights are mounted above the positions (ft) 

	/*----------------------------------------------------------------------------------*/
	// Calculated variables
	/*----------------------------------------------------------------------------------*/

	double delta_x(0); //difference between the x position of floodlight and 
					   //   the square evaluated in direction of 94 
	double delta_y(0); //difference between the y position of floodlight and 
					   //   the square evaluated in direction of 50 

	double h_distance(0); // the distance between the light and square in top down view
	double v_distance(0); // the distance between the light and the square in 3D
	double intensity_matrix[SIZE_LENGTH][SIZE_WIDTH] = {0}; // arrays to store each square's light intensity

	/*----------------------------------------------------------------------------------*/
	// Fstream Stuff
	/*----------------------------------------------------------------------------------*/
	
	//open input and output files
	ifstream lightdata("P:\\Private\\lights.txt");
	ofstream lightresults("P:\\Private\\lightoption.txt");

	//check files
	if (lightdata.fail())
	{
		cout << "Failed to open data file! Exiting..." <<endl;

		system("Pause");
		return 0;
	}
	else
	{
		cout << "Data file opened successfully! Generating all options..." <<endl;
	}

	if (lightresults.fail())
	{
		cout << "Failed to generate results! Exiting..." <<endl;

		system("Pause");
		return 0;
	}
	/*----------------------------------------------------------------------------------*/
	// Loop to read files
	/*----------------------------------------------------------------------------------*/
	lightdata >> option >> nFloodlight >> rand_or_given;
		
		//if data is given
		if (rand_or_given == 'G')
		{
			
			for (int iii = 0; iii < nFloodlight; iii++)
			{
				//create 2 floating points dummy variables and read in light data
				double dummy_x;
				double dummy_y;

				lightdata >> dummy_y >> dummy_x;

				//convert values to integer then assign it to lightposition xy
				light_position_x[iii] = floor(dummy_x);
				light_position_y[iii] = floor(dummy_y);
			}
			
		}

		//else generates random integer between 1-94 and 1-50 and assign to lightposition xy
		else
		{
			for (int iii = 0; iii <nFloodlight; iii++)
			{
				light_position_x[iii] = Rand_Int(1,SIZE_LENGTH);
				light_position_y[iii] = Rand_Int(1,SIZE_WIDTH);
			}
		}

		lightdata >> dPower >> dHeight;

	//while not end of file
	while(!lightdata.eof())
	{

		//loops through whole matrix
		for (int iii = 1; iii <= SIZE_LENGTH; iii++)
		{
			for (int jjj = 1; jjj <= SIZE_WIDTH; jjj++)
			{
				//loops through the number of floodlight and superposition each individual intensity on the square
				for (int kkk = 0; kkk <nFloodlight; kkk++)
				{
					//*abs() to get the absolute values
					//difference between horizontal values and vertical values as in cartesian plane of graphs
					delta_x = abs(light_position_x[kkk] - (iii));
					delta_y = abs(light_position_y[kkk] - (jjj));

					//see functions documentation above
					//h_distance is used for the calculations for v_distance
					h_distance = HorizontalDistance(delta_x, delta_y);
					v_distance = Distance_to_Floor(h_distance, dHeight);

					//calls LightIntensity() and superposition the values to intensitymatrix  
					intensity_matrix[iii-1][jjj-1] += LightIntensity(dPower, v_distance);
				}
			}
		}

		//echo read in data
		lightresults << "Option : " << option << endl;
		lightresults << "No. of floodLights : " << nFloodlight << endl;
		lightresults << "Given/Random : " << rand_or_given << endl;
		
		//echo the position of floodlights
		for (int iii = 0; iii < nFloodlight; iii++)
		{
			lightresults << light_position_x[iii] <<" " << light_position_y[iii] <<endl;
		}

		lightresults << "Power : " << dPower <<endl;
		lightresults << "Height : " << dHeight <<endl;


		
		//calls PrintField() to output results
		PrintField(intensity_matrix,SIZE_LENGTH,SIZE_WIDTH, lightresults);

		//clears the matrix after outputing results
		ClearIntensityField(intensity_matrix);

		//reads in data again
		lightdata >> option >> nFloodlight >> rand_or_given;
		
		if (rand_or_given == 'G')
		{
			
			for (int iii = 0; iii < nFloodlight; iii++)
			{
				double dummy_x;
				double dummy_y;

				lightdata >> dummy_y >> dummy_x;

				light_position_x[iii] = floor(dummy_x);
				light_position_y[iii] = floor(dummy_y);
			}
			
		}

		else
		{
			for (int iii = 0; iii <nFloodlight; iii++)
			{
				light_position_x[iii] = Rand_Int(1,SIZE_LENGTH);
				light_position_y[iii] = Rand_Int(1,SIZE_WIDTH);
			}
		}

		lightdata >> dPower >> dHeight;
		
	}

	//close both files
	lightdata.close();
	lightresults.close();

	system("Pause");
	return 0; 
}