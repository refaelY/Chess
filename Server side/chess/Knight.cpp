#include "Knight.h"

/**Ctor*/
Knight::Knight(const string location, const char type) : Tool(location, type)
{
	_isStep = false;
}

/**Dtor*/
Knight::~Knight()
{

}


/**
The function checks whether this is a valid move of the tool
*/
char Knight::invalidToolMovement(int* dest, Board board)
{
	char ans = VALID_MOVE;
	int* src = Tool::conversion(getLocation());

	if (!(src[WIDTH] - 2 == dest[WIDTH] && src[LENGTH] - 1 == dest[LENGTH]))
	{
		if (!(src[WIDTH] - 2 == dest[WIDTH] && src[LENGTH] + 1 == dest[LENGTH]))
		{
			if (!(src[WIDTH] - 1 == dest[WIDTH] && src[LENGTH] - 2 == dest[LENGTH]))
			{
				if (!(src[WIDTH] - 1 == dest[WIDTH] && src[LENGTH] + 2 == dest[LENGTH]))
				{
					if (!(src[WIDTH] + 1 == dest[WIDTH] && src[LENGTH] - 2 == dest[LENGTH]))
					{
						if (!(src[WIDTH] + 2 == dest[WIDTH] && src[LENGTH] - 1 == dest[LENGTH]))
						{
							if (!(src[WIDTH] + 2 == dest[WIDTH] && src[LENGTH] + 1 == dest[LENGTH]))
							{
								if (!(src[WIDTH] + 1 == dest[WIDTH] && src[LENGTH] + 2 == dest[LENGTH]))
								{
									ans = ERROR_INVALID_TOOL_MOVEMENT;
								}
							}
						}
					}
				}
			}
		}
	}
	delete src;
	return ans;
}