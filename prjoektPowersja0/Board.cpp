#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->sizeBoard = 0;
	this->board = NULL;
}

Board::Board(int size = 5)
{
	this->sizeBoard = size;
	char boardSignJ, boardSignI;
	boardSignJ = 64;
	boardSignI = 48;
	this->board = new char *[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			if (i == 0)
			{
				this->board[0][j] = boardSignJ;
				boardSignJ++;
			}
			if (j == 0)
			{
				this->board[i][0] = boardSignI;
				boardSignI++;
			}
			if (((j != 0) && (i != 0)) || ((j == 0) && (i == 0)))
			{
				this->board[i][j] = '-';
			}
		}
	}
}

void Board::writeMove(string x, char sign)
{
	system("cls");
	try {
		Move move = this->parseMove(x);
		this->board[move.column][move.row] = sign;
		cout << "\n";
	}
	catch (const char* exception) {
		cout << exception << endl;
	}
	
	this->makeBoard();
}

Move Board::parseMove(string moveStr)
{
	char column = moveStr[0];
	char row = moveStr[1];


	if (isdigit(row) && isalpha(column))
	{

		Move move;
		move.row = toupper(moveStr[0]) - 64;
		move.column = moveStr[1] - 48;
	
		if (move.row >= sizeBoard || move.column >= sizeBoard || board[move.column][move.row] != '-')
			throw "Nieprawidlowy ruch. Tracisz kolejke kurwo";

		return move;
	}
	throw  "Nieprawidlowy ruch. Tracisz kolejke kurwo";
}

void Board::makeBoard()
{
	for (int i = 0; i < sizeBoard; i++)
	{
		for (int j = 0; j < sizeBoard; j++)
		{
			cout << this->board[i][j] << "\t";
		}
		cout << endl;
	}
}

Board::~Board()
{
	for (int i(0); i < sizeBoard; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	board = NULL;
}
