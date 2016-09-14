#include "bitmapobject.h"

BitMapObject::BitMapObject()
{
	hdcMemory = NULL;
	hbmNew = NULL;
	hbmOld = NULL;
	iWidth=0;
	iHeight=0;
}

BitMapObject::~BitMapObject()
{
	if (hdcMemory)
	{
		Destroy();
	}
}

void BitMapObject::Load(HDC hdcCompatible, LPCTSTR lpszFileName)
{
	//clear up memory
	if(hdcMemory)
	{
		Destroy();
	}

	//create memory dc
	hdcMemory = CreateCompatibleDC(hdcCompatible);

	//loadbitmap
	hbmNew = (HBITMAP)LoadImage(NULL,lpszFileName, IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

	//placebitmap into dc
	hbmOld = (HBITMAP)SelectObject(hdcMemory, hbmNew);

	//grab bitmap's properties

	BITMAP bmp;
	GetObject(hbmNew,sizeof(BITMAP), (LPVOID) &bmp);
	iWidth=bmp.bmWidth;
	iHeight=bmp.bmHeight;
}

void BitMapObject::Create(HDC hdcCompatible, int width, int height)
{
	if(hdcMemory)
		Destroy();
	
	//create the memory dc.
	hdcMemory=CreateCompatibleDC(hdcCompatible);
	
	//create the bitmap
	hbmNew=CreateCompatibleBitmap(hdcCompatible, width, height);
	
	//put the image into the dc
	hbmOld =(HBITMAP)SelectObject(hdcMemory, hbmNew);
	//change the width and height.
	iWidth=width;
	iHeight=height;
}

void BitMapObject::Destroy()
{
	//restore old bitmap.
	SelectObject(hdcMemory, hbmOld);

	//delete new bitmap.
	DeleteObject(hbmNew);

	//delete device context.
	DeleteDC(hdcMemory);

	//set members to 0/NULL
	hdcMemory=NULL;
	hbmNew=NULL;
	hbmOld=NULL;
	iWidth=0;
	iHeight=0;
}

BitMapObject::operator HDC()
{
	//return hdcMemory.
	return hdcMemory;
}

int BitMapObject::GetWidth()
{
	//return width
	return(iWidth);
}

int BitMapObject::GetHeight()
{
	//return height
	return(iHeight);
}