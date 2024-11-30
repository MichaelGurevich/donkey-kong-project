#pragma once

#include "StaticObj.h"
#include "Position.h"

class DonkeyKong : public StaticObj
{


public:
	using StaticObj::StaticObj;
	void throwBarrel();
};