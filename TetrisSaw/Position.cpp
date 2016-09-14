#include "Position.h"


Position Position::GetPosition() const {return Position(m_posx,m_posy);}

Position& Position::SetPosition(int posx, int posy) 
		{
			m_posx = posx;
			m_posy = posy;

			return *this;
		}




Position& Position::Move(direction edirection)
		{
			switch (edirection)
			{		
				case (down):
					
						m_posy -= 1;
						return *this;
					
				case (left):
					
						m_posy -= 1;
						return *this;
					
				case (right):
					
						m_posy += 1;
						return *this;
					
			}
		}



Position Position::GetAdjacent(direction edirection)
{
			switch (edirection)
			{
				case (up):
						
						return Position(m_posx, m_posy - 1);
					
				case (down):
					
						return Position(m_posx, m_posy + 1);
					
				case (left):
					
						return Position(m_posx -1, m_posy);
					
				case (right):
					
						return Position(m_posx +1, m_posy);
					
			}
}

bool Position::operator==(const Position& pos2)
{
	if ((m_posx == pos2.m_posx) && (m_posy == pos2.m_posy))
	{
		return true;
	}

	else
	{
		return false;
	}

}