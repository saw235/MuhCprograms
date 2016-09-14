#define WINDOWCLASS "Sawesome!!"
#define WINDOWTITLE "FKING 4WIDE BY THE AWESOME ME!"


#define WIN32_LEAN_AND_MEAN
//need this for windows stuff.
#include <windows.h>
#include "Game.h"
#include <sstream>
#include <string>

HINSTANCE hInstMain=NULL; //main app handle
HWND hWndMain=NULL; //main window handle

DWORD start_time;
DWORD collide_time;




BoardGrid* pBoard; //pointer to the board
Block current_block_save;
Block* pCurrentBloc; // pointer to the bloc
Block* pHoldBloc;
Bag* pCurrentBag;
Bag* pNextBag;

double arrow_pos_y = (BOARD_LENGTH/2)*TILESIZE;

bool barrowpointchanges = true;

BitMapObject* tempImg;
BitMapObject* projectionImg;
BitMapObject* arrow;
BitMapObject Logo;

int score = 0 ;
bool GAMESTARTED = false;

bool first_collision = true;

TCHAR StartText[ ] = "Start Game";
TCHAR ExitText[]= "Exit";


LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT uMSG, WPARAM wParam, LPARAM lParam)
{
	switch (uMSG)
	{
	case (WM_KEYDOWN):
		{
			if (GAMESTARTED)
			{
				//check for escape key
				if (wParam == VK_ESCAPE)
				{
					DestroyWindow(hWndMain);
					return 0; //handled message
				}
				else if(wParam==VK_DOWN) //check for down arrow key
				{
					pCurrentBloc->Move(direction::down);
					return(0);//handled message
				}

				else if(wParam== VK_CONTROL)
				{
					pCurrentBloc->Rotate(direction::left);
					return(0);
				}
				else if(wParam==VK_UP) //check for up arrow key
				{
					pCurrentBloc->Rotate(direction::right);
					return(0);//handled message
				}
				else if(wParam==VK_LEFT) //check for left arrow key
				{
					pCurrentBloc->Move(direction::left);
					return(0);//handled message
				}
				else if(wParam==VK_RIGHT) //check for right arrow key
				{
					pCurrentBloc->Move(direction::right);
					return(0);//handled message
				}
				else if(wParam==VK_SPACE)
				{
					pBoard->HardDrop();
					return(0);
				}
				else if(wParam==VK_SHIFT)
				{
					if (!(pBoard->returnswitched()))
					{
						if (pBoard->GetHoldBloc().GetBLOCTYPE() == NOBLOC) //if theres no block
						{
							pBoard->changeholdbloc(pCurrentBag->GetNextBloc(initialpos)); //get next bloc from bag
						}
						else
						{
							pBoard->changeholdbloc(Block()); //else sent in dummy bloc
						}
					}
					return(0);
				}
			}
			else
			{
				if (wParam == VK_ESCAPE)
				{
					DestroyWindow(hWndMain);
					return 0; //handled message
				}
				else if(wParam==VK_UP) //check for up arrow key
				{
					if (arrow_pos_y == (BOARD_LENGTH/2+2)*TILESIZE)
					{
						arrow_pos_y = (BOARD_LENGTH/2)*TILESIZE;
					}
					else
					{
						arrow_pos_y = (BOARD_LENGTH/2+2)*TILESIZE;
					}

					barrowpointchanges = true;
					return 0; 
				}
				else if(wParam==VK_RETURN)
				{
					if (arrow_pos_y == (BOARD_LENGTH/2)*TILESIZE)
					{
						GAMESTARTED = TRUE;
						return 0;
					}
					else if (arrow_pos_y == (BOARD_LENGTH/2+2)*TILESIZE)
					{
						DestroyWindow(hWndMain);
						return 0;
					}
				}

				else if(wParam==VK_DOWN) //check for down arrow key
				{
					if (arrow_pos_y == (BOARD_LENGTH/2)*TILESIZE)
					{
						arrow_pos_y = (BOARD_LENGTH/2+2)*TILESIZE;
					}
					else
					{
						arrow_pos_y = (BOARD_LENGTH/2)*TILESIZE;
					}
					return(0);//handled message
				}
			}

		}break;

	case (WM_DESTROY):
		{

			PostQuitMessage(0);

			return(0);
		}break;

	case (WM_PAINT):
		{
			//a variable needed for painting information
			PAINTSTRUCT ps;

			//start painting
			HDC hdc=BeginPaint(hwnd,&ps);

			//redraw the map
			BitBlt(hdc,0,0,TILESIZE*pBoard->GetBoardWidth()+TILESIZE*SIDEBARWIDTH,TILESIZE*pBoard->GetBoardLength(),pBoard->Getbmo(),0,0,SRCCOPY);

			//end painting
			EndPaint(hwnd,&ps);

			//handled message, so return 0
			return(0);
		}break;


	}

	//pass along any other message to default message handler
	return(DefWindowProc(hwnd,uMSG,wParam,lParam));

}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	hInstMain = hInstance; //assign instance to global variable

	WNDCLASSEX wcx; //create window class

	wcx.cbSize = sizeof(WNDCLASSEX);

	wcx.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	wcx.lpfnWndProc = MyWindowProc;  //set pointer to WNDPROC

	//class extra
	wcx.cbClsExtra=0;

	//window extra
	wcx.cbWndExtra=0;

	//application handle
	wcx.hInstance=hInstMain;

	//icon
	wcx.hIcon=LoadIcon(NULL,IDI_APPLICATION);

	//cursor
	wcx.hCursor=LoadCursor(NULL,IDC_ARROW);

	//background color
	wcx.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);


	//menu
	wcx.lpszMenuName=NULL;

	//class name
	wcx.lpszClassName=WINDOWCLASS;

	//small icon
	wcx.hIconSm=NULL;

	if (!RegisterClassEx(&wcx))
	{
		return 0;
	}

	//create main window

	hWndMain=CreateWindowEx(0,WINDOWCLASS,WINDOWTITLE, WS_BORDER | WS_SYSMENU | WS_CAPTION| WS_VISIBLE,0,0,320,240,NULL,NULL,hInstMain,NULL);

	//error check
	if(!hWndMain) { return 0;}

	//if program initialization failed, then return with 0
	if(!GameInit()) {return 0;}

	//message Structure

	MSG msg;


	//message pump

	//message pump
	for( ; ; )	
	{
		//look for a message
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			//there is a message

			//check that we arent quitting
			if(msg.message==WM_QUIT) break;

			//translate message
			TranslateMessage(&msg);

			//dispatch message
			DispatchMessage(&msg);
		}

		if (!GAMESTARTED)
		{
			StartScreen();
		}
		else
		{
			//run main game loop
			GameLoop();
		}
	}

	//clean up program data
	EndGame();

	//return the wparam from the WM_QUIT message
	return(msg.wParam);

}


