#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
int maxhorizontal(std::vector<std::vector<int>> &grid, int row, int column, int term)
{  
	
	
	/*struct points
	{
	int product;
	std::unique_ptr<int[]> rows(new int[term]);

	
	};
	*/  // stuff i want to add later

	int maxproduct=1;


	for (int i = 1; i <= row; i++)
	{
		
		for (int j = 1; j <= (column - term); j++)
		{
			
			for (int k = 0, product = 1; k < term; k++)
			{
				product *= grid[i-1][j-1+k];
				if (product > maxproduct)
				{
					maxproduct= product;
				}
			}
			
		}
	
		
	}

	return maxproduct;
}

int maxvertical(std::vector<std::vector<int>> &grid, int row, int column, int term)
{
	int maxproduct = 1 ;
	for (int j = 1; j <= column; j++)
	{
		
		for (int i = 1; i <= (row - term); i++)
		{
			
			for (int k = 0,  product = 1; k < term; k++)
			{
				product *= grid[i-1+k][j-1];
				if (product > maxproduct)
				{
					maxproduct= product;
				}
			}
			
		}
	
		
	}
	return maxproduct;
}

int maxnotvertical(std::vector<std::vector<int>> &grid, int row, int column, int term)
{
	int maxproduct = 1;

	for (int i = 1; i <= row - term; i++)
	{
		
		for (int j = 1; j <= (column - term); j++)
		{
			
			for (int k = 0,  product = 1; k < term; k++)
			{
				product *= grid[i-1+k][j-1+k];
				if (product > maxproduct)
				{
					maxproduct= product;
				}
			}
			
		}
	}
	for (int i = 20; i >= term; i--)
	{
		
		for (int j = 1; j <= column - term; j++)
		{
			
			for (int k = 0,  product = 1; k < term; k++)
			{
				product *= grid[i-1-k][j-1+k];
				if (product > maxproduct)
				{
					maxproduct= product;
				}
			}
			
		}
	}

	return maxproduct;
}

int main()
{
	using namespace std;

	fstream file("numbergrid.txt", ios::in);

	vector<vector <int>> grid(20, vector<int>(20));
	if (file.is_open())
	{
		cout << "Open successful!" << endl;
	}
	else
	{
		cout << " Error: Can't find file!" << endl;
	}

	int b=0;
	while (file.good())
	{
		static int rowcount = 1;
		static int columncount = 1;
		static int charactercount = 0;

		if (file.peek() == '\n')
			{
				
			
				file.seekg(2, ios::cur);
				
				rowcount++;

				if (columncount == 20)
				{
					columncount = 1;
				}
		    }
		if (file.peek() == ' ')
			{
		
				file.seekg(1, ios::cur);
				
				
				columncount++;
				
			}
				
		static stringstream convert;
		convert.put(file.get());
		b= file.tellg();
		charactercount++;
		
		int number = 0;
		if (charactercount == 2)
			{
				convert >> number;
				grid[rowcount-1][columncount-1] = number;	
				charactercount = 0;
				convert.clear();
			}
	}

	for ( int iii = 1; iii <= 20; iii++)
	{
		for ( int jjj = 1; jjj <= 20; jjj++)
		{
			if (grid[iii-1][jjj-1] <10)
			{
			cout << '0' << grid[iii-1][jjj-1] << ' ';
			}
			else
			{
			cout <<  grid[iii-1][jjj-1] << ' ';
			}

			if (jjj%20 == 0)
			{
				cout << endl;
			}

		}
	}

	
	int a = max(maxhorizontal(grid, 20, 20, 4), maxvertical(grid,20,20, 4));
	int maxproduct = max(a, maxnotvertical(grid, 20 , 20, 4));

	cout << maxproduct << endl;
	
	system("Pause");
}