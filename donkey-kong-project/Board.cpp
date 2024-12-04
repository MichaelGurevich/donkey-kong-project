#include "Board.h"
#include "createGameAssests.h"
#include <iostream>
#include <algorithm>


void printBoard(int height, int width, int platformNum, int platformSpacing, char** arr);
char** createEmptyAssetsArray(int height, int width) {
	char** arry = new char* [height];
	for (int i = 0; i < height; i++)
	{
		arry[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			arry[i][j] = ' ';
		}
		//std::fill(arry[i], arry[i] + width, ' ');
	}
	return arry;
}

void printBoard(int height, int width, int platformNum, int platformSpacing, char** arr) {
	Platform** platformsList = createPlatforms(height, platformNum, width, platformSpacing, arr);
	Ladder** laddersList = createLadders(platformsList, platformNum, platformSpacing, arr);
	DonkeyKong* donkeyKong = createDonkeyKong(platformsList[platformNum - 1]->getPosition(), platformsList[platformNum - 1]->getLen(), arr);
	StaticObj* pauline = createPauilne(platformsList[platformNum - 1]->getPosition(), platformsList[platformNum - 1]->getLen(), arr);
}

char Board::getChar(Position p)
{
	int x, y;
	x = p.getX();
	y = p.getY();
	return array[y][x];
}

Board::Board(int _height, int _width, int platformNum, int platformSpacing) 
{
	height = _height;
	width = _width;
	array = createEmptyAssetsArray(height, width);
	printBoard(height, width, platformNum, platformSpacing, array);
}

char Board::getHeight()
{
	return height;
}