void EndGame()
{
	//set both pointer to null
	pBoard = 0;
	pCurrentBloc = 0;

	//check if Current bag and next bag is pointing at something
	if (pCurrentBag)
	{
		delete pCurrentBag; //frees allocated memory
		pCurrentBag = NULL; //set to null
	}

	if (pNextBag)
	{
		delete pNextBag;
		pNextBag = NULL;
	}

	delete tempImg;
	tempImg = NULL;
	//free board
	delete pBoard;
	pBoard = NULL;

	//DisplayScore
	DisplayHighscores();
}

bool GameInit()
{
	srand(GetTickCount());
	mt19937 gen(rand());
	
	//Initiallize Game Objects and Board
	Bag* firstbag= new Bag(gen()); //initialise bag with random seed
	pCurrentBag = firstbag;



	pNextBag = new Bag(pCurrentBag->GetNextSeed());

	pBoard = new BoardGrid(*pCurrentBag,BOARD_LENGTH,BOARD_WIDTH); //construct board and sets pBoard pointing to it


	//set up hdc
	RECT rcTemp;
	HDC hdc=GetDC(hWndMain);
	//set the client area size

	SetRect(&rcTemp,0,0,pBoard->GetBoardWidth()*TILESIZE+TILESIZE*SIDEBARWIDTH,pBoard->GetBoardLength() *TILESIZE);//160x480 client area
	AdjustWindowRect(&rcTemp,WS_BORDER | WS_SYSMENU | WS_CAPTION| WS_VISIBLE,FALSE);//adjust the window size based on desired client area
	SetWindowPos(hWndMain,NULL,0,0,rcTemp.right-rcTemp.left,rcTemp.bottom-rcTemp.top,SWP_NOMOVE);//set the window width and height



	arrow = new BitMapObject;
	arrow ->Load(NULL,"arrow2.bmp");


	//create map image

	(pBoard->Getbmo()).Create(hdc,pBoard->GetBoardWidth()*TILESIZE+TILESIZE*SIDEBARWIDTH,pBoard->GetBoardLength() *TILESIZE);

	FillRect(pBoard->Getbmo(),&rcTemp,(HBRUSH)GetStockObject(WHITE_BRUSH));
	ReleaseDC(hWndMain,hdc);

	tempImg = new BitMapObject;

	tempImg->Load(NULL,"tile3.bmp");

	projectionImg = new BitMapObject;
	projectionImg->Load(NULL, "previewtile.bmp");

	pBoard->SetPreviewTile(projectionImg);

	//set small block img pointer to tempIMG
	(pBoard->GetTileImg()).Load(NULL,"tile2.bmp");

	pCurrentBloc = &(pBoard->GetCurrentBloc()); //set pointer pointing to currentbloc
	pCurrentBloc ->SetBlocPos(initialpos);
	pHoldBloc = &(pBoard->GetHoldBloc());
	pHoldBloc ->SetBlocPos(holdpos);
	pBoard->UpdatePreviewBlock(*pCurrentBag,*pNextBag); //updates preview blocks

	
	Logo.Load(NULL, "Logo2.bmp");
	
	
	//NewGame();

	return(true);//return success
}

