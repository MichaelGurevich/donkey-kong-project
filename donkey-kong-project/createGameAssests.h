#pragma once
#include "Platform.h"
#include "Ladder.h"
#include "StaticObj.h"
#include "DonkeyKong.h"

// ##### Platforms #####
Platform* createPlatform(int platformY, int platformMaxLen, char* arr);
Platform* createPlatform(int platformY, int dir, int platformMaxLen, int randomPoint, char* arr);
bool createPlatformCheck(int x, int dir, int platformMaxLen, int platformMinLen);
Platform** createPlatforms(int height, int platformsNum, int platformMaxLen, int platformSpacing, char** arr);


// ##### Ladders ######
Ladder* createLadder(Platform* plat1, Platform* plat2, int ladderLen, char** arry);
Ladder** createLadders(Platform**& platforms, int platformsNum, int platformSpacing, char** arry);


// ##### Pauline #####
StaticObj* createPauilne(Position lastPlatPos, int lastPlatLen, char** arr);


// ##### DonkeyKong #####
DonkeyKong* createDonkeyKong(Position lastPlatPos, int lastPlatLen, char** arr);
