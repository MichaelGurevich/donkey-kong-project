#include <iostream>
#include "Game.h"
#include "utils.h"
#include <conio.h>
#include <windows.h>


Game::Game(int height, int width, int level, int platformSpacing)
{
	board = new Board(height, width, level, platformSpacing); // the board is being printed immidiatly
}


void Game::start()
{

	while (!_kbhit())
	{
		Sleep(500);
	}

}