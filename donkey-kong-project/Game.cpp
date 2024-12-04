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
	board = new Board(height, width, maxLevel, platformSpacing);
	mario = new Mario(*board);

}

void clearInputBuffer() {
	while (_kbhit()) { // While a key is in the buffer
		_getch();      // Read and discard it
	}
}


void Game::start()
{
		mario->draw();
		char key = 'e';	/////////////////////////////////////just for now
		while (key != 27) // esc
		{
			/*
			for (int i = 0; i < 5; i++)
			{
				barrels[i]->draw();
			}
			*/

			Sleep(50);
			if (_kbhit())
			{
				key = _getch();
				if (mario->changeDir(key) == 1)
				{
					key = 27;
				}
			}
			else
			{
				if (mario->move() == 1)
				{
					key = 27;
				}
			}
		}

		//clearInputBuffer();
		//gotoxy(0, 0);
		//std::cout << clearCanvas;
	
}