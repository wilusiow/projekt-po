#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include"Move.h"
using namespace std;
class Board
{
	int sizeBoard;
	char **board;
	Move parseMove(string moveStr);
public:
	Board(int);
	Board();
	~Board();
	void makeBoard();
	void writeMove(string x, char sign);
	
};

