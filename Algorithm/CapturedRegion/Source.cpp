#include <fstream>
#include <iostream>

//Author: Saw Xue Zheng
//Program Description : Captions regions of a board that are surrounded by X's


void O_traverse(char** board, int i, int j, int length);
void printBoard(char** board, int length);
using namespace std;
void main()
{
	ifstream infile;
	infile.open("input.txt");

	int length = 0;

	infile >> length;

	cout << length <<endl;

	char** board = new char*[length];
	for(int i = 0; i < length; ++i)
		board[i] = new char[length];

	//get board from input.txt

	for(int i = 0; i <  length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			infile >> board[i][j];
		}
	}

	
	printBoard(board,length);

	//search the border for 'O's and perform DFS on them. Skip if already marked
	//a border is define as the rim of the board so would be [0][x], [x][0], [length-1][x], [x][length-1]

	//search top border
	for (int i = 0; i < length; i++)
	{
		if (board[0][i] == 'O')
		{
			board[0][i] = '#';
			O_traverse(board, 0,i,length);
		}
	}
	
	//search bot border
	for (int i = 0; i < length; i++)
	{
		if (board[length-1][i] == 'O')
		{
			board[length-1][i] = '#';
			O_traverse(board, length-1,i,length);
		}
	}
	
	//search left border
	for (int i = 0; i < length; i++)
	{
		if (board[i][0] == 'O')
		{
			board[i][0] = '#';
			O_traverse(board, i,0,length);
		}
	}

	//search right border

	for (int i = 0; i < length; i++)
	{
		if (board[i][length-1] == 'O')
		{
			board[i][length-1] = '#';
			O_traverse(board, i,length-1,length);
		}
	}

	cout << "AFTER SEARCHING BORDERS" << endl;

	printBoard(board,length);

	//now that we know the ones we dont need to flip
	//process board
	for (int i = 0; i < length ; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (board[i][j] == 'O')
			{
				board[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < length ; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (board[i][j] == '#')
			{
				board[i][j] = 'O';
			}
		}
	}

	cout << "AFTER CAPTURING O's" << endl;
	printBoard(board,length);

	system("PAUSE");

}


//print board
void printBoard(char** board, int length)
{
	for(int i = 0; i <  length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
//dfs
void O_traverse(char** board, int i, int j, int length)
{
	//check all the neighbours of the current position
	//there is only 4 posible choice for the board up down left and right

	//down
	if (i+1 < length)
	{
		if (board[i+1][j] == 'O')
			{
				board[i+1][j] = '#';
				O_traverse(board,i+1,j, length);
			}	
	}

	//up
	if (i-1 > 0)
		{
		if (board[i-1][j] == 'O')
			{
				board[i-1][j] = '#';
				O_traverse(board,i-1,j, length);
			}	
	}

	//left
	if (j-1 > 0)
		{
		if (board[i][j-1] == 'O')
			{
				board[i][j-1] = '#';
				O_traverse(board,i,j-1, length);
			}	
	}

	//right
	if (j+1 < length)
		{
		if (board[i][j+1] == 'O')
			{
				board[i][j+1] = '#';
				O_traverse(board,i,j+1, length);
			}	
	}
	


}