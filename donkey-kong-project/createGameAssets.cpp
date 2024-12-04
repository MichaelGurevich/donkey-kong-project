#include "createGameAssests.h"
#include "utils.h"
#include "algorithm"


Platform* createPlatform(int platformY, int platformMaxLen, char* arr) {
	int platformMinLen, platformLen, platformX;

	platformMinLen = platformMaxLen / 2;
	platformLen = randomInt(platformMinLen, platformMaxLen); // random platform len
	platformX = randomInt(0, platformMaxLen - platformLen); // random platform start X
	Position platPos(platformX, platformY);
	Platform* plat = new Platform(platPos, '=', platformLen);

	std::fill(arr + platformX, arr + platformX + platformLen, '=');


	return plat;
}

Platform* createPlatform(int platformY, int dir, int platformMaxLen, int randomPoint, char* arr)
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

	
	std::fill(arr + platformX, arr + platformX + platformLen, symbol);

	return plat;
}

bool createPlatformCheck(int x, int dir, int platformMaxLen, int platformMinLen)
{
	// dir = 0 - left, dir = 1 - right
	// convert to ENUMs
	if (dir == 0)
		return x >= platformMinLen ? true : false;
	return platformMaxLen - x >= platformMinLen ? true : false;
}

Platform** createPlatforms(int height, int platformsNum, int platformMaxLen, int platformSpacing, char** arr)
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
					plat = createPlatform(platformY, 0, platformMaxLen, randomPoint, arr[platformY]);
				}
				else {

					plat = createPlatform(platformY, 1, platformMaxLen, randomPoint, arr[platformY]);
				}
			}
			else {
				if (createPlatformCheck(randomPoint, dirPriority, platformMaxLen, platformMinLen))
				{
					plat = createPlatform(platformY, 1, platformMaxLen, randomPoint, arr[platformY]);
				}
				else {
					plat = createPlatform(platformY, 0, platformMaxLen, randomPoint, arr[platformY]);
				}
			}


		}
		else {
			plat = createPlatform(platformY, platformMaxLen, arr[platformY]);
		}
		platforms[i] = plat;
		gotoxy(plat->getPosition());
		plat->printObj(plat->getLen());
	}

	return platforms;
}

Ladder* createLadder(Platform* plat1, Platform* plat2, int ladderLen, char** arry)
{
	int rngStart, rngEnd = 0;
	int plat1x, plat2x;

	plat1x = plat1->getPosition().getX();
	plat2x = plat2->getPosition().getX();
	rngStart = maxVal(plat1x, plat2x);

	rngEnd = minVal(plat1x + plat1->getLen(), plat2x + plat2->getLen());


	int ladderX = randomInt(rngStart, rngEnd - 1);
	Position ladderPos(ladderX, plat1->getPosition().getY() - 1);
	Ladder* ladder = new Ladder(ladderPos, 'H', ladderLen);

	int ladderY = ladderPos.getY();
	for (int i = 0; i < ladderLen; i++)
	{
		arry[ladderY-i][ladderX] = 'H';
	}

	return ladder;
}

Ladder** createLadders(Platform**& platforms, int platformsNum, int platformSpacing, char** arry)
{
	Ladder** laddersList = new Ladder * [platformsNum - 1];

	for (int i = 0; i < platformsNum - 1; i++)
	{
		laddersList[i] = createLadder(platforms[i], platforms[i + 1], platformSpacing - 1, arry);
		laddersList[i]->printObj();
	}
	return laddersList;
}


StaticObj* createPauilne(Position lastPlatPos, int lastPlatLen, char** arr)
{

	int paulineXmin, paulineY, paulineX;
	paulineXmin = lastPlatPos.getX() + lastPlatLen - (lastPlatLen / 2);
	paulineY = lastPlatPos.getY() - 1;
	paulineX = randomInt(paulineXmin, paulineXmin + (lastPlatLen / 2));

	Position paulinePos(paulineX, paulineY);
	StaticObj* pauline = new StaticObj(paulinePos, 'P');
	gotoxy(pauline->getPosition());
	pauline->printObj();
	arr[paulineY][paulineX] = 'P';

	return pauline;
}

DonkeyKong* createDonkeyKong(Position lastPlatPos, int lastPlatLen, char** arr)
{

	int donkeyXmax, donkeyY, donkeyX;
	donkeyXmax = (lastPlatPos.getX() + lastPlatLen) / 2;
	donkeyY = lastPlatPos.getY() - 1;
	donkeyX = randomInt(lastPlatPos.getX(), donkeyXmax);

	Position donkeyKongPos(donkeyX, donkeyY);

	DonkeyKong* donkeyKong = new DonkeyKong(donkeyKongPos, 'D');
	gotoxy(donkeyKong->getPosition());
	donkeyKong->printObj();
	arr[donkeyY][donkeyX] = 'D';
	return donkeyKong;
}