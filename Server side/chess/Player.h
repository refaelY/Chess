#pragma once

#include "Tool.h"

class Player
{
private:
	int _color;

public:

	Player(int color);
	~Player();
	int getColor();
};