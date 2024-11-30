#include "Board.h"
#include "Platform.h"
#include "Ladder.h"
#include "utils.h"

void printBoard(int height, int width, int platformNum, int platformSpacing);


bool createPlatformCheck(int x, int dir, int platformMaxLen, int platformMinLen)
{
	// dir = 0 - left, dir = 1 - right
	// convert to ENUMs

	if (dir == 0)
	{
		return x >= platformMinLen ? true : false;
	}
	return platformMaxLen - x >= platformMinLen ? true : false;
}

Platform** createPlatforms(int height,int platformsNum, int platformMaxLen, int platformSpacing)
{
	Platform** platforms = new Platform * [platformsNum];
	Platform* plat = nullptr;

	int platformLength, platformX, platformY, randomPoint, dirPriority, platformMinLen;
	platformX = 0;
	platformLength = 0;

	platformMinLen = platformMaxLen / 2;

	for (int i = 0; i < platformsNum; i++)
	{
		platformY = height - 1 - i * platformSpacing; // spacing between platforms
		if (i != 0)
		{
			platformX = plat->getPosition().getX();
			platformLength = plat->getLen();
			randomPoint = randomInt(platformX + 1, platformX + platformLength - 1);
			dirPriority = randomInt(0, 1);
			if (dirPriority == 0)
			{
				if (createPlatformCheck(randomPoint, dirPriority, platformMaxLen, platformMinLen))
				{
					plat = createPlatform(platformY, 0, platformMaxLen, randomPoint);
				}
				else {
					
					plat = createPlatform(platformY, 1, platformMaxLen, randomPoint);
				}
			}
			else {
				if (createPlatformCheck(randomPoint, dirPriority, platformMaxLen, platformMinLen))
				{
					plat = createPlatform(platformY, 1, platformMaxLen, randomPoint);
				}
				else {
					plat = createPlatform(platformY, 0, platformMaxLen, randomPoint);
				}
			}


		}
		else {
			plat = createPlatform(platformY, platformMaxLen);
		}
		platforms[i] = plat;
		gotoxy(plat->getPosition());
		plat->printObj(plat->getLen());
	}

	return platforms;
}

Ladder** createLadders(Platform**& platforms, int platformsNum, int platformSpacing)
{
	Ladder** laddersList = new Ladder * [platformsNum - 1];

	for (int i = 0; i < platformsNum - 1; i++)
	{
		laddersList[i] = createLadder(platforms[i], platforms[i+1], platformSpacing - 1);
		laddersList[i]->printObj();
	}
	return laddersList;
}


void printBoard(int height, int width, int platformNum, int platformSpacing) {
	Platform** platformsList = createPlatforms(height, platformNum, width, platformSpacing);
	Ladder** laddersList = createLadders(platformsList, platformNum, platformSpacing);
}

Board::Board(int _height, int _width, int platformNum, int platformSpacing) 
{
	height = _height;
	width = _width;
	printBoard(height, width, platformNum, platformSpacing);
}
