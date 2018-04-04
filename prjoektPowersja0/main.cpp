#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include<string>
#include"Board.h"
#include"Player.h"
#include"User.h"

using namespace std;

static const int sizeB = 10;

int main()
{
	
	Board* board = new Board(sizeB);
	User* userX = new User('X', board);
	User* userO = new User('O', board);
	
	string move;
	cout << "\n";
	board->makeBoard();
	while(true)
	{
		cout << "Ruch gracza 'O',wybierz pole \n";
		cin >> move;
		userO->makeMove(move);
		cout << "Ruch gracza 'X', podaj kolumne: \n";
		cin >> move;
		userX->makeMove(move);
	}
	delete board;
	delete userX;
	delete userO;
    return 0;
}

