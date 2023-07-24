#pragma once

#include "Board.h"
#include "Player.h"
#include "Rook.h"

class Manager
{
private:

	Player _white;
	Player _black;
	Board _board;
	int _turn;

public:
	
	Manager(Tool*** board);
	~Manager();
	void general();

};