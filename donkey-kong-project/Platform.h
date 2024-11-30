#pragma once
#include "StaticObj.h"


class Platform: public StaticObj
{
	int len;
	
public:
	Platform(Position p, char symbol, int _len);
	int getLen();
	void setLen(int newLen);
	
};

