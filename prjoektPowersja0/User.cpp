#include "stdafx.h"
#include "User.h"

User::~User()
{
}

void User::makeMove(string x)
{
	this->board->writeMove(x, this->sign);
}