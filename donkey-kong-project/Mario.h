#pragma once

#include <iostream>
#include "utils.h"
#include "Position.h"
#include "Direction.h"
#include "MovingObj.h"


#define INITIALPOS = {1,23}


class Mario : public MovingObj {

	int lives = 3; // change to magic number!!
	bool won = false;
	Position lastDir = directions.STAY;

	int movingJumpCount = 0;

	bool hasWonOrLost();
	bool hasWon(char chToCheck);
	bool isAlive(char chToCheck);

	bool isMarioOutOfBorder();

	bool isOnLadder(bool up);
	bool wasOnLadder();
	bool isAboveLadder();

	bool isMarioAboveFloor();
	bool isUnderFloor();

	void handleUpMovement();
	void undoMove();

public:
	// MAGIC NUMBERS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Mario(Board& b) : MovingObj(b, '@', Position{ 1,23 }, Position(directions.STAY)) {};
	int changeDir(char key);
	int move();
};