#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
/**Ctor*/
Queen::Queen(const string location, const char type) : Tool(location, type)
{
	_isStep = false;
}

/**Dtor*/
Queen::~Queen()
{

}

/**
The function checks whether this is a valid move of the tool
*/
char Queen::invalidToolMovement(int* dest, Board board)
{
	char ans = VALID_MOVE;
	int* src = Tool::conversion(getLocation());
	
	Tool* temp = new Rook(getLocation(), getType());
	ans = temp->invalidToolMovement(dest, board); //If she walks like a rook
	delete temp;
	temp = new Bishop(getLocation(), getType());

	if (ans != VALID_MOVE)
	{
		ans = temp->invalidToolMovement(dest, board); //If she walks like a bishop
	}

	delete temp, src;

	return ans;
}