#include "Board.h"
#include "createGameAssests.h"
#include <iostream>
#include <algorithm>


void printBoard(int height, int width, int platformNum, int platformSpacing);
char** createEmptyAssetsArray(int height, int width) {
	char** arry = new char* [height];
	for (int i = 0; i < height; i++)
	{
		arry[i] = new char[width];
		std::fill(arry[i], arry[i] + width, ' ');
	}
	return arry;
}

void printBoard(int height, int width, int platformNum, int platformSpacing) {
	Platform** platformsList = createPlatforms(height, platformNum, width, platformSpacing);
	Ladder** laddersList = createLadders(platformsList, platformNum, platformSpacing);
	DonkeyKong* donkeyKong = createDonkeyKong(platformsList[platformNum - 1]->getPosition(), platformsList[platformNum - 1]->getLen());
	StaticObj* pauline = createPauilne(platformsList[platformNum - 1]->getPosition(), platformsList[platformNum - 1]->getLen());
}

Board::Board(int _height, int _width, int platformNum, int platformSpacing) 
{
	height = _height;
	width = _width;
	array = createEmptyAssetsArray(height, width);
	printBoard(height, width, platformNum, platformSpacing);
}
