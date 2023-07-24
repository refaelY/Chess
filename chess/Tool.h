#pragma once
#include <string>
#include <iostream>
#include "Board.h"


#define SUM_OF_SLOTS 64
#define LINE 8

#define VALID_MOVE '0'
#define CHESS '1'
#define ERROR_OTHER_PLAYER_TOOL '2'
#define ERROR_DEST_SELF_POPULATED '3'
#define ERROR_SELF_CHESS '4'
#define ERROR_INDEX '5'
#define ERROR_INVALID_TOOL_MOVEMENT '6'
#define ERROR_SAME_DEST_AND_SRC '7'
#define CHECKMATE '8'

#define LENGTH 1
#define WIDTH 0


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Board;

class Tool
{
private:
	int _color;
	string _location;
	char _type;

public:
	Tool(const string, const char);
	int getColor() const;
	string getLocation() const;
	void setLocation(const string);
	char getType() const;
	static int* conversion(const string);
	char move(string dest, Board board, const int turn);
	virtual char invalidToolMovement(int* dest, Board board) = 0;

};