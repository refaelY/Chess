#pragma once
#include "Tool.h"
#include "Check.h"



using std::string;

class Bishop : public Tool
{
public:
	Bishop(const string location, const char type);
	~Bishop();

private:
	char invalidToolMovement(int* destC, Board board);
	bool _isStep;
};