#include "Platform.h"
#include "utils.h"


Platform::Platform(Position p, char symbol, int _len=0)
	:StaticObj(p, symbol)
{
	len = _len;
}

int Platform::getLen()
{
	return len;
}
void Platform::setLen(int newLen)
{
	len = newLen;
}
