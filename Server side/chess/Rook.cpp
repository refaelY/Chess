#include "Rook.h"

/**Ctor*/
Rook::Rook(const string location, const char type) : Tool(location, type)
{
	_isStep = false;
}

/**Dtor*/
Rook::~Rook()
{}



/**
The fun is check if is the king can move there
Input: dest and the all board
Output: none
*/
char Rook::invalidToolMovement(int* dest, Board board)
{
	char ans = VALID_MOVE;
	int i = 0, j = 0;
	int length = 0;
	bool error = false;
	int* src = Tool::conversion(getLocation());
	
	if (src[LENGTH] == dest[LENGTH])
	{
		length = src[LENGTH];
		j = src[WIDTH] > dest[WIDTH] ? src[WIDTH] : dest[WIDTH];
		i = src[WIDTH] > dest[WIDTH] ? dest[WIDTH] + 1 : src[WIDTH] + 1;
		for (; i < j; i++)
		{
			if (board.getBoard()[i][length] != NULL)
			{
				error = true;
				break;
			}
		}
	}

	else if (src[WIDTH] == dest[WIDTH])
	{
		length = src[WIDTH];
		j = src[LENGTH] > dest[LENGTH] ? src[LENGTH] : dest[LENGTH];
		i = src[LENGTH] > dest[LENGTH] ? dest[LENGTH] + 1 : src[LENGTH] + 1;
		for (; i < j; i++)
		{
			if (board.getBoard()[length][i] != NULL)
			{
				error = true;
				break;
			}
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
	
	_isStep = true;
	delete src;
	return ans;
}