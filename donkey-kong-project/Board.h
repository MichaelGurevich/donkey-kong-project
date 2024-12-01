#pragma once


class Board
{
	int height;
	int width;
	

public:
	char** array;
	Board(int _height, int _width, int platformNum, int platformSpacing);
	
};