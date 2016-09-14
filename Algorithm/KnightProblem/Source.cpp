#include <fstream>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct DVector
{
	int i;
	int j;

	DVector(int x, int y):i(x),j(y){
	}
};

struct Pos
	{
		int row;
		int col;

		Pos(int x =0, int y=0):col(x),row(y){
	}
		
	};

Pos ChessPos2Cord(char* string);

void main()
{
	
	ifstream inputfile;
	inputfile.open("input.txt");
	char inipos[10];
	char finpos[10];
	

	while(!inputfile.eof())
	{
		inputfile >> inipos;
		inputfile >> finpos;
		Pos initial_pos = ChessPos2Cord(inipos);
	Pos final_pos = ChessPos2Cord(finpos);

	
	const int BOARD_SIZE = 8;

	//define the direction vectors
	list<DVector> DV;
	DV.push_back(DVector(1,2));
	DV.push_back(DVector(1,-2));
	DV.push_back(DVector(-1,2));
	DV.push_back(DVector(-1,-2));
	DV.push_back(DVector(2,1));
	DV.push_back(DVector(2,-1));
	DV.push_back(DVector(-2,1));
	DV.push_back(DVector(-2,-1));

	
	bool mark[BOARD_SIZE+1][BOARD_SIZE+1] = {false};
	int mv_count[BOARD_SIZE+1][BOARD_SIZE+1];

	for (int i  = 0; i < BOARD_SIZE + 1; i++)
	{
		for (int j = 0 ; j < BOARD_SIZE + 1 ; j++)
		{
			mv_count[i][j] = -1;
		}
	}

	
	//traverse the board using bfs
	queue<Pos> q;
	queue<Pos> path;
	q.push(initial_pos);
	
	bool found = false;
	mark[initial_pos.col][initial_pos.row] = true;
	mv_count[initial_pos.col][initial_pos.row] = 0;
	
	while (!q.empty())
	{
		
		Pos temp = q.front();
		//cout << temp.col << "," << temp.row << endl;
		q.pop();

		if (temp.row == final_pos.row && temp.col == final_pos.col)
		{
			break;
		}
		

		//for each DVector add to current position then check if valid position
		for (DVector v : DV)
		{
			
			if (((v.i + temp.col) > 0) && ((v.i + temp.col) <= BOARD_SIZE))
				{
					if (((v.j + temp.row) > 0) && ((v.j + temp.row) <= BOARD_SIZE))
					{
						//cout << ( temp.col) << "," <<( temp.row) << endl;
						//if valid and not marked
						if (!mark[v.i+temp.col][v.j+temp.row])
						{
							//mark and add to queue
							mv_count[v.i+temp.col][v.j+temp.row] = mv_count[temp.col][temp.row] + 1;
							mark[v.i+temp.col][v.j+temp.row] = true;
							q.push(Pos(v.i+temp.col,v.j+temp.row));
							
						}

					}
			}
		}

	}

	cout << "To get from " << inipos << " to " <<finpos << " takes "<< mv_count[final_pos.col][final_pos.row]  << " knight moves."<<endl;
	
		
	
		
	
	}

	inputfile.close();

	
	
	

	
	system("PAUSE");


}

//covert chessmove to pos
//input: a1, a2, b2 etc.. up to h8
Pos ChessPos2Cord(char* string)
{
	Pos temp;
	switch(string[0])
	{
		case 'a':
			temp.col = 1;
			break;
		case 'b':
			temp.col = 2;
			break;
		case 'c':
			temp.col = 3;
			break;
		case 'd':
			temp.col = 4;
			break;
		case 'e':
			temp.col = 5;
			break;
		case 'f':
			temp.col = 6;
			break;
		case 'g':
			temp.col = 7;
			break;
		case 'h':
			temp.col = 8;
			break;
	}

	temp.row = (int)string[1] -48;
	return temp;
}