#pragma once

#include "Position.h"

class StaticObj
{
protected:
	Position pos;
	char symbol;

public:
	StaticObj(Position p, char ch);
	void setSymbol(char ch);
	char getSymbol();
	void printObj(int amount=1);
	void setPosition(Position p);
	Position getPosition();
};