void GameLoop()
{

	while (pBoard->Collided()) //checks for collision
	{

		if(pBoard->GetCurrentBloc().m_bMoved==down)//if its the floor
		{

			if (first_collision) //if first time collide
			{
				collide_time = GetTickCount();
				first_collision = false;
			}

			if (pBoard->harddroped)
			{
				pCurrentBloc->Move(up);
			}
			else
			{
				if ( (GetTickCount() - collide_time) < 1000) //if collision time is less than 500
				{
					pCurrentBloc->Move(up); 
					break;
				}
				else
				{
					pCurrentBloc->Move(up);
				}
			}
			pBoard->UpdateLandedBlocks(pBoard->GetCurrentBloc()); //updates landed block
			pBoard->GetCurrentBloc() = pCurrentBag->GetNextBloc(initialpos); //get next blocks
			pBoard->UpdatePreviewBlock(*pCurrentBag,*pNextBag); //updates preview blocks

			first_collision = true;
			pBoard->harddroped = false;

			if (pCurrentBag->m_blocleft == 5)
			{
				if (pNextBag == NULL)
				{
					pNextBag = new Bag(pCurrentBag->GetNextSeed());
				}
			}

			if (pCurrentBag->m_blocleft == 0)
			{
				delete pCurrentBag;
				pCurrentBag = pNextBag; //set pCurrentBag pointing to the next allocated bag
				pNextBag = NULL;//set nextbag to null
			}

			pBoard->SetImgPointers(tempImg);
			pBoard->DrawBoard();
			//invalidate the window rect
			InvalidateRect(hWndMain,NULL,FALSE);
			pCurrentBloc->m_bMoved = no_move;
		}


		else if(pBoard->GetCurrentBloc().m_bMoved == direction::right)
		{

			pCurrentBloc->Move(direction::left);

			pBoard->SetImgPointers(tempImg);
			pBoard->DrawBoard();
			//invalidate the window rect
			InvalidateRect(hWndMain,NULL,FALSE);
			pCurrentBloc->m_bMoved = no_move;

		}

		else if(pBoard->GetCurrentBloc().m_bMoved==direction::left)
		{

			pCurrentBloc->Move(direction::right);

			pBoard->SetImgPointers(tempImg);
			pBoard->DrawBoard();
			//invalidate the window rect
			InvalidateRect(hWndMain,NULL,FALSE);
			pCurrentBloc->m_bMoved = no_move;
		}	

		else if(pBoard->GetCurrentBloc().m_bRotated ==direction::right)
		{
			pCurrentBloc->Move(direction::down);
			if (pBoard->Collided()) //if stills collides restore original position
			{   
				pCurrentBloc->Move(direction::up);
				pCurrentBloc->Rotate(direction::left);

			}


			pBoard->SetImgPointers(tempImg);
			pBoard->DrawBoard();
			//invalidate the window rect
			InvalidateRect(hWndMain,NULL,FALSE);
			pCurrentBloc->m_bRotated = no_move;

		}

		else if(pBoard->GetCurrentBloc().m_bRotated ==direction::left)
		{

			pCurrentBloc->Move(direction::down);
			if (pBoard->Collided()) //if stills collides restore original position
			{   
				pCurrentBloc->Move(direction::up);
				pCurrentBloc->Rotate(direction::right);

			}


			pBoard->SetImgPointers(tempImg);
			pBoard->DrawBoard();
			//invalidate the window rect
			InvalidateRect(hWndMain,NULL,FALSE);
			pCurrentBloc->m_bRotated = no_move;

		}
		pBoard->resetswitched();
	}

	while ((pCurrentBloc->m_bMoved)||(pCurrentBloc->m_bRotated)||(pBoard->bswitched==1))
	{
		if (pCurrentBag->m_blocleft == 0)
		{
			delete pCurrentBag;
			pCurrentBag = pNextBag; //set pCurrentBag pointing to the next allocated bag
			pNextBag = NULL;//set nextbag to null
		}
		pBoard->UpdatePreviewBlock(*pCurrentBag,*pNextBag); //updates preview blocks
		pBoard->SetImgPointers(tempImg);
		pBoard->DrawBoard();
		//invalidate the window rect
		InvalidateRect(hWndMain,NULL,FALSE);
		break;
	}

	if (pBoard->Walled())
	{
		switch (pBoard->Walled())
		{
		case (COLLISION_LEFTWALL):
			pCurrentBloc->Move(direction::right);
			pBoard->DrawBoard();
			break;
		case (COLLISION_RIGHTWALL):
			pCurrentBloc->Move(direction::left);
			pBoard->DrawBoard();
			break;
		}
	}



	while (pBoard->LineFull())
	{
		score += 1000;
	}

	if ( (GetTickCount() - start_time) > 1000)
	{
		pCurrentBloc->Move(direction::down);
		start_time=GetTickCount();

	}
}

void StartScreen()
{
	double displacement_x = 2;
	double displacement_y = 0.25;

	BitBlt(pBoard->Getbmo(), double(BOARD_WIDTH/2-2)*TILESIZE,(BOARD_LENGTH/5)*TILESIZE, 501,123, Logo, 0,0,SRCAND);
	BitBlt(pBoard->Getbmo(), double(BOARD_WIDTH/2-2)*TILESIZE,(BOARD_LENGTH/5)*TILESIZE, 501,123, Logo, 0,0,SRCPAINT);


	TextOut(pBoard->Getbmo(),double(BOARD_WIDTH/3+displacement_x)*TILESIZE,(BOARD_LENGTH/2+displacement_y)*TILESIZE,StartText, ARRAYSIZE(StartText));
	TextOut(pBoard->Getbmo(),double(BOARD_WIDTH/3+displacement_x)*TILESIZE,(BOARD_LENGTH/2+2+displacement_y)*TILESIZE,ExitText, ARRAYSIZE(ExitText));


	//mask first
	BitBlt(GetDC(hWndMain),double(BOARD_WIDTH/3-2+displacement_x)*TILESIZE,arrow_pos_y,TILESIZE,TILESIZE,*arrow,0,0,SRCAND);
	//then image
	BitBlt(GetDC(hWndMain),double(BOARD_WIDTH/3-2+displacement_x)*TILESIZE,arrow_pos_y,TILESIZE,TILESIZE,*arrow,0,0,SRCPAINT);

	InvalidateRect(hWndMain,NULL,FALSE);




}





void DisplayHighscores()
{
	std::stringstream ssMessage;

	ssMessage << "Congratulations!! You've gotten the highest score eva!! Its:  " << score;

	char* sMessage = new char[ssMessage.gcount()+1];
	ssMessage >> sMessage;
	MessageBoxA(hWndMain, sMessage, "High Score", MB_OK);
	delete[] sMessage;
	sMessage = 0;

}