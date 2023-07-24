#include "Bishop.h"

/**Ctor*/
Bishop::Bishop(const string location, const char type) : Tool(location, type)
{

}

/**Dtor*/
Bishop::~Bishop()
{

}

/**
The function checks whether this is a valid move of the tool
*/
char Bishop::invalidToolMovement(int* destC, Board board)
{
	char ans = VALID_MOVE;
	int i = 0, j = 0, x = 0, changeI = 0;
	int* src = Tool::conversion(getLocation());

	if ((abs(src[LENGTH] - destC[LENGTH]) == abs(src[WIDTH] - destC[WIDTH])))
	{

		if (src[LENGTH] > destC[LENGTH])
		{
			j = destC[LENGTH];
			i = destC[WIDTH];
			x = src[LENGTH];
			changeI = src[WIDTH] > destC[WIDTH] ? 1 : -1;
		}
		else
		{
			j = src[LENGTH];
			i = src[WIDTH];
			x = destC[LENGTH];
			changeI = src[WIDTH] > destC[WIDTH] ? -1 : 1;
		}

		i += changeI;
		for (j++; j < x; j++)
		{
			if (board.getBoard()[i][j] != NULL)
			{
				ans = ERROR_INVALID_TOOL_MOVEMENT;
				break;
			}
			i += changeI;
		}
	}
	else
	{
		ans = ERROR_INVALID_TOOL_MOVEMENT;
	}



	delete src;
	return ans;
}
