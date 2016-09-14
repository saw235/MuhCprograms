#pragma once

enum direction
{
	no_move,
	up,
	down,
	left,
	right
};

class Position
{
	private:
	
		int m_posx;
		int m_posy; 

	
	public:

		Position(int posx = 0, int posy = 0): m_posx(posx), m_posy(posy)
		{
		}

	

		Position GetPosition() const;
		Position& SetPosition(int posx, int posy) ;
		


		Position& Move(direction edirection);


		int GetXPosition() const { return m_posx;}
		int GetYPosition() const { return m_posy;}
		int& SetXPosition() {return m_posx;}
		int& SetYPosition() {return m_posy;}
		Position GetAdjacent(direction edirection);

		bool operator==(const Position& pos2);
		
		
};


