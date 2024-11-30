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
	for (int i = 0; i < height; i++)
	{
		Position toPrint(pos.getX(), pos.getY() - i);
		gotoxy(toPrint);
		std::cout << symbol;
	}
}

