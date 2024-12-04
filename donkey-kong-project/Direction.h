#pragma once
#include "Position.h"

struct Directions {
	Position LEFT;
	Position UP;
	Position RIGHT;
	Position DOWN;
	Position STAY;
};

const static Directions directions = {
	//LEFT //UP	   //RIGHT//DOWN //STAY
	{-1,0}, {0,-1}, {1,0}, {0,1}, {0,0}
};
