#pragma once
#include "StaticObj.h"
#include "Board.h"


class Game
{
	Board* board = nullptr; // all static assets of the game
	int height;
	int width;
	int maxLevel;
	int platformSpacing;
	

public:
	Game(int _height, int _width, int _maxLevel, int _platformSpacing);
	void start();
	//void stop();
	//void pause();
};