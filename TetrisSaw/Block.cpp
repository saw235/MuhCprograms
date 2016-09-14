#include "Block.h"


Block::Block(BLOCTYPE type, Position &blockpos, int seed ):m_type(type), m_internalseed(seed), m_bRotated(no_move), m_bMoved(no_move)
	{
		
		if (m_type == OBLOC)
		{
			//forms agregate of blocks from smaller blocks
			//setting up the position of blocks from a reference point
			SmallerBlock sobloc[4]= {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(right)),
				SmallerBlock(blockpos.GetAdjacent(down)), SmallerBlock((blockpos.GetAdjacent(right)).GetAdjacent(down))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = sobloc[i];
				_4Blocks[i].SetColor() = YELLOW;
			}

			

		}


		 if (m_type == TBLOC)
		{
			//same stuff as above for TBLOCK
			SmallerBlock stbloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(up)),
				SmallerBlock(blockpos.GetAdjacent(left)), SmallerBlock(blockpos.GetAdjacent(right))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = stbloc[i];
				_4Blocks[i].SetColor() = PURPLE;
			}

			
		}

		if (m_type == LBLOC)
		{
			SmallerBlock slbloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(left)),
				SmallerBlock(blockpos.GetAdjacent(right).GetAdjacent(up)), SmallerBlock(blockpos.GetAdjacent(right))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = slbloc[i];
				_4Blocks[i].SetColor() = ORANGE;
			}
			
		}

		if (m_type == JBLOC)
		{
			SmallerBlock sjbloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(left)),
				SmallerBlock(blockpos.GetAdjacent(left).GetAdjacent(up)), SmallerBlock(blockpos.GetAdjacent(right))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = sjbloc[i];
				_4Blocks[i].SetColor() = DARKBLUE;
			}
			
		}

		if (m_type == SBLOC)
		{
			SmallerBlock ssbloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(right)),
				SmallerBlock(blockpos.GetAdjacent(left).GetAdjacent(down)), SmallerBlock(blockpos.GetAdjacent(down))};
			

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = ssbloc[i];
				_4Blocks[i].SetColor() = GREEN;
			}
		}

		if (m_type == ZBLOC)
		{
			SmallerBlock szbloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(left)),
				SmallerBlock(blockpos.GetAdjacent(right).GetAdjacent(down)), SmallerBlock(blockpos.GetAdjacent(down))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = szbloc[i];
				_4Blocks[i].SetColor() = RED;
			}
			
		}

		if (m_type == IBLOC)
		{
			
			SmallerBlock sibloc[4] = {SmallerBlock(blockpos), SmallerBlock(blockpos.GetAdjacent(right)),
				SmallerBlock(blockpos.GetAdjacent(left)), SmallerBlock((blockpos.GetAdjacent(right)).GetAdjacent(right))};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = sibloc[i];
				_4Blocks[i].SetColor() = LIGHTBLUE;
			}
		}

		if (m_type == NOBLOC)
		{
			SmallerBlock sibloc[4] = {SmallerBlock(),SmallerBlock(), SmallerBlock(),SmallerBlock()};

			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i] = sibloc[i];
				_4Blocks[i].SetColor() = NOCOLOR;
			}
		}
	}

	Block::Block(const Block& source) // copy constructor
	{
		m_type = source.m_type;
		m_internalseed = source.m_internalseed;
		m_bMoved = source.m_bMoved;
		m_bRotated = source.m_bRotated;

		for (int i =0; i < 4; i++)
		{
			_4Blocks[i] = source._4Blocks[i];
		}

	}

	Block& Block::operator=(const Block& source) //assignment operator
	{

		if(this == &source)
		{
			return *this;
		}

		m_type = source.m_type;
		m_internalseed = source.m_internalseed;
		m_bMoved = source.m_bMoved;
		m_bRotated = source.m_bRotated;

		for (int i =0; i < 4; i++)
		{
			_4Blocks[i] = source._4Blocks[i];
		}

		return *this;

	}

	SmallerBlock* Block::Get_4Blocks()
	{
		return _4Blocks;
	}

	BLOCTYPE Block::GetBLOCTYPE() {return m_type;}

	void Block::SetBlocPos(const Position& blockpos)
	{
		
			int xdifference = blockpos.GetXPosition() - _4Blocks[0].GetXPosition();
			int ydifference = blockpos.GetYPosition() - _4Blocks[0].GetYPosition() ;

			for (int i = 0; i <4; i++)
			{
			
			_4Blocks[i].SetXPosition() += xdifference;
			_4Blocks[i].SetYPosition() += ydifference;
			
			}

	}
	


	Block& Block::Rotate(direction direction)
	{
		/*int pivotx;
		int pivoty;

		Block temp = *this;

		if (m_type == OBLOC)
		{
			
			return *this;

		}


		 if (m_type == TBLOC)
		{
			
			pivotx = temp._4Blocks[0].GetXPosition();
			pivoty = temp._4Blocks[0].GetYPosition();
			
		}

		if (m_type == LBLOC)
		{
			
			pivotx = temp._4Blocks[3].GetXPosition();
			pivoty = temp._4Blocks[3].GetYPosition();
		}

		if (m_type == JBLOC)
		{
			pivotx = temp._4Blocks[3].GetXPosition();
			pivoty = temp._4Blocks[3].GetYPosition();
			
		}

		if (m_type == SBLOC)
		{
			pivotx = temp._4Blocks[0].GetXPosition();
			pivoty = temp._4Blocks[0].GetYPosition();
		}

		if (m_type == ZBLOC)
		{
			pivotx = temp._4Blocks[0].GetXPosition();
			pivoty = temp._4Blocks[0].GetYPosition();
			
		}

		if (m_type == IBLOC)
		{
			pivotx = temp._4Blocks[0].GetXPosition();
			pivoty = temp._4Blocks[0].GetYPosition();
			
		}

		if (m_type == NOBLOC)
		{
			return temp;
		}

		if (direction == right)
		{
			
				for (int i= 0; i < 4; i++)
			{
				int x = temp._4Blocks[i].GetXPosition();
				int y = temp._4Blocks[i].GetYPosition();
					//   x' = [(X- xpivot)* cos0 - (Y - Ypivot)*sin0] + ypivot
					//   y' = [(X- xpivot)*sin0 + (Y - Ypivot)*cos0] + xpivot
					//   For left, thetha = pi/2 = 90 degrees
					//   *Note that the pivot position has to be subtracted from the pos to translate the position to the origin
					//	  Similarly, the pivot positions are added back to reflect the new position after rotation 
				temp._4Blocks[i].SetXPosition() =  (x - pivotx)* 0 - (y - pivoty)*1 + pivotx;
				temp._4Blocks[i].SetYPosition() =  (x- pivotx)*1 + (y - pivoty)*0 + pivoty;
			}
				*this = temp;

				// chk for wall kicking

				m_bRotated = true;
				return temp;*/

		int pivotx;
		int pivoty;

		if (m_type == OBLOC)
		{
			
			return *this;

		}


		 if (m_type == TBLOC)
		{
			
			pivotx = _4Blocks[0].GetXPosition();
			pivoty = _4Blocks[0].GetYPosition();
			
		}

		if (m_type == LBLOC)
		{
			
			pivotx = _4Blocks[0].GetXPosition();
			pivoty = _4Blocks[0].GetYPosition();
		}

		if (m_type == JBLOC)
		{
			pivotx = _4Blocks[0].GetXPosition();
			pivoty = _4Blocks[0].GetYPosition();
			
		}

		if (m_type == SBLOC)
		{
			pivotx = _4Blocks[3].GetXPosition();
			pivoty = _4Blocks[3].GetYPosition();
		}

		if (m_type == ZBLOC)
		{
			pivotx = _4Blocks[3].GetXPosition();
			pivoty = _4Blocks[3].GetYPosition();
			
		}

		if (m_type == IBLOC)
		{
			pivotx = _4Blocks[1].GetXPosition();
			pivoty = _4Blocks[1].GetYPosition();
			
		}

		if (m_type == NOBLOC)
		{
			return *this;
		}

		if (direction == right)
		{
			
				for (int i= 0; i < 4; i++)
			{
				int x = _4Blocks[i].GetXPosition();
				int y = _4Blocks[i].GetYPosition();
					//   x' = [(X- xpivot)* cos0 - (Y - Ypivot)*sin0] + ypivot
					//   y' = [(X- xpivot)*sin0 + (Y - Ypivot)*cos0] + xpivot
					//   For left, thetha = pi/2 = 90 degrees
					//   *Note that the pivot position has to be subtracted from the pos to translate the position to the origin
					//	  Similarly, the pivot positions are added back to reflect the new position after rotation 
				_4Blocks[i].SetXPosition() =  (x - pivotx)* 0 - (y - pivoty)*1 + pivotx;
				_4Blocks[i].SetYPosition() =  (x- pivotx)*1 + (y - pivoty)*0 + pivoty;
			}
				

				// chk for wall kicking

				m_bRotated = right;
				return *this;

		}

		if (direction == left)
		{
			for (int i= 0; i < 4; i++)
			{
				int x = _4Blocks[i].GetXPosition();
				int y = _4Blocks[i].GetYPosition();
					//   x' = [(X- xpivot)* cos0 - (Y - Ypivot)*sin0] + xpivot
					//   y' = [(X- xpivot)*sin0 + (Y - Ypivot)*cos0] + ypivot
					//Same thing as above with thetha = -pi/2
				_4Blocks[i].SetXPosition() =  (x - pivotx)* 0 - (y - pivoty)*-1 + pivotx;
				_4Blocks[i].SetYPosition() =  (x- pivotx)*-1 + (y - pivoty)*0 + pivoty;
			}


				
				
				m_bRotated = left;
				return *this;
		}

			

	}


	Block& Block::Move(direction direction)
	{
		if (direction == right)
		{
			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i].SetXPosition() = _4Blocks[i].GetXPosition() +1;
				
			}

			m_bMoved = right;
			return *this;
		}

		if (direction == left)
		{
			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i].SetXPosition() = _4Blocks[i].GetXPosition() -1;
			}
			m_bMoved = left;
			return *this;
		}

		if (direction == down)
		{
			for (int i= 0; i < 4; i++)
			{
				_4Blocks[i].SetYPosition() = _4Blocks[i].GetYPosition() +1;
			}
			m_bMoved = down;
			return *this;
		}

		if (direction == up)
		{
			for (int i =0; i<4; i++)
			{
				_4Blocks[i].SetYPosition() = _4Blocks[i].GetYPosition() -1;
			}

			m_bMoved = up;
			return *this;
		}

	}
	
	
	long long Block::GetInseed() {return m_internalseed;}


	void Block::SetImgPointer(BitMapObject* pObject)
	{
		for (int i = 0; i<4; i++)
		{
			_4Blocks[i].SetIMGPointer(pObject);
		}
	}

