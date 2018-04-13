#include "stdafx.h"
#include "Bot.h"

Bot::~Bot()
{
}

void Bot::makeMove(string x)
{
	this->board->writeMoveB(x, this->sign);
}