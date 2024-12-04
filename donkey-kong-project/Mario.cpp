#include "Mario.h"

// function checks if mario won or lost
bool Mario::hasWonOrLost()
{
	char chToCheck = board.getChar(location);
	if (!isAlive(chToCheck) && hasWon(chToCheck))
	{
		return true;
	}
	return false;
}

// function returns true if mario didn't touch barrel or kong
bool Mario::isAlive(char chToCheck)
{
	if (chToCheck == 'B' or chToCheck == 'K')	// barrel or kong
	{
		this->lives--;
		return false;
	}

	return true;
}

// function returns true if mario touched Pauline
bool Mario::hasWon(char chToCheck)
{
	if (chToCheck == 'P')	// Pauline
	{
		this->won = true;
		return true;
	}
	return false;
}


/*
function gets a bool indicating if mario is going up or down the latte
function takes care of 3 cases:
	1) mario's on ladder and wants to go up
	2) mario's on ladder and wants to go down
	3) mario's movement is up and he reached above the last level of the ladder (he's in between levels)
*/
bool Mario::isOnLadder(bool up)
{
	char chToCheck = board.getChar(location);
	if (isLadder(chToCheck))
	{
		if (up)
		{
			return true;
		}
		else // he can only climb down if he isn't on floor
		{
			return (!isOnFloor(location));
		}
	}
	else
	{
		if (up and movingJumpCount == 0)	// regular up
		{
			if (wasOnLadder() and isFloor(chToCheck))	// at the end of ladder inside the floor
			{
				// stop climbing ladder and get to second floor or stay at top of ladder
				lastDir = currentDir;
				currentDir = directions.STAY;

				// move to second floor
				erase();
				drawOldLoc();
				location.setXY(location.getX(), location.getY() - 1);	// second floor

				if (isMarioOutOfBorder())
				{
					undoMove();
					location.setXY(location.getX(), location.getY() + 1);	// top of ladder
				}

				draw();
				return true;
			}
		}
	}
	return false;
}

/*
function checks if mario's location is out of bounds:
	1) location is out of our board's bounds.
	2) mario is touching the bottom part of board (abyss)
*/
bool Mario::isMarioOutOfBorder()
{
	if (isPosOutOfBorder(location))
	{
		return true;
	}
	else if (location.getY() == board.getHeight() - 1)	// mario got to bottom of floor
	{
		currentDir = directions.STAY;
		return true;
	}
	return false;
}

/*
function takes care of moving-up movement:
	1) uses var rightOrLeft to indicate if jump is to the right or to the left
*/
void Mario::handleUpMovement()
{
	// mario is mid jump since Move function moved one pixel up

	int rightOrLeft = -1;
	if (lastDir == directions.RIGHT)
	{
		rightOrLeft = 1;
	}

	if (movingJumpCount == 3)	 // end of moving jump
	{
		location.setXY(location.getX() + rightOrLeft, location.getY() + 3);
	}
	else
	{
		location.setX(location.getX() + rightOrLeft);
	}

	if (isMarioOutOfBorder() or isFloor(board.getChar(location)))		// undo and start falling
	{
		location.setX(location.getX() - rightOrLeft);
		if (movingJumpCount == 3)
		{
			location.setY(location.getY() - 3);
		}
		currentDir = directions.DOWN;
		lastDir = directions.UP;
	}
	else if (isOnFloor(location))  // go back to old direction
	{
		currentDir = lastDir;
		lastDir = directions.UP;
	}
	else if (location.getY() == 0 or isUnderFloor() or movingJumpCount == 3) // jumping in small spaces or at end of fall
	{
		currentDir = directions.DOWN;
		lastDir = directions.UP;
	}

	movingJumpCount++;
}

/*
function undos lsat move accordint to currentDir
*/
void Mario::undoMove()
{
	location.setX(location.getX() - currentDir.getX());
	location.setY(location.getY() - currentDir.getY());

	lastDir = currentDir;
	if (isMarioAboveFloor())
	{
		currentDir = directions.DOWN;
	}
	else
	{
		currentDir = directions.STAY;
	}
	draw();
}

bool Mario::isMarioAboveFloor()
{
	Position pos = location;
	pos.setXY(pos.getX(), pos.getY() + 1);
	if (isPosOutOfBorder(pos))
	{
		return false;
	}
	return isOnFloor(pos);
}

bool Mario::wasOnLadder()
{
	Position before(location.getX(), location.getY() + 1);
	if (!isPosOutOfBorder(before))
	{
		return (isLadder(board.getChar(before)));
	}
	return false;
}

bool Mario::isAboveLadder()
{
	if (isOnFloor(location))
	{
		Position pos = location;
		pos.setY(location.getY() + 2);
		if (isPosOutOfBorder(pos))
		{
			return false;
		}
		if (isLadder(board.getChar(pos)))
		{
			erase();
			drawOldLoc();
			location = pos;
			draw();
			return true;
		}
	}
	return false;
}

bool Mario::isUnderFloor()
{
	Position pos = location;
	pos.setY(pos.getY() - 1);
	return (isFloor(board.getChar(pos)));
}

/*
function:
	1) gets key that indicates move.
	2) takes care of keys related to mario only
	3) checks if key was a valid move if so it changes mario's direction.
	*) in case of new up direction function initializes movingJumpCount according to last movement
*/
int Mario::changeDir(char key)
{
	lastDir = currentDir;

	switch (std::tolower(key))
	{
	case('a'):	//left
		if (isOnFloor(location) or isOnLadder(true))
		{
			currentDir = directions.LEFT;
		}
		break;
	case('d'):	// right
		if (isOnFloor(location) or isOnLadder(true))
		{
			currentDir = directions.RIGHT;
		}
		break;
	case('w'):	//up
		if ((isOnFloor(location) and !isUnderFloor()) or isOnLadder(true))
		{
			movingJumpCount = 0;
			if (lastDir == directions.RIGHT or lastDir == directions.LEFT)
			{
				movingJumpCount = 1;
			}
			currentDir = directions.UP;
		}
		break;
	case('x'):	// down
		if (isOnLadder(false) or isAboveLadder())
		{
			currentDir = directions.DOWN;
		}
		break;
	case('s'):	// stay
		if (isOnFloor(location) or isOnLadder(true))
		{
			currentDir = directions.STAY;
		}
		break;
	default: //ignore
		break;
	}

	return move();
}


/*
* function:
	1) moves mario according to currentDir
	2) checks if new location is valid
		*) if move wasn't valid it undos it and sets currentDir accordingly.
	3) prepares new currentDir if needed
	4) function returns 1 if Mario lost, 0 else

	- function uses handleUpMovement: function that takes care of jumping
	(ie: handles special edge cases for moving jump)
*/
int Mario::move()
{
	if (currentDir == directions.STAY) { return 0; } // nothing to do

	// erase old location, return what was there
	erase();
	drawOldLoc();

	//move to next position
	location.setX(location.getX() + currentDir.getX());
	location.setY(location.getY() + currentDir.getY());

	if (currentDir == directions.UP and movingJumpCount != 0)			//moving jump
	{
		handleUpMovement();
	}
	else if (isMarioOutOfBorder())				//movements diff than moving up are easy to undo
	{
		undoMove();
	}
	else
	{
		if (currentDir == directions.UP)
		{
			if (!isOnLadder(true))
			{
				if (isMarioAboveFloor() and (location.getY() == 0 or isUnderFloor()))	// at the top of screen or jumping in small spaces
				{
					lastDir = directions.UP;
					currentDir = directions.DOWN;
				}
				else if (!isMarioAboveFloor() and !isOnFloor(location))	// at the end of reg jump
				{
					lastDir = directions.UP;
					currentDir = directions.DOWN;
				}
			}
		}
		else if (currentDir == directions.DOWN)
		{
			if (isOnFloor(location))	// just finished with ladder / falling / ending jump
			{
				lastDir = currentDir;
				currentDir = directions.STAY;
			}
			else if (location.getY() == board.getHeight() - 1)	// fell through hole to bottom of screen -> lost
			{
				currentDir = directions.STAY;
				lives--;
				return 1;
			}
		}
		else if (currentDir == directions.RIGHT or currentDir == directions.LEFT)
		{
			if (!isOnFloor(location))	// starts falling
			{
				lastDir = currentDir;
				currentDir = directions.DOWN;
			}
		}
	}

	if (hasWonOrLost()) { return 1; }

	draw();
	return 0;
}