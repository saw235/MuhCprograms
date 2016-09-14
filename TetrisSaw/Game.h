#pragma once

//need this for srand and rand
#include <stdlib.h>
//now let's include our bitmapobject definitions
#include "BoardGrid.h"

const int BOARD_LENGTH = 20;
const int BOARD_WIDTH = 10;
const Position initialpos = Position((BOARD_WIDTH/2)-1, -1);
const Position holdpos = Position((BOARD_WIDTH+2), 2);


void GameStart();

void EndGame();
 
void DisplayHighscores();

void NewGame();

void GameLoop();

bool GameInit();

void StartScreen();
