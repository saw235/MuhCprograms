#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	std::ifstream data("data.txt");
	if (data.fail())
	{
		cout << "Cannot open file!\n\n";
		system("pause");
		return 0;
	}

	int event_task_nday [3] = {0, 0 ,0}; 
	int event_task_nday_compared [3] = {0 ,0 ,0};
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