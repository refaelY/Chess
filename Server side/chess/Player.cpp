#include "Player.h"

Player::Player(int color)
{
	_color = color;
}

Player::~Player()
{}

int Player::getColor()
{
	return _color;
}