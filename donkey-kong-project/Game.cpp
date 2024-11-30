#include <iostream>
using namespace std;

#include "Game.h"
#include "utils.h"
#include <conio.h>
#include "StaticObj.h"
#include "Position.h"
#include <windows.h>
#include <random>
#include "Platform.h"
#include "Ladder.h"
#include "DonkeyKong.h"
#include "Board.h"


/*const int MIN_SPACE_BETWEEN_PLATFORMS = 4;
const int MAX_PLATFORM_LEN = 80;
const int MIN_PLATFORM_LEN = 40;


int minVal(int a, int b)
{
	return  a <= b ? a : b;
}

int maxVal(int a, int b)
{
	return  a >= b ? a : b;
}


int randomInt(int low, int high)
{

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> random(low, high);

	return random(rng);
}

bool createPlatformCheck(int x, int dir)
{
	// dir = 0 - left, dir = 1 - right

	if (dir == 0)
	{
		return x >= MIN_PLATFORM_LEN ? true : false;
	}
	else if (dir == 1)
	{
		return MAX_PLATFORM_LEN - x >= MIN_PLATFORM_LEN ? true : false;
	}
}

StaticObj* createPauilne(Position lastPlatPos, int lastPlatLen)
{

	int paulineXmin, paulineY, paulineX;
	paulineXmin = lastPlatPos.getX() + lastPlatLen - (lastPlatLen / 2);
	paulineY = lastPlatPos.getY();
	paulineX = randomInt(paulineXmin, paulineXmin + (lastPlatLen / 2));

	Position paulinePos(paulineX, paulineY - 1);
	StaticObj* pauline = new StaticObj(paulinePos, 'P');
	gotoxy(pauline->getPosition());
	pauline->printObj();

	return nullptr;
}

DonkeyKong* createDonkeyKong(Position lastPlatPos, int lastPlatLen)
{

	int donkeyXmax, donkeyY, donkeyX;
	donkeyXmax = (lastPlatPos.getX() + lastPlatLen) / 2;
	donkeyY = lastPlatPos.getY();
	donkeyX = randomInt(lastPlatPos.getX(),donkeyXmax);

	Position donkeyKongPos(donkeyX, donkeyY - 1);

	DonkeyKong* donkeyKong = new DonkeyKong(donkeyKongPos, 'D');
	gotoxy(donkeyKong->getPosition());
	donkeyKong->printObj();
	return nullptr;
}


StaticObj*** createLevel(int levelNum=1)
{
	Position lastPlatPos;
	int lastPlatLen;


	StaticObj*** gameAssets = nullptr;

	// 1. Create and print platforms
	Platform** platforms = createPlatforms(levelNum, 40);
	lastPlatPos = platforms[levelNum - 1]->getPosition();
	lastPlatLen = platforms[levelNum - 1]->getLen();

	// 2. Create and print ladders
	Ladder** laddersList = createLadders( platforms, levelNum, 1);

	// 3. Create and print Pauline
	StaticObj* pauline = createPauilne(lastPlatPos, lastPlatLen);

	// 4. Create and print Donkey
	DonkeyKong* donkeyKong = createDonkeyKong(lastPlatPos, lastPlatLen);

	return gameAssets;
	
}
 */

void Game::start()
{


	Board board(25, 80, 5, 5);

	while (!_kbhit())
	{
		Sleep(500);
	}

}