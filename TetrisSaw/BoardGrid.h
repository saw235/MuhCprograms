#pragma once

#include <vector>
#include "Bag.h"

const int TILESIZE = 40;
const int SIDEBARWIDTH = 10;

enum WALLCOLLISION
{
	NO_COLLISION,
	COLLISION_LEFTWALL,
	COLLISION_RIGHTWALL,
	ROTATE_COLLISION_LEFTWALL,
	ROTATE_COLLISION_RIGHTWALL

};
using namespace std;
class BoardGrid
{
	
private:
	const int m_boardwidth;
	const int m_boardlength;


	

	BitMapObject imgBoard;
	BitMapObject imgTile;
	BitMapObject* projectionTile;

	vector<SmallerBlock> LandedBlocks;

	vector<Position> Mapping;

	Block currentbloc;
	Block holdbloc;

	Block projection;

	Block previewblock[5];

public:
	
	const Position initialpos;
	const Position holdpos;
	bool bswitched;
	bool harddroped;

	//constructor
	BoardGrid (Bag& bag, int length = 20, int width = 10): m_boardlength(length), m_boardwidth(width), currentbloc(bag.GetNextBloc(Position(m_boardwidth/2, -1))), bswitched(0), initialpos(Position((m_boardwidth/2)-1, -1)), holdpos(Position((m_boardwidth+7),m_boardlength/2))
	{
	}

	void SetImgPointers(BitMapObject* pObject);
	void SetPreviewTile(BitMapObject* pProjectiontile);
	bool LineFull();
	void DrawBoard();
	void DrawBlock(SmallerBlock &SmallBlock);
	void DrawTile(int x,int y,Color tile_color);
	
	int GetPositionOfFloor(int column);

	bool BoardGrid::Projected();

	void UpdateLandedBlocks(Block& landed);
	
	void LineClear(int row);

	void GenerateProjection(BitMapObject* projectiontiles);

	int GetBoardLength();

	int GetBoardWidth();

	BitMapObject& Getbmo();
	
	BitMapObject& GetTileImg();

	Block& GetCurrentBloc();
	
	Block& GetHoldBloc();

	void changeholdbloc(Block nxtbloc);

	bool Collided();

	WALLCOLLISION Walled();

	void HardDrop();

	void DrawPreviewBlock();


	void UpdatePreviewBlock(Bag& firstbag, Bag& secondbag);

	bool returnswitched();
	void resetswitched();
};

