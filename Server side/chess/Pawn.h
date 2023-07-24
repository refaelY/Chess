#pragma once
#include "Tool.h"
#include "Check.h"

class Pawn : public Tool
{

public:
	Pawn(const string location, const char type, int direction);
	~Pawn();

private:
	int _direction; // 0 - down, 1 - up
	char invalidToolMovement(int* destC,Board board);
	bool _isStep;
};