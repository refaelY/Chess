#include "King.h"



/**Ctor*/
King::King(const string location, const char type) : Tool(location, type)
{
	_isStep = false;
}

/**Dtor*/
King::~King()
{

}


/**
The fun is check if is the king can move there
Input: dest and the all board
Output: none
*/
char King::invalidToolMovement(int* dest, Board board)
{
	char ans = VALID_MOVE;
	int* src = Tool::conversion(getLocation());
	if (!((src[LENGTH] == dest[LENGTH] && (src[WIDTH] + 1 == dest[WIDTH] || src[WIDTH] - 1 == dest[WIDTH])) || 
		(src[WIDTH] == dest[WIDTH] && (src[LENGTH] + 1 == dest[LENGTH] || src[LENGTH] - 1 == dest[LENGTH])) ||
		(src[LENGTH] + 1 == dest[LENGTH] && (src[WIDTH] + 1 == dest[WIDTH]) || src[LENGTH] - 1 == dest[LENGTH] && (src[WIDTH] - 1 == dest[WIDTH])) ||
		(src[LENGTH] - 1 == dest[LENGTH] && (src[WIDTH] + 1 == dest[WIDTH]) || src[LENGTH] + 1 == dest[LENGTH] && (src[WIDTH] -1 == dest[WIDTH]))))
	{
		ans = ERROR_INVALID_TOOL_MOVEMENT;
	}
	
	
	_isStep = true;
	delete src;
	return ans;
}