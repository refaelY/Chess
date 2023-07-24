#pragma once
#include "Tool.h"
#include "Check.h"

using std::string;

class Queen : public Tool
{
public:
	Queen(const string location, const char type);
	~Queen();

private:
	char invalidToolMovement(int* dest, Board board);
	bool _isStep;
};