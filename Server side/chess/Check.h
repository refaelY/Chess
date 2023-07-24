#pragma once
#include "Tool.h"
#include <exception>
#include <string>
#include "Board.h"

using std::exception;
using std::string;

class Board;

class Check : public exception
{
private: 
	Tool* _tool;
	string _dest;
	int _turn;
	Board* _board;
	string conversion(int width, int length);

public:
	Check(const string dest, Tool* tool, const Board board, const int turn);
	~Check();
	char otherPlayerTool() const;
	char destSelfPopulated() const;
	char selfChess() const;
	char invalidIndex() const;
	char sameDestAndSrc() const;
	char checkMate(); //BONOS
	char chessCheck() const;
	
};