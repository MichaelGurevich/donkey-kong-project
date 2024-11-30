#include <iostream>
using namespace std;

#include "StaticObj.h"
#include <string.h>



StaticObj::StaticObj(Position p, char ch)
{
	pos = p;
	symbol = ch;
}

void StaticObj::setSymbol(char ch)
{
	symbol = ch;
}

char StaticObj::getSymbol()
{
	return symbol;
}

void StaticObj::printObj(int amount) // this function should be uniqe to each child of StaticObj
{
	cout << std::string(amount, symbol);
}

void StaticObj::setPosition(Position p)
{
	pos = p;
}

Position StaticObj::getPosition()
{
	return pos;
}