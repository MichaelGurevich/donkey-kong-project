#include <iostream>
#include "Game.h"
#include "utils.h"
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>


const std::string clearCanvas =
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                "
"                                                                                ";




Game::Game(int _height, int _width, int _maxLevel, int _platformSpacing)
{
	height = _height;
	width = _width;
	maxLevel = _maxLevel;
	platformSpacing = _platformSpacing;

	
}

void clearInputBuffer() {
	while (_kbhit()) { // While a key is in the buffer
		_getch();      // Read and discard it
	}
}


void Game::start()
{


	board = new Board(height, width, 5, platformSpacing);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			gotoxy(j, i);
			std::cout << board->array[i][j];
		}
		
	}

	while (!_kbhit())
	{
		Sleep(500);
	}
	/*for (int i = 2; i <= 6; i++)
	{
		board = new Board(height, width, i, platformSpacing);
 		while (!_kbhit())
		{
			Sleep(500);
		}
		clearInputBuffer();
		gotoxy(0, 0);
		std::cout << clearCanvas;
	}*/
}