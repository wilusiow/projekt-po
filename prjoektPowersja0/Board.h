#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include"Move.h"
#include<cstdlib>
#include<ctime>
#include <time.h>
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
	void writeMoveP(string x, char sign);
	void writeMoveB(string x, char sign);
	bool winOrTie(char sign);
};

