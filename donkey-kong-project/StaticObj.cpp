#include <iostream>
using namespace std;

#include "StaticObj.h"
#include <string.h>


void StaticObj::setSymbol(char ch)
{
	symbol = ch;
}

char StaticObj::getSymbol()
{
	return symbol;
}

void StaticObj::printObj(int amount)
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