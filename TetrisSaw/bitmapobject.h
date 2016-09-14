
#pragma once
//we need this for windows stuff.
#include <windows.h>

class BitMapObject
{
private:
	HDC hdcMemory;	//memory dc
	HBITMAP hbmNew;  //New BitMap
	HBITMAP hbmOld;	 //Old Bitmap

	int iWidth;
	int iHeight;

public:
	//constructor
	BitMapObject();

	~BitMapObject();

	void Load(HDC hdcCompatible, LPCTSTR lpszFileName);

	void Create(HDC hdcCompatible, int width, int height);


	//Destroy Bitmap
	void Destroy();

	//return width
	int GetWidth();

	//return height
	int GetHeight();

	//converts to HDC
	operator HDC();
};

