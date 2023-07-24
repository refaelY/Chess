#pragma once
#include "Tool.h"
#include "Check.h"

using std::string;

class Knight : public Tool
{
public:
	Knight(const string location, const char type);
	~Knight();

private:
	char invalidToolMovement(int* dest, Board board);
	bool _isStep;
};