#pragma once

#include "bitmapobject.h"
#include "Position.h"

enum Color
{
	RED,
	ORANGE,
	GREEN,
	YELLOW,
	LIGHTBLUE,
	DARKBLUE,
	PURPLE,
	GRAY,
	NOCOLOR
	
};
class SmallerBlock

{
private:
	Position sblocposi;
	Color BlocColor;

	BitMapObject* imgBlocks;

public:
	// -1 for nonexistant 
	SmallerBlock(Position blocposi = Position(-1,-1)): sblocposi(blocposi)
	{
	}

	BitMapObject* GetImgPointer()
	{
		return imgBlocks;
	}


	void SetIMGPointer(BitMapObject* pObject)
	{
		imgBlocks = pObject;
	}

	Color& SetColor() {return BlocColor;}
	Color GetColor() const {return BlocColor;}

	int GetXPosition() const {return sblocposi.GetXPosition();}
	int GetYPosition() const {return sblocposi.GetYPosition();}

	int& SetXPosition() {return sblocposi.SetXPosition();}
	int& SetYPosition() {return sblocposi.SetYPosition();}

	Position& GetPosition() {return sblocposi;}

	SmallerBlock& operator=(const SmallerBlock& source)
	{
		sblocposi = source.sblocposi;
		BlocColor = source.GetColor();

	   imgBlocks = source.imgBlocks;

	   return *this;
	}
};
