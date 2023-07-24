#include "Pawn.h"
#define UP 0
#define DOWN 1

/**Ctor*/
Pawn::Pawn(const string location, const char type, int direction) : Tool(location, type)
{
	_direction = direction;
	_isStep = false;
}

/**Dtor*/
Pawn::~Pawn()
{

}

/**
The function checks whether this is a valid move of the tool
*/
char Pawn::invalidToolMovement(int* destC, Board board)
{
	char ans = VALID_MOVE;
	bool error = false;
	int* src = Tool::conversion(getLocation());

	//If goes straight one
	if (src[WIDTH] + 1 == destC[WIDTH] && src[LENGTH] == destC[LENGTH] && _direction == DOWN || src[WIDTH] - 1 == destC[WIDTH] && src[LENGTH] == destC[LENGTH] && _direction == UP)
	{
		if (board.getBoard()[destC[WIDTH]][destC[LENGTH]] != NULL)
		{
			error = true;
		}
		else
		{
			_isStep = true;
		}
	}
	//If going sideways
	else if (((src[WIDTH] + 1 == destC[WIDTH] && src[LENGTH] + 1 == destC[LENGTH]) || (src[WIDTH] + 1 == destC[WIDTH] && src[LENGTH] - 1 == destC[LENGTH]) && _direction == DOWN) || ((src[WIDTH] - 1 == destC[WIDTH] && src[LENGTH] - 1 == destC[LENGTH]) || (src[WIDTH] - 1 == destC[WIDTH] && src[LENGTH] + 1 == destC[LENGTH]) && _direction == UP))
	{
		if (!(board.getBoard()[destC[WIDTH]][destC[LENGTH]] != NULL))
		{
			error = true;
		}
		else
		{
			_isStep = true;
		}
	}
	//If two moved forward
	else if (_isStep == false)
	{
		if (!(src[WIDTH] + 2 == destC[WIDTH] && src[LENGTH] == destC[LENGTH] && _direction == DOWN || src[WIDTH] - 2 == destC[WIDTH] && src[LENGTH] == destC[LENGTH] && _direction == UP))
		{
			error = true;
		}
		if (board.getBoard()[src[WIDTH] + 1][src[LENGTH]] != NULL && _direction == DOWN || board.getBoard()[src[WIDTH] - 1][src[LENGTH]] != NULL  && _direction == UP)
		{
			error = true;
		}
		else if (board.getBoard()[destC[WIDTH]][destC[LENGTH]] == NULL)
		{
			_isStep = true;
		}
		else
		{
			error = true;
		}
	}
	else
	{
		error = true;
	}

	if (error == true)
	{
		ans = ERROR_INVALID_TOOL_MOVEMENT;
	}
	delete src;
	return ans;
}