#pragma once
#include "Tool.h"
#include "Check.h"

using std::string;

class King : public Tool
{
public:
	King(const string location, const char type);
	~King();

private:
	char invalidToolMovement(int* dest , Board board);
	bool _isStep;
};