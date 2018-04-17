#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->sizeBoard = 0;
	this->board = NULL;
}

Board::Board(int size = 17)
{
	this->sizeBoard = size;
	char boardSignJ, boardSignI;
	boardSignI = 65;
	boardSignJ = 49;
	this->board = new char *[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			if (i == 1 && j > 1)
			{
				this->board[i][j] = boardSignI;
				boardSignI++;
			}
			if ((j == 0) && (i > 10))
			{
				this->board[i][j] = 49;
			}
			if ((j == 0) && (i < 11))
			{
				this->board[i][j] = 48;
			}
			if (j == 1 && i != 0 && i != 1)
			{
				this->board[i][j] = boardSignJ;
				boardSignJ++;
				if (boardSignJ == 58)
				{
					boardSignJ -= 10;
				}
			}
			if (((j != 0 && j != 1) && (i != 0 && i != 1)) || ((j < 2) && (i == 1)))
			{
				this->board[i][j] = '-';
			}
			if (i == 0)
			{
				this->board[i][j] = ' ';
			}
		}
	}
}

void Board::writeMoveP(string x, char sign)
{
	system("cls");
	this->makeBoard();
	try {
		Move move = this->parseMove(x);
		this->board[move.column][move.row] = sign;
		cout << "\n";
	}
	catch (const char* exception) {
		cout << exception << endl;
	}
	Sleep(750);
	system("cls");
	this->makeBoard();
}

void Board::writeMoveB(string x, char sign)
{	
	int move_row, move_column;
	system("cls");
	this->makeBoard();
	srand((unsigned int)time(NULL));
	if (isdigit(x[1]) && isdigit(x[2]) && isalpha(x[0]))
	{

		Move move;
		move.row = toupper(x[0]) - 63;
		move.column = x[2] - 47;
		if (x[1] == '1')
		{
			move.column += 10;
		}
		clock_t begin_time = clock();
		float timeCounter=0.0;
		do
		{
			move_row = move.row + ((rand() % 3) - 1);
			move_column = move.column + ((rand() % 3) - 1);
			if ((float(clock() - begin_time - timeCounter) / CLOCKS_PER_SEC) > 3)
			{
				while ((move_row <= 1) || (move_column <= 1) || (move_row > (sizeBoard - 1)) || (move_column > (sizeBoard - 1)) || (board[move_column][move_row] != '-'))
				{
					for (int i = 2; i < sizeBoard; i++)
					{
						for (int j = 2; j < sizeBoard; j++)
						{
							if (board[i][j] == '-')
							{
								move_row = j;
								move_column = i;
								break;
							}
						}
						if (board[move_column][move_row] == '-') break;
					}
				}
			}
		} while ((move_row <= 1) || (move_column <= 1) || (move_row > (sizeBoard - 1)) || (move_column > (sizeBoard - 1)) || (board[move_column][move_row] != '-'));
		this->board[move_column][move_row] = sign;
		system("cls");
		this->makeBoard();
	}
}

Move Board::parseMove(string moveStr)
{
	char column = moveStr[0];
	char row10 = moveStr[1];
	char row1 = moveStr[2];

	if (isdigit(row10) && isdigit(row1) && isalpha(column))
	{

		Move move;
		move.row = toupper(moveStr[0]) - 63;
		move.column = moveStr[2] - 47;
		if (row10 == '1')
		{
			move.column += 10;
		}

		if (move.row >= sizeBoard || move.column >= sizeBoard || board[move.column][move.row] != '-')
			throw "Nieprawidlowy ruch. Tracisz kolejke.";
			
		return move;
	}

	throw  "Nieprawidlowy ruch. Tracisz kolejke.";
}

void Board::makeBoard()
{
	for (int i = 1; i < sizeBoard; i++)
	{
		for (int j = 0; j < sizeBoard; j++)
		{
			if (j == 0)
			{
				cout << this->board[i][j] << "";
			}
			else
			{
				cout << this->board[i][j] << "\t";
			}
		}
		cout << "\n\n\n";
	}
}

bool Board::winOrTie(char sign)
{
	for (int a = 2; a <= (sizeBoard - 1); a++)
	{
		for (int b = 2; b <= (sizeBoard - 5); b++)
		{

			if (((board[a][b] == sign) && (board[a][b + 1] == sign) && (board[a][b + 2] == sign) && (board[a][b + 3] == sign) && (board[a][b + 4] == sign))
				|| ((board[b][a] == sign) && (board[b + 1][a] == sign) && (board[b + 2][a] == sign) && (board[b + 3][a] == sign) && (board[b + 4][a] == sign)))
			{
				cout << "Wygral gracz "<< sign << endl;
				return 1;
			}
		}
	}

	for (int a = 2; a <= (sizeBoard - 5); a++)
	{
		for (int b = 2; b <= (sizeBoard - 5); b++)
		{
			if (((board[a][b] == sign) && (board[a + 1][b + 1] == sign) && (board[a + 2][b + 2] == sign) && (board[a + 3][b + 3] == sign) && (board[a + 4][b + 4] == sign))
				|| ((board[a][sizeBoard - b] == sign) && (board[a + 1][sizeBoard - 1 - b] == sign) && (board[a + 2][sizeBoard - 2 - b] == sign) && (board[a + 3][sizeBoard - 3 - b] == sign) && (board[a + 4][sizeBoard - 4 - b] == sign)))
			{
				cout << "Wygral gracz " << sign << endl;
				return 1;
			}
		}
	}

	int fields;
	fields = (sizeBoard - 2)*(sizeBoard - 2);
	for (int a = 2; a < (sizeBoard-1); a++)
	{
		for (int b = 2; b < (sizeBoard-1); b++)
		{
			if (board[a][b] != '-')
			{
				fields--;
				if (fields == 0)
				{
					cout << "Remis" << endl;
					return 1;
				}
			}
		}
	}
	return 0;
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
