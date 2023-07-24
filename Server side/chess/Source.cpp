#include "Pipe.h"
#include <iostream>
#include <thread>
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Bishop.h"
#include "Player.h"

#define UP 0
#define DOWN 1

Tool*** createBoard();

using namespace std;
void main()
{
	int j = 0;
	Tool*** tools =  createBoard();
	Manager* m = new Manager(tools);
	m->general();

	for (j = 0; j < 8; j++)
	{
		delete tools[j];
	}
	delete tools;

}

/**
The fun is create the array of pointer of Tools
input: none
Output: the array
*/
Tool*** createBoard()
{
	int i = 0, j = 0;
	Tool*** tools = new Tool**[8];
	for (j = 0; j < 8; j++)
	{
		tools[j] = new Tool*[8];
	}
	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			tools[j][i] = NULL;
		}
	}

	tools[0][0] = new Rook("a8", 'R');
	tools[0][1] = new Knight("b8", 'N');
	tools[0][2] = new Bishop("c8", 'B');
	tools[0][3] = new King("d8", 'K');
	tools[0][4] = new Queen("e8", 'Q');
	tools[0][5] = new Bishop("f8", 'B');
	tools[0][6] = new Knight("g8", 'N');
	tools[0][7] = new Rook("h8", 'R');

	tools[1][0] = new Pawn("a7", 'P', DOWN);
	tools[1][1] = new Pawn("b7", 'P', DOWN);
	tools[1][2] = new Pawn("c7", 'P', DOWN);
	tools[1][3] = new Pawn("d7", 'P', DOWN);
	tools[1][4] = new Pawn("e7", 'P', DOWN);
	tools[1][5] = new Pawn("f7", 'P', DOWN);
	tools[1][6] = new Pawn("g7", 'P', DOWN);
	tools[1][7] = new Pawn("h7", 'P', DOWN);

	tools[7][0] = new Rook("a1", 'r');
	tools[7][1] = new Knight("b1", 'n');
	tools[7][2] = new Bishop("c1", 'b');
	tools[7][3] = new King("d1", 'k');
	tools[7][4] = new Queen("e1", 'q');
	tools[7][5] = new Bishop("f1", 'b');
	tools[7][6] = new Knight("g1", 'n');
	tools[7][7] = new Rook("h1", 'r');

	tools[6][0] = new Pawn("a2", 'p', UP);
	tools[6][1] = new Pawn("b2", 'p', UP);
	tools[6][2] = new Pawn("c2", 'p', UP);
	tools[6][3] = new Pawn("d2", 'p', UP);
	tools[6][4] = new Pawn("e2", 'p', UP);
	tools[6][5] = new Pawn("f2", 'p', UP);
	tools[6][6] = new Pawn("g2", 'p', UP);
	tools[6][7] = new Pawn("h2", 'p', UP);


	return tools;
}