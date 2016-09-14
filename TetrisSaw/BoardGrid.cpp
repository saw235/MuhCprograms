#include "BoardGrid.h"

void BoardGrid::DrawBoard()
{

	//draw toolbar
	for (int x = m_boardwidth; x< m_boardwidth+ SIDEBARWIDTH; x++)
	{
		for(int y = 0; y< m_boardlength; y++)
		{
			DrawTile(x,y, Color::GRAY);
		}
	}

	//draw map
	for (int x = 0; x< m_boardwidth; x++)
	{
		for(int y = 0; y< m_boardlength; y++)
		{
			DrawTile(x,y, Color::NOCOLOR);
		}
	}
	//draw preview block

	for(int i= 0; i <5; i++)//loop through previewblock
	{
		for(int j=0; j<4; j++)//loop through the smallblocks
		{
			DrawBlock((previewblock[i].Get_4Blocks())[j]);
		}


	}

	//draw hold block
	if (holdbloc.GetBLOCTYPE() != NOBLOC)
	{
		for (int i = 0; i < 4 ; i++)
		{
			DrawBlock((holdbloc.Get_4Blocks())[i]);
		}

	}


	GenerateProjection(projectionTile);

	//draw projection
	for (int iii = 0; iii < 4; iii++)
	{
		DrawBlock((projection.Get_4Blocks())[iii]);
	}

	//draw current moving block

	for (int i = 0; i < 4 ; i++)
	{
		DrawBlock((currentbloc.Get_4Blocks())[i]);
	}

	if (LandedBlocks.size() > 0)
	{
		//draw landedblocks
		for (vector<SmallerBlock>::iterator it= LandedBlocks.begin(); it != LandedBlocks.end(); it++)
		{
			DrawBlock((*it));
		}
	}


}

void BoardGrid::DrawTile(int x,int y, Color tile_color)
{
	//mask first
	BitBlt(imgBoard,x*TILESIZE,y*TILESIZE,TILESIZE,TILESIZE,imgTile,tile_color*TILESIZE,TILESIZE,SRCAND);

	//then image
	BitBlt(imgBoard,x*TILESIZE,y*TILESIZE,TILESIZE,TILESIZE,imgTile,tile_color*TILESIZE,0,SRCPAINT);
}

int BoardGrid::GetPositionOfFloor(int column)
{
	int maxposi = m_boardlength;


	for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); it++)
	{
		if ( it->GetXPosition() == column)
		{
			if ( it->GetYPosition() < maxposi)
			{
				maxposi = it->GetYPosition();
			}
		}

	}

	return maxposi;
}


void BoardGrid::UpdateLandedBlocks(Block& landed)
{
	for (int i = 0; i <4; i++)
	{
		LandedBlocks.push_back((landed.Get_4Blocks())[i]);
	}
}

void BoardGrid::SetPreviewTile(BitMapObject* pProjectiontile)
{
	projectionTile = pProjectiontile;
}
bool BoardGrid::LineFull()
{
	for (int row = 0; row < m_boardlength; row++)
	{
		int blockcount = 0;
		for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); ++it)
		{
			if ( it->GetYPosition() == row)
			{
				blockcount++;

				if (blockcount == m_boardwidth)
				{
					LineClear(row);
					return true;
				}
			}	
		}



	}

	return false;
}
void BoardGrid::LineClear(int row)
{
	//clear out blocks

	auto it = LandedBlocks.begin();

	while( it != LandedBlocks.end())
	{
		if ( it->GetYPosition() == row)
		{
			it = LandedBlocks.erase(it);

		}
		else
		{
			if (it == LandedBlocks.end())
			{
				break;
			}
			it++;
		}

	}
	int count = 0;
	// decrease y position of every blocks above row by 1 
	for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); count++ ,it++)
	{
		if ( it->GetYPosition() < row)
		{
			LandedBlocks[count].SetYPosition() = LandedBlocks[count].GetYPosition() +1;
		}
	}

	DrawBoard();
}

int BoardGrid::GetBoardLength()
{
	return m_boardlength;
}

int BoardGrid::GetBoardWidth()
{
	return m_boardwidth;
}

void BoardGrid::DrawBlock(SmallerBlock & SmallBlock)
{


	//mask first
	BitBlt(imgBoard,SmallBlock.GetXPosition()*TILESIZE,SmallBlock.GetYPosition()*TILESIZE,TILESIZE,TILESIZE,*(SmallBlock.GetImgPointer()),SmallBlock.GetColor()*TILESIZE,TILESIZE,SRCAND);

	//then image
	BitBlt(imgBoard,SmallBlock.GetXPosition()*TILESIZE,SmallBlock.GetYPosition()*TILESIZE,TILESIZE,TILESIZE,*(SmallBlock.GetImgPointer()),SmallBlock.GetColor()*TILESIZE,0,SRCPAINT);

}

WALLCOLLISION BoardGrid::Walled()
{
	for (int i =0; i<4; i++)
	{
		if ((((currentbloc.Get_4Blocks())[i]).GetXPosition()) == -1)
		{
			
			return COLLISION_LEFTWALL;
		}
		else if ((((currentbloc.Get_4Blocks())[i]).GetXPosition()) == m_boardwidth)
		{
			return COLLISION_RIGHTWALL;
		}
	}

	return NO_COLLISION;
}

bool BoardGrid::Collided()
{

	for (int i =0; i<4; i++)
	{
		for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); it++)
		{

			if  (((((currentbloc.Get_4Blocks())[i]).GetXPosition()) == it->GetXPosition()) && ((((currentbloc.Get_4Blocks())[i]).GetYPosition()) == it->GetYPosition()))
			{
				return true;
			}

			else
			{
				continue;
			}
		}

		if ((((currentbloc.Get_4Blocks())[i]).GetYPosition()) == m_boardlength)
		{
			return true;
		}


	}
	return false;
}

bool BoardGrid::Projected()
{

	for (int i =0; i<4; i++)
	{
		for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); it++)
		{

			if  (((((projection.Get_4Blocks())[i]).GetXPosition()) == it->GetXPosition()) && ((((projection.Get_4Blocks())[i]).GetYPosition()) == it->GetYPosition()))
			{
				return true;
			}

			else
			{
				continue;
			}
		}

		if ((((projection.Get_4Blocks())[i]).GetYPosition()) == m_boardlength)
		{
			return true;
		}


	}
	return false;
}

void BoardGrid::SetImgPointers(BitMapObject* pObject)
{
	currentbloc.SetImgPointer(pObject);

	for (int i = 0; i <5; i++)
	{
		previewblock[i].SetImgPointer(pObject);
	}

	for (vector<SmallerBlock>::iterator it = LandedBlocks.begin(); it != LandedBlocks.end(); it++)
	{
		it->SetIMGPointer(pObject);
	}
}

BitMapObject& BoardGrid::Getbmo()
{
	return imgBoard;
}

BitMapObject& BoardGrid::GetTileImg()
{
	return imgTile;
}

Block& BoardGrid::GetCurrentBloc()
{
	return currentbloc;
}

void BoardGrid::HardDrop()
{
	while(!Collided())
	{
		currentbloc.Move(direction::down);
	}

	harddroped = true;
}

void BoardGrid::GenerateProjection(BitMapObject* projectiontiles)
{
	projection = currentbloc;
	projection.SetImgPointer(projectiontiles);
	while(!Projected())
	{
		projection.Move(direction::down);
	}

	projection.Move(direction::up);

	/*for (int iii = 0; iii < 4; iii++)
	{
		(projection.Get_4Blocks())[iii].SetColor() = GRAY;
	}*/
}

void BoardGrid::UpdatePreviewBlock(Bag& firstbag, Bag& secondbag)
{
	const int separation = 4;
	int previewblockcount = 0;


	//look through first bag and copy contents
	for(vector<Block>::iterator it = firstbag.Get_7Bloc().end(); it !=firstbag.Get_7Bloc().begin(); it--)
	{
		previewblock[4-previewblockcount] = (firstbag.Get_7Bloc())[firstbag.Get_7Bloc().size() - previewblockcount-1]; // -1 as vector starts from 0

		previewblockcount++;

		if (previewblockcount ==5)
		{
			break;
		}


	}
	if (previewblockcount <5)
	{
		int count = 0;
		//if number of block is less than 5 then look in second bag
		for(vector<Block>::iterator it = secondbag.Get_7Bloc().end(); it !=secondbag.Get_7Bloc().begin(); it--)
		{
			previewblock[4-previewblockcount] = secondbag.Get_7Bloc()[secondbag.Get_7Bloc().size() - count -1];
			previewblockcount++;
			count++;

			if (previewblockcount ==5)
			{
				break;
			}
		}


	}

	for(int i = 0; i< previewblockcount; i++)
	{
		//sets preview position
		previewblock[i].SetBlocPos(Position(m_boardwidth+2, m_boardlength - separation*i -3));
	}
}

Block& BoardGrid::GetHoldBloc()
{
	return holdbloc;
}

void BoardGrid::changeholdbloc(Block blocreceived)
{
	if (blocreceived.GetBLOCTYPE() != NOBLOC) //if its a bloc
	{
		holdbloc = currentbloc; // set holdblock to hold current bloc
		holdbloc.SetBlocPos(holdpos); // set block position to hold position

		currentbloc = blocreceived; // set current bloc equal to next bloc
		currentbloc.SetBlocPos(initialpos);
	}
	else
	{
		//else get a temperory holder to hold the holdbloc
		Block tmpbloc = holdbloc;

		//then hold the current bloc
		holdbloc = currentbloc;
		holdbloc.SetBlocPos(holdpos);

		//set currentbloc to the previous holdbloc saved in temp
		currentbloc = tmpbloc;
		currentbloc.SetBlocPos(initialpos);
	}



	bswitched = 1;
}

bool BoardGrid::returnswitched()
{
	return bswitched;
}
void BoardGrid::resetswitched()
{
	bswitched = FALSE;
}