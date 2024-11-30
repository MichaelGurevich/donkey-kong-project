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

Ladder* createLadder(Platform* plat1, Platform* plat2, int ladderLen)
{
	int rngStart, rngEnd = 0;
	int plat1x, plat2x;

	plat1x = plat1->getPosition().getX();
	plat2x = plat2->getPosition().getX();
	rngStart = maxVal(plat1x, plat2x);

	rngEnd = minVal(plat1x + plat1->getLen(), plat2x + plat2->getLen());


	int ladderX = randomInt(rngStart, rngEnd - 1);
	Position ladderPos(ladderX, plat1->getPosition().getY() - 1);
	Ladder* ladder = new Ladder(ladderPos, 'H', ladderLen);

	return ladder;
}