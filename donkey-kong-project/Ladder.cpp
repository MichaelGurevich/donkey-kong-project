#include "Ladder.h"
#include "utils.h"
#include <iostream>

Ladder::Ladder(Position p, char ch, int _height)
	:StaticObj(p, ch)
{
	height = _height;
}


int Ladder::getHeight() { return height; };

void Ladder::setHeight(int _height) { height = _height; };


void Ladder::printObj()
{
	int x, y;
	x = pos.getX();
	y = pos.getY();
	for (int i = 0; i < height; i++)
	{
		gotoxy(x, y - i);
		std::cout << symbol;
	}
}

