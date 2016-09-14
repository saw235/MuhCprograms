#pragma once
#include <math.h>
#include "SmallerBlock.h"

#define PI 3.141596

enum BLOCTYPE
	{
		NOBLOC,
		OBLOC,
		TBLOC,
		LBLOC,
		JBLOC,
		SBLOC,
		ZBLOC,
		IBLOC,
		
	};


class Block
{
private:


	BLOCTYPE m_type;
	long long m_internalseed;
	
	SmallerBlock _4Blocks[4]; //array of 4 smallerblocks
	SmallerBlock _PreviousBlock[4];


	

	//Block();//disallow empty constructor

public:

	direction m_bRotated;
	direction m_bMoved;
	
	Block(BLOCTYPE type = NOBLOC, Position &blockpos = Position(-1,-1), int seed = 0);


	Block(const Block& source); // copy constructor
	

	void SetBlocPos(const Position& blockpos);

	Block& Rotate(direction direction);

	Block& Move(direction direction);
	
	BLOCTYPE GetBLOCTYPE();
	long long GetInseed();

	SmallerBlock* Get_4Blocks();

	Block& operator=(const Block& source);
	void SetImgPointer(BitMapObject* pObject);


};

