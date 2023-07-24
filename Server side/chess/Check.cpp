#include "Check.h"


/**Ctor*/
Check::Check(const string dest, Tool* tool, const Board board, const int turn) : exception()
{
	_board = new Board(board.getBoard());
	_tool = tool;
	_dest = dest;
	_turn = turn;
}

/**Dtor*/
Check::~Check()
{
	delete _board;
}

/**
Check if the user pressure the empty square
Input: none
Output: none
*/
char Check::otherPlayerTool() const
{
	char ans = VALID_MOVE;
	if (_tool->getColor() != _turn)
	{
		ans = ERROR_OTHER_PLAYER_TOOL;
	}

	return ans;
}

/**
The fun is check if the dest have a self tool
Input: none
Output: none but if invalid move is throw exception
*/
char Check::destSelfPopulated() const
{
	char ans = VALID_MOVE;
	int* dest = Tool::conversion(_dest);

	if (_board->getBoard()[dest[WIDTH]][dest[LENGTH]] != NULL)
	{
		if (_board->getBoard()[dest[WIDTH]][dest[LENGTH]]->getColor() == 1 && 1 == _turn || _board->getBoard()[dest[WIDTH]][dest[LENGTH]]->getColor() == 0 && 0 == _turn)
		{
			if (_board->getBoard()[dest[WIDTH]][dest[LENGTH]] != NULL)
			{
				ans = ERROR_DEST_SELF_POPULATED;
			}
		}
	}

	delete dest;
	return ans;
}

/**
The fun is check if the dest and the src is same
Input: none
Output: none but if invalid move is throw exception
*/
char Check::sameDestAndSrc() const
{
	char ans = VALID_MOVE;

	string src = _tool->getLocation();
	if (src == _dest)
	{
		ans = ERROR_SAME_DEST_AND_SRC;
	}
	return ans;
}

/**
The function checks all the soldiers of the same line if it threatens the other king
input: NONE
output: if have chess - '1' if valid move = '0'
*/
char Check::chessCheck() const
{
	char chess = VALID_MOVE;
	int i = 0, j = 0;
	string toolLocationTemp = _tool->getLocation();
	string tempLocation;
	Tool* tempTool_test = _board->getBoard()[Tool::conversion(_dest)[0]][Tool::conversion(_dest)[1]];

	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(_dest);
	_board->getBoard()[Tool::conversion(_dest)[0]][Tool::conversion(_dest)[LENGTH]] = _board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]];
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = NULL;

	int* kingLocationC = NULL;
	string kingLocation;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (_board->getBoard()[i][j] != NULL)
			{
				if ((_board->getBoard()[i][j]->getType() == 'k' && _turn == 0) || (_board->getBoard()[i][j]->getType() == 'K' && _turn == 1))
				{
					kingLocation = _board->getBoard()[i][j]->getLocation();
					kingLocationC = Tool::conversion(kingLocation);
				}
			}
		}
	}
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (_board->getBoard()[i][j] != NULL)
			{
				if (_board->getBoard()[i][j]->getColor() == _turn)
				{
					if (_board->getBoard()[i][j]->invalidToolMovement(kingLocationC, *_board) == VALID_MOVE)
					{
						chess = CHESS;
					}
					
				}
			}
		}
	}
	
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = _board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]];
	_board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]] = tempTool_test;
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(toolLocationTemp);
	delete kingLocationC;
	return chess;
}

/**
The function checks whether the action I'm making is threatening me
intput: none
output: if have self chess = '4' valid move = '0'
*/
char Check::selfChess() const
{
	char chess = VALID_MOVE;
	int i = 0, j = 0;
	string toolLocationTemp = _tool->getLocation();
	string tempLocation;
	Tool* tempTool_test = _board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]];

	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(_dest);
	_board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]] = _board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]];
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = NULL;

	int* kingLocationC = NULL;
	string kingLocation;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (_board->getBoard()[i][j] != NULL)
			{
				if ((_board->getBoard()[i][j]->getType() == 'k' && _turn == 1) || (_board->getBoard()[i][j]->getType() == 'K' && _turn == 0))
				{
					kingLocation = _board->getBoard()[i][j]->getLocation();
					kingLocationC = Tool::conversion(kingLocation);
				}
			}
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (_board->getBoard()[i][j] != NULL)
			{
				if (_board->getBoard()[i][j]->getColor() != _turn)
				{
					if (_board->getBoard()[i][j]->invalidToolMovement(kingLocationC, *_board) == VALID_MOVE)
					{
						chess = ERROR_SELF_CHESS;
					}

				}
			}
		}
	}

	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = _board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]];
	_board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]] = tempTool_test;
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(toolLocationTemp);
	delete kingLocationC;
	return chess;
}

/**
The function checks the index if is valid
Input: none
output: error index - '5' valid - '0'
*/
char Check::invalidIndex() const
{
	char ans = VALID_MOVE;
	if (!(_dest[0] > '8' || _dest[0] < '1' || _dest[1] < 'a' || _dest[1] > 'h'))
	{
		ans = ERROR_INDEX;
	}

	return ans;
}

/**
The function checks to see whether the other player has a second check on all possible moves of the 
second player if he can block the island
input: NONE
output: checkmate - '8'
*/
char Check::checkMate()
{
	char ans = CHECKMATE;
	int i = 0, j = 0;
	int x = 0, y = 0;
	string ans_conversion = "  ";
	string toolLocationTemp = _tool->getLocation();
	Tool* tempTool_test = _board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]];

	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(_dest);
	_board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]] = _board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]];
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = NULL;


	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			if (_board->getBoard()[j][i] != NULL)
			{
				if (_board->getBoard()[j][i]->getColor() != _turn)
				{
					for (x = 0; x < 8; x++)
					{
						for (y = 0; y < 8; y++)
						{
							ans_conversion = conversion(x, y);
							ans = _board->getBoard()[j][i]->move(ans_conversion, *_board, _turn == 0 ? 1 : 0);
							if (ans == VALID_MOVE)
							{
								break;
							}
						}
						if (ans == VALID_MOVE)
						{
							break;
						}
					}
				}
			}
			if (ans == VALID_MOVE)
			{
				break;
			}
		}
		if (ans == VALID_MOVE)
		{
			break;
		}
		
	}

	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]] = _board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]];
	_board->getBoard()[Tool::conversion(_dest)[WIDTH]][Tool::conversion(_dest)[LENGTH]] = tempTool_test;
	_board->getBoard()[Tool::conversion(toolLocationTemp)[WIDTH]][Tool::conversion(toolLocationTemp)[LENGTH]]->setLocation(toolLocationTemp);
	if (ans != VALID_MOVE)
	{
		ans = CHECKMATE;
	}
	
	return ans;
}

/**
The function converts from position to array to board
input: the width and the length
output: the position
*/
string Check::conversion(int width, int length)
{
	string ans = "  ";

	switch (width)
	{
	case 0:
		ans[1] = '8';
		break;
	case 1:
		ans[1] = '7';
		break;
	case 2:
		ans[1] = '6';
		break;
	case 3:
		ans[1] = '5';
		break;
	case 4:
		ans[1] = '4';
		break;
	case 5:
		ans[1] = '3';
		break;
	case 6:
		ans[1] = '2';
		break;
	case 7:
		ans[1] = '1';

	default:
		break;
	}

	ans[0] = char(length) + 97;

	return ans;
}