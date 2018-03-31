#include "stdafx.h"
#include "Player.h"

Player::Player(char sign, Board* board)
{
	this->board = board;
	this->sign = sign;
}

Player::~Player()
{
}
