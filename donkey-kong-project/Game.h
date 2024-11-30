#pragma once
#include "StaticObj.h"
#include "Board.h"


class Game
{
	Board* board = nullptr; // all assets of the game
	

public:
	Game(int height, int width, int level, int platformSpacing);
	void start();
	//void stop();
	//void pause();
};