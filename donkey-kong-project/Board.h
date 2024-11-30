#pragma once



class Board
{
	int height;
	int width;
	char** array;

public:
	Board(int _height, int _width, int platformNum, int platformSpacing);
	
};