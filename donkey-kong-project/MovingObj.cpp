#include "MovingObj.h"

void MovingObj::erase()
{
	gotoxy(location.getX(), location.getY());
	std::cout << ' ';
}

void MovingObj::drawOldLoc()
{
	gotoxy(location.getX(), location.getY());
	std::cout << board.getChar(location);
}

bool MovingObj::isFloor(char ch)
{
	return (ch == '=' or ch == '<' or ch == '>');
}

bool MovingObj::isLadder(char ch)
{
	return (ch == 'H');
}

bool MovingObj::isBarrel(char ch)
{
	return (ch == 'O');
}

MovingObj::MovingObj(Board& b, char i, Position loc, Position curr) :
	board(b), icon(i), location(loc), currentDir(curr)
{

}

bool MovingObj::isPosOutOfBorder(Position pos)
{
	return (pos.getX() < 0 or pos.getX() > 79 or pos.getY() > 24 or pos.getY() < 0);
}

bool MovingObj::isOnFloor(Position pos)
{
	pos.setXY(pos.getX(), pos.getY() + 1);	// check under
	if (isPosOutOfBorder(pos))
	{
		return false;
	}
	return(isFloor(board.getChar(pos)));
}