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


Platform* createPlatform(int platformY, int platformMaxLen) {
	int platformMinLen, platformLen, platformX;

	platformMinLen = platformMaxLen / 2;
	platformLen = randomInt(platformMinLen, platformMaxLen); // random platform len
	platformX = randomInt(0, platformMaxLen - platformLen); // random platform start X
	Position platPos(platformX, platformY);
	Platform* plat = new Platform(platPos, '=', platformLen);

	return plat;
}

Platform* createPlatform(int platformY, int dir, int platformMaxLen, int randomPoint)
{
	int platformLen, platformX, platformMinLen;
	platformMinLen = platformMaxLen / 2;
	char symbol;
	if (dir == 0)
	{
		platformLen = randomInt(platformMinLen, randomPoint);
		platformX = randomInt(0, randomPoint - platformLen);
		symbol = '>';
	}
	else {
		platformLen = randomInt(platformMinLen, platformMaxLen - randomPoint);
		platformX = randomInt(randomPoint, platformMaxLen - platformLen);
		symbol = '<';
	}

	Position platPos(platformX, platformY);
	Platform* plat = new Platform(platPos, symbol, platformLen);

	return plat;
}