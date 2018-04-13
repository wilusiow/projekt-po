#pragma once
#include "Player.h"
#include<iostream>
#include<string>
class Bot : public Player
{
public:
	Bot(char sign, Board* board) : Player(sign, board) {}
	~Bot();
	void makeMove(string x);
};

