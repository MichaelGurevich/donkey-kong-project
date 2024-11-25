#include <iostream>
using namespace std;

#include "Position.h"


int Position::getX()
{
	return x;
}

void Position::setX(int newX)
{
	x = newX;
}

int Position::getY()
{
	return y;
}

void Position::setY(int newY)
{
	y = newY;
}

void Position::setXY(int newX, int newY)
{
	x = newX;
	y = newY;
}