/*
Name:		Saw Xue Zheng
Class:		CMPSC 201
Section:	2
Date:		April 20thh 2014
Assignment:	 P02

This program calculates the maximum and minimum heat flow for a pipe given initial data

Copyright (c)	Saw Xue Zheng

	Academic Integrity Statement: I certify that, while others may have assisted me in brain storming,
	debugging and validating this program, the program itself is my own work. I understand that submitting
	code which is the work of other individuals is a violation of the course Academic Integrity Policy and may
	result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
	I also understand that if i knowingly give my original work to another individual that it could also result
	in a zero credit for the assignment, or course failure and a report to the Acedemic Dishonesty Board.
*/

#include <iostream> //for input output
#include <fstream> // to deal with files
#include "math.h" // for abs()  <--- returns absolute value of
#include <string> // to deal with strings
#include <iomanip> // manipulates input output



//Fucntion Name: centi_to_meter
//This function converts centimeters to meters
//Arguments passed: input 
//Returns input/100
double centi_to_meter(double input)
{
	return input/100;
}

//Fucntion Name: MaterialHeatTransfer
//This function calculates the heat transfer from the inner surface of the pipe to the outer surface 
//Arguments passed: inner_radius, outer_radius, CONDUCTIVITY_CONSTANT
//Returns (log(outer_radius/inner_radius))/(2*PI*CONDUCTIVITY_CONSTANT)
//NOTE!!* RADIUS HAS TO BE IN METERS
double MaterialHeatTransfer(double inner_radius, double outer_radius, const double CONDUCTIVITY_CONSTANT)
{
	const double PI = 3.14159;
	return (log(outer_radius/inner_radius))/(2*PI*CONDUCTIVITY_CONSTANT);
}

//Fucntion Name: AirHeatTransfer
//This function calculates the heat transfer from the outer surface of the pipe to the surrounding surface 
//Arguments passed: outer_radius, HEAT_TRANSFER_COEFFICIENT
//Returns 1/(2*PI*outer_radius*HEAT_TRANSFER_COEFFICIENT)
//NOTE!!* RADIUS HAS TO BE IN METERS
double AirHeatTransfer(double outer_radius, const double HEAT_TRANSFER_COEFFICIENT)
{
	const double PI = 3.14159;
	return 1/(2*PI*outer_radius*HEAT_TRANSFER_COEFFICIENT);
}

//Fucntion Name: TotalHeatTransfer
//This function calculates the total heat transfer
//Arguments passed: r1, r2
//Returns r1+r2
double TotalHeatTransfer(double r1, double r2)
{
	return r1+r2;
}

//Fucntion Name: TotalHeatFlow
//This function calculates the total heat flow given total heattransfer and the temperature datas 
//Arguments passed: inner_temp, outer_temp, totalheattransfer
//Returns (inner_temp - outer_temp)/totalheattransfer
//NOTE!!* TEMP HAS TO BE IN KELVIN
double TotalHeatFlow(double inner_temp, double outer_temp, double totalheattransfer)
{
	return (inner_temp - outer_temp)/totalheattransfer;
}


//Fucntion Name: SurfaceTemp
//This function calculates the surface temperature of the pipe 
//Arguments passed: inner_temp, totalheatflow, materialheattransfer
//Returns (inner_temp - totalheatflow*materialheattransfer
//NOTE!!* TEMP HAS TO BE IN KELVIN
double SurfaceTemp(double inner_temp, double totalheatflow, double materialheattransfer)
{
	return (inner_temp - totalheatflow*materialheattransfer);
}

//Fucntion Name: Float_IsEqual
//This function compares floating point number
//Arguments passed: n1, n2
//Returns fabs(n1 - n2) <= dEpsilon * fabs(n1)
bool Float_IsEqual(double n1, double n2)
{
	const double dEpsilon = 0.0000001; //percentage difference allowed
	return fabs(n1 - n2) <= dEpsilon * fabs(n1); //return true if the difference between n1 and n2 is less than 0.00001% of n1
}

//Fucntion Name: Celcius_To_Kelvin
//This function convert celcius to kelvin
//Arguments passed: cel_temp <----- temperature in celcius
//Returns cel_temp + 273.15
double Celcius_To_Kelvin(double cel_temp)
{
	return cel_temp + 273.15; 
}

//Fucntion Name: Celcius_To_Kelvin
//This function convert Kelvin to Celcius
//Arguments passed: kel_temp <----- temperature in Kelvin
//Returns cel_temp - 273.15
double Kelvin_To_Celcius(double kel_temp)
{
	return kel_temp - 273.15;
}


int main()
{
	using namespace std;

	//open output and input files
	ifstream data("P:\\Private\\P2 Heat Transfer Data.txt");
	ofstream results("P:\\Private\\P2 Heat Results.txt");

	//error message and exit if fail to open 
	if (data.fail())
	{
		cout << "Failed to open file. Exiting... "<<endl;
		system("Pause");
		return 0;
	}

	if (results.fail())
	{
		cout << "Failed to create output file. Exiting... "<<endl;
		system("Pause");
		return 0;
	}

	/*----------------------------------------------------------------------------------------------*/
	//read-in data variables
	string materialtype; //Type of materials
	double heat_transfer_coefficient(0); //Heat Transfer Coefficient
	double conductivity_coefficient(0); //Conducitvity Coefficient
	double inner_radius(0); // in cm   (Radius to the inner surface of pipe)
	double outer_radius_max(0); // in cm (Upper limit of radius to outer surface of pipe)
	double outer_radius_min(0);// in cm (Lower limit of radius to outer surface of pipe)
	double increment(0); // Increment of radius
	double inner_temp(0); // celcius (Temperature inside pipe)
	double outer_temp(0); // celcius (Temperature outside pipe)

	/* ------------------------------------------------------------------------------------------------*/
	//reads data
	data >> materialtype >> heat_transfer_coefficient >> conductivity_coefficient >> inner_radius 
		>> inner_temp >> outer_temp >> outer_radius_min >> outer_radius_max >> increment;
	/*------------------------------------------------------------------------------------------------*/
	// variables for calculations and stuff

	double inner_outer_heattransfer(0); // Heat transfer from inside pipe to surface of pipe
	double air_heat_transfer(0); //Heat transfer due to radiation to air
	double totalhealflow(0); // Total Heat Flow
	double surface_temp(0); //in Kelvin
	double max_heat_flow(0); // Maximum heat flow
	double min_heat_flow(0); // Minimum heat flow
	double max_heat_radius(0); // Outer radius when maximum heat flow occurs
	double min_heat_radius(0); // Outer radius when minimum heat flow occurs
	

	//end of file loop
	while(!data.eof())
	{
		
		results << fixed << setprecision(2); //set to decimal notation and set precision to 2 for output file

		//echos read in data
		results << "Material Type					:" << materialtype << endl;
		results << "Heat Transfer Coefficient, h			:" << heat_transfer_coefficient << " W/m^2 K"<<endl;
		results << "Conductivity of the insulation, k		:"<< conductivity_coefficient << " W/m K" <<endl;
		results << "Inner radius of pipe, r(i)			:" << setprecision(4) << inner_radius << " cm" <<endl;
		results << "Temperature inside pipe, T(i)			:" << inner_temp << " Celcius" <<endl;
		results << "Surrounding temperaturem, T(air)		:" << outer_temp << " Celcius" <<endl;
		results << "Upper limit of radius, r(u)			:" << setprecision(4) << outer_radius_max << " cm" << endl;
		results << "Lower limit of radius, r(l)			:" << setprecision(4) << outer_radius_min << " cm" << endl;
		results << "Increment					:" << setprecision(4) << increment << " cm" <<endl;

		results <<endl;

		//echos calculation in chart format using loop
		results << "Outer Radius, R(o)  Inner_To_Outer_HeatTransfer,R1  Heat_Transfer_To_Air,R2  Total Heat Flow, q(t)  Surface Temp, T(o) "
			<<endl;

	
		//loops when current radius is LESS THAN OR EQUAL to the outer_radius_max
		//FLOAT_IsEqual() is used to compare 2 floating point values
		//Increase by increment every loop
		for(double outer_radius = outer_radius_min; 
			((outer_radius < outer_radius_max) || (Float_IsEqual(outer_radius, outer_radius_max))); outer_radius += increment)
		{
			
			//calculates values *refer to functions above and assign them to each variables
			//conversion to kelvin and meters are used to ensure that formulas worked correctly
			inner_outer_heattransfer = MaterialHeatTransfer(centi_to_meter(inner_radius), centi_to_meter(outer_radius), conductivity_coefficient);
			air_heat_transfer = AirHeatTransfer(centi_to_meter(outer_radius), heat_transfer_coefficient);

			totalhealflow = TotalHeatFlow(Celcius_To_Kelvin(inner_temp), Celcius_To_Kelvin(outer_temp), TotalHeatTransfer(inner_outer_heattransfer,air_heat_transfer));

			surface_temp = SurfaceTemp(Celcius_To_Kelvin(inner_temp), totalhealflow, inner_outer_heattransfer);

			//set min max values to initial heatflow and initial radius if it is going through the first loop 
			if (outer_radius == outer_radius_min)
			{
				max_heat_flow = totalhealflow;
				min_heat_flow = totalhealflow;
				max_heat_radius = outer_radius;
				min_heat_radius = outer_radius;
			}

			//set current radius and current heatflow to maxheatflow and maxheatradius if maxheatflow is less than the current heatflow
			if (max_heat_flow < totalhealflow)
			{
				max_heat_flow = totalhealflow;
				max_heat_radius = outer_radius;
			}
			
			//set current radius and current heatflow to minheatflow and minheatradius if minheatflow is more than the current heatflow
			if (min_heat_flow > totalhealflow)
			{
				min_heat_flow = totalhealflow;
				min_heat_radius = outer_radius;
			}

			//output calculations to "results"  (Kelvin to celcius is used for surfacetemp because it only accepts kelvin)
			results << setw(10) << fixed << setprecision(1) << outer_radius <<" cm"
				<<setw(28) <<setprecision(4) << inner_outer_heattransfer << " J"
				<< setw(23) << setprecision(4) << air_heat_transfer << " J"
				<< setw(21) <<setprecision(2) <<totalhealflow<<" W"
				<<setw(19)<< Kelvin_To_Celcius(surface_temp)<<" C"<<endl;
		}

		// output max and min to "results"
		results << fixed;

		results << "Maximum_Flow_Of_Heat(W)	Radius_To_Outside_Pipe(cm)"<<endl; 
		results <<setw(22)<< setprecision(2)<< max_heat_flow << setw(9) << setprecision(1) << max_heat_radius <<endl; 

		results << "Minimum_Flow_Of_Heat(W)	Radius_To_Outside_Pipe(cm)"<<endl; 
		results <<setw(22)<< setprecision(2)<< min_heat_flow << setw(9)<< setprecision(1) << min_heat_radius <<endl; 

		results<< endl<< endl;

		//reads data
		data >> materialtype >> heat_transfer_coefficient >> conductivity_coefficient >> inner_radius 
		>> inner_temp >> outer_temp >> outer_radius_min >> outer_radius_max >> increment;
	}


	cout << "Results has been generated successfully!" <<endl;

	//close both files
	data.close();
	results.close();

	system("Pause");

	return 0;
}
