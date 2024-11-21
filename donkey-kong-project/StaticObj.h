#pragma once

#include "Position.h"

class StaticObj
{
	Position pos;
	char symbol;

public:
	void setSymbol(char ch);
	char getSymbol();
	void printObj(int amount);
	void setPosition(Position p);
	Position getPosition();
};