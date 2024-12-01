#include "utils.h"
#include <windows.h>
#include <iostream>
#include <random>
using namespace std;

void gotoxy(Position p)
{   
    cout.flush();
    COORD coord;
    coord.X = p.getX();
    coord.Y = p.getY();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotoxy(int x, int y)
{
    cout.flush();
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

