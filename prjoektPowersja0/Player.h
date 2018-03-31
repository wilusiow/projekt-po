#pragma once
#include<iostream>
#include<string>
#include"Board.h"

using namespace std;

class Player
{
protected:
	Board * board;
	char sign;
public:
	Player(char sign, Board* board);
	virtual ~Player();
	virtual void makeMove(string x) = 0;

};

