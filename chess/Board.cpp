#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Bishop.h"
#include "Player.h"


/**Ctor*/
Board::Board(Tool*** tool)
{
	_board = tool;
}

/**Dtor*/
Board::~Board()
{

}

/**
The fun is return the board
Input: none
Output: the board
*/
Tool*** Board::getBoard() const
{
	return _board;
}

/**
The fun is print the board to cmd
Input: none
Output: none
*/
void Board::printBoard() const
{
	int i = 0, j = 0;
	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			if (_board[j][i] == NULL)
			{
				cout << "# ";
			}
			else
			{
				cout << _board[j][i]->getType() << ' ';
			}
		}
		cout << endl;
	}
}

/**
The fun is moving the tool after check all the invalid move
Input: the dest move and the current tool and the torn for checking
Output: string if is valid move or if he is made chess and if have invalid move is throw exception
*/
char Board::move(string dest, const int turn, int* conversion_src, Tool* currTool)
{
	char ans = VALID_MOVE;
	int* conversion_dest = Tool::conversion(dest);
	ans = currTool->move(dest, *this, turn);

	if (ans == VALID_MOVE || ans == CHESS || ans == CHECKMATE)
	{ 
		currTool->setLocation(dest);

		if (_board[conversion_dest[WIDTH]][conversion_dest[LENGTH]] != NULL)
		{
			delete _board[conversion_dest[WIDTH]][conversion_dest[LENGTH]];
		}
		_board[conversion_dest[WIDTH]][conversion_dest[LENGTH]] = _board[conversion_src[WIDTH]][conversion_src[LENGTH]];
		_board[conversion_src[WIDTH]][conversion_src[LENGTH]] = NULL;
	}

	delete conversion_dest;
	return ans;
}