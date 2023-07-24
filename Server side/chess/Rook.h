#pragma once
#include "Tool.h"
#include "Check.h"

class Rook : public Tool
{

public:
	Rook(const string location, const char type);
	~Rook();
	char invalidToolMovement(int* dest, Board board);
private:
	bool _isStep;
};