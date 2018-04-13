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

void Board::writeMoveP(string x, char sign)
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

	for (int a = 1; a <= (sizeBoard - 1); a++)
	{
		for (int b = 1; b <= (sizeBoard - 5); b++)
		{

			if (((board[a][b] == sign) && (board[a][b + 1] == sign) && (board[a][b + 2] == sign) && (board[a][b + 3] == sign) && (board[a][b + 4] == sign))
				|| ((board[b][a] == sign) && (board[b + 1][a] == sign) && (board[b + 2][a] == sign) && (board[b + 3][a] == sign) && (board[b + 4][a] == sign)))
			{
				cout << "Wygral gracz " << sign << endl;
				system("pause");
				exit(0);
			}
		}
	}

	for (int a = 1; a <= (sizeBoard - 5); a++)
	{
		for (int b = 1; b <= (sizeBoard - 5); b++)
		{
			if (((board[a][b] == sign) && (board[a + 1][b + 1] == sign) && (board[a + 2][b + 2] == sign) && (board[a + 3][b + 3] == sign) && (board[a + 4][b + 4] == sign))
				|| ((board[a][sizeBoard - b] == sign) && (board[a + 1][sizeBoard - 1 - b] == sign) && (board[a + 2][sizeBoard - 2 - b] == sign) && (board[a + 3][sizeBoard - 3 - b] == sign) && (board[a + 4][sizeBoard - 4 - b] == sign)))
			{
				cout << "Wygral gracz " << sign << endl;
				system("pause");
				exit(0);
			}
		}
	}

	int fields;
	fields = (sizeBoard - 1)*(sizeBoard - 1);
	for (int a = 1; a < sizeBoard; a++)
	{
		for (int b = 1; b < sizeBoard; b++)
		{
			if (board[a][b] != '-')
			{
				fields--;
				if (fields == 0)
				{
					cout << "Remis" << endl;
					system("pause");
					exit(0);
				}
			}
		}
	}
}

void Board::writeMoveB(string x, char sign)
{
	system("cls");
	srand((unsigned int)time(NULL));
	int move_row = toupper(x[0]) - 64 + ((rand() % 3) - 1);
	int move_column = x[1] - 48 + ((rand() % 3) - 1);
	cout << endl;
	
	while ((move_row <= 0) || (move_column <= 0) || (board[move_row][move_column] != '-') || (move_row > (sizeBoard-1)) || (move_column > (sizeBoard-1)))
	{
		move_row = toupper(x[0]) - 64 + ((rand() % 3) - 1);
		move_column = x[1] - 48 + ((rand() % 3) - 1);
	}
	this->board[move_row][move_column] = sign;
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
			throw "Nieprawidlowy ruch. Tracisz kolejke";

		return move;
	}
	throw  "Nieprawidlowy ruch. Tracisz kolejke";
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
