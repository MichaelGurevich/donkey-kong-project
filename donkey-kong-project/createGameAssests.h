#pragma once
#include "Platform.h"
#include "Ladder.h"
#include "StaticObj.h"
#include "DonkeyKong.h"

// ##### Platforms #####
Platform* createPlatform(int platformY, int platformMaxLen);
Platform* createPlatform(int platformY, int dir, int platformMaxLen, int randomPoint);
bool createPlatformCheck(int x, int dir, int platformMaxLen, int platformMinLen);
Platform** createPlatforms(int height, int platformsNum, int platformMaxLen, int platformSpacing);


// ##### Ladders ######
Ladder* createLadder(Platform* plat1, Platform* plat2, int ladderLen);
Ladder** createLadders(Platform**& platforms, int platformsNum, int platformSpacing);


// ##### Pauline #####
StaticObj* createPauilne(Position lastPlatPos, int lastPlatLen);


// ##### DonkeyKong #####
DonkeyKong* createDonkeyKong(Position lastPlatPos, int lastPlatLen);
