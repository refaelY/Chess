#include "Tool.h"
#include "Check.h"

/**Constructor*/
Tool::Tool(const string location, const char type)
{
	_location = location;
	_type = type;
	if (type > 96 && type < 123) // lower case
	{
		_color = 1;
	}
	else
	{
		_color = 0;
	}
}

/**
The fun is return the color
Input: none
Output: 1 - black, 0 - white
*/
int Tool::getColor() const
{
	return _color;
}

/**
The fun is return the location
Input: none
Output: the location
*/
string Tool::getLocation() const
{
	return _location;
}

/**
The fun is return the type
Input: none
Output: the type
*/
char Tool::getType() const
{
	return _type;
}

/**
The fun is set new location
Input: the new location
Output: none
*/
void Tool::setLocation(const string newLocation)
{
	_location = newLocation;
}

/**
The board locations are different in array locations so the function 
does a conversion to an array location
Input: Position in the board
*/
int* Tool::conversion(const string square)  
{
	char length = square[0]; //ex (square = "c5"), Length = 'c', width = '5'
	char width = square[1];
	int* ans = new int[2];
	length -= 49; //ex Length = 'c' afte Length = '2'

	switch (width)
	{
	case '0':
		width = '8';
		break;
	case '1':
		width = '7';
		break;
	case '2':
		width = '6';
		break;
	case '3':
		width = '5';
		break;
	case '5':
		width = '3';
		break;
	case '6':
		width = '2';
		break;
	case '7':
		width = '1';
		break;
	case '8':
		width = '0';
		break;
	default:
		break;
	}

	ans[LENGTH] = int(length) - 48;
	ans[WIDTH] = int(width) - 48;

	return ans;
}

/**
The fun is check all the options that can be disqualified and sends back the error code
Input: the dest and the all board and the turn if white or black
Output: if have chess or if is valid move
*/
char Tool::move(string dest, Board board, const int turn)
{
	char ans = VALID_MOVE;
	Check moveCheck(dest, this, board, turn);
	ans = moveCheck.otherPlayerTool();
	if (ans == VALID_MOVE)
	{
		ans = moveCheck.destSelfPopulated();
		if (ans == VALID_MOVE)
		{
			ans = moveCheck.sameDestAndSrc();
			if (ans == VALID_MOVE)
			{
				ans = moveCheck.invalidIndex();
				if (ans == VALID_MOVE)
				{
					ans = invalidToolMovement(Tool::conversion(dest), board);
					if (ans == VALID_MOVE)
					{
						ans = moveCheck.selfChess();
						if (ans == VALID_MOVE)
						{
							ans = moveCheck.chessCheck();
							if (ans == CHESS)
							{
								ans = moveCheck.checkMate();
								if (ans == VALID_MOVE)
								{
									ans = CHESS;
								}
							}
						}
					}
				}
			}
		}
	}

	return ans;
}

