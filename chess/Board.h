#pragma once
#include "Tool.h"

using std::string;


class Tool;
class Board
{
private:
	Tool*** _board;

public:
	Board(Tool***);
	~Board();
	Tool*** getBoard() const;
	char move(string dest, const int turn, int* conversion_src, Tool* currTool);
	void printBoard() const;
};