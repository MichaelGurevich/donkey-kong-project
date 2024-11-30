#pragma once

#include "StaticObj.h"
#include "Position.h"
#include "Platform.h"

class Ladder : public StaticObj
{
	int height;


public:
	Ladder(Position p, char symbol, int _height);
	int getHeight();
	void setHeight(int _height);
	void printObj();
};