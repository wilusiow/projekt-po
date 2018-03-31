#pragma once
#include "Player.h"
#include<iostream>
#include<string>

using namespace std;

class User : Player
{
public:
	User(char sign, Board* board): Player(sign, board){}
	~User();
	void makeMove(string x);
};

