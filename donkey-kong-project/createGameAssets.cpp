#include "createGameAssests.h"
#include "utils.h"


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

bool createPlatformCheck(int x, int dir, int platformMaxLen, int platformMinLen)
{
	// dir = 0 - left, dir = 1 - right
	// convert to ENUMs
	if (dir == 0)
		return x >= platformMinLen ? true : false;
	return platformMaxLen - x >= platformMinLen ? true : false;
}

Platform** createPlatforms(int height, int platformsNum, int platformMaxLen, int platformSpacing)
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

Ladder* createLadder(Platform* plat1, Platform* plat2, int ladderLen)
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

	return ladder;
}

Ladder** createLadders(Platform**& platforms, int platformsNum, int platformSpacing)
{
	Ladder** laddersList = new Ladder * [platformsNum - 1];

	for (int i = 0; i < platformsNum - 1; i++)
	{
		laddersList[i] = createLadder(platforms[i], platforms[i + 1], platformSpacing - 1);
		laddersList[i]->printObj();
	}
	return laddersList;
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

	return pauline;
}

DonkeyKong* createDonkeyKong(Position lastPlatPos, int lastPlatLen)
{

	int donkeyXmax, donkeyY, donkeyX;
	donkeyXmax = (lastPlatPos.getX() + lastPlatLen) / 2;
	donkeyY = lastPlatPos.getY();
	donkeyX = randomInt(lastPlatPos.getX(), donkeyXmax);

	Position donkeyKongPos(donkeyX, donkeyY - 1);

	DonkeyKong* donkeyKong = new DonkeyKong(donkeyKongPos, 'D');
	gotoxy(donkeyKong->getPosition());
	donkeyKong->printObj();
	return donkeyKong;
}