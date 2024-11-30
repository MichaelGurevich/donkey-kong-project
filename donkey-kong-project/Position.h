#pragma once


class Position
{
	int x, y;

public:
	Position(int _x=0, int _y=0);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void setXY(int x, int y);
};
