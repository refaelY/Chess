#include "Manager.h"
#include "Pipe.h"
#include <iostream>
#include <thread>

#define EXIT "quit"

#define INITIAL_BOARD "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0"

/**Ctor*/
Manager::Manager(Tool*** board) : _white(Player(0)), _black(Player(1)), _board(board)
{
	
}

/**Dtor*/
Manager::~Manager()
{}

/**
This function manages the entire game
*/
void Manager::general()
{
	_turn = 0;
	srand(time_t(NULL));
	Pipe p;
	bool isConnect = p.connect();
	int* conversion_src;
	char ans = '0';
	char ans_to_send[2];
	int ans1 = 0;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans1;

		if (ans1 == 0)
		{
			cout << "trying connect again.." << endl;
			//Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, INITIAL_BOARD);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	_board.printBoard();
											  // get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != EXIT)
	{
		string src = "  ", dest = "  ";
		src[0] = msgFromGraphics[0];
		src[1] = msgFromGraphics[1];
		dest[0] = msgFromGraphics[2];
		dest[1] = msgFromGraphics[3];
		conversion_src = Tool::conversion(src);
		cout << "Move from: " << conversion_src[0] << " ," << conversion_src[1] << " To " << Tool::conversion(dest)[0] << " ," << Tool::conversion(dest)[1] << endl;
		
		if (_board.getBoard()[conversion_src[WIDTH]][conversion_src[LENGTH]] != NULL)
		{
			ans = _board.move(dest, _turn, conversion_src, _board.getBoard()[conversion_src[WIDTH]][conversion_src[LENGTH]]);
		}
		else
		{
			ans = ERROR_OTHER_PLAYER_TOOL;
		}
		
		ans_to_send[0] = ans;
		ans_to_send[1] = NULL;
		strcpy_s(msgToGraphics, ans_to_send);
		
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);
		_board.printBoard();

		if (ans == VALID_MOVE || ans == CHESS) //switch turn
		{
			_turn = _turn == 0 ? 1 : 0;
		}
		msgFromGraphics = p.getMessageFromGraphics();
	}

	//delete conversion_src;
	p.close();
}

