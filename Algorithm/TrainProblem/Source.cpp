#include <stack>
#include <deque>
#include <fstream>
#include <iostream>

using namespace std;

void print_stack(stack<int> stackcpy)
{
	cout << "Stack is now: [ " ;
	while(!stackcpy.empty())
	{
		cout << stackcpy.top() << " ";
		stackcpy.pop();
	}

	cout << "]" << endl;

	return;
}

void main()
{
	ifstream ifile("lab1in.txt");
	ofstream ofile("lab1out.txt");

	if (!ifile.is_open())
	{
		cerr << "Unable to open file ! " << endl;
		return; 
	}

	
	int num= 0;
	int buffer = 1;
	
	while (!ifile.eof())
	{
		ifile >> num;
		if (num == 0)
		{
			break;
		}
		while (num > 0)
	{
		
		

		deque<int> dq1; // queue to store input
		stack<int> s2; // stack to store the ordered trains
		
		for (int i = 0; i < num; i++)
		{
			ifile >> buffer;
			if (buffer == 0)
			{
				ofile << endl;
				break;
			}
			dq1.push_front(buffer);
		}
		 
		if (buffer == 0)
		{
			break;
		}
		
	

		//calculate stack
		int j = 1; //use to count the ordered train
		s2.push(j);
		while (!dq1.empty())
	{
		if (dq1.back() == s2.top())
		{
			cout << "Popped "<< dq1.back() << " from i stack "<<endl;
			dq1.pop_back();

			if (dq1.empty())
			{
				ofile << "Yes\n";
				break;
			}

			cout << "Popped "<< s2.top() << " from j stack "<<endl;
			s2.pop();
			print_stack(s2);

			if (s2.empty())
			{
				j++;
				s2.push(j);
					cout << "Pushe	d "<< j << " into j stack "<<endl;
					print_stack(s2);

			}
			continue;
		}
		else
		{

			if (s2.top() > num)
			{
				ofile << "No\n";

				break;
			}

			j++;
		}
		s2.push(j);
		//cout << "Pushed "<< j << " into j stack "<<endl;
		//print_stack(s2);


	}//end of calculation block
	}
	

}


	ifile.close();
	ofile.close();
	std::system("pause");


}

