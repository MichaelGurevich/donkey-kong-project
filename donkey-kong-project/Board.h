#pragma once
#include "Position.h"


static constexpr int MAX_Y = 25;
static constexpr int TOP_OF_BOARD = 0;

class Board
{
	int height;
	int width;
	

public:
	char** array;
	Board(int _height, int _width, int platformNum, int platformSpacing);
	char getChar(Position p);
	char getHeight();
};