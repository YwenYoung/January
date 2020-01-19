#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

bool queenCheck(const char[][8], int, int);
void placeQueens(char[][8]);
void printBoard(const char[][8]);
void xConflictSquares(char[][8], int, int);
void xDiagonals(char[][8], int, int);
bool availableSquare(const char[][8]);
inline int validMove(const char board[][8], int row, int col)
{
	return(row >= 0 && row < 8 && col >= 0 && col < 8);
}

int main()
{
	char board[8][8] = { '\0' };
	srand(time(0));
	placeQueens(board);
	printBoard(board);
	return 0;
}

bool availableSquare(const char board[][8])
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (board[row][col] == '\0')
				return false;
		}
	}
	return true;
}

void placeQueens(char board[][8])
{
	const char QUEEN = 'Q';
	int rowMove, colMove;
	int queens = 0;
	bool done = false;

	while (queens < 8 && !done)
	{
		rowMove = rand() % 8;
		colMove = rand() % 8;

		if (queenCheck(board, rowMove, colMove))
		{
			board[rowMove][colMove] = QUEEN;
			xConflictSquares(board, rowMove, colMove);
			queens++;
		}
		done = availableSquare(board);
	}
}

void xConflictSquares(char board[][8], int row, int col)
{
	for (int loop = 0; loop < 8; ++loop)
	{
		if (board[row][loop] == '\0')
			board[loop][col] = '*';
	}
	xDiagonals(board, row, col);
}

bool queenCheck(const char board[][8], int row, int col)
{
	int r = row;
	int c = col;

	for (int d = 0; d < 8; d++)
	{
		if (board[row][d] == 'Q' || board[d][col] == 'Q')
			return false;
	}

	for (int e = 0; e < 8 && validMove(board, --r, --c); e++)
	{
		if (board[r][c] == 'Q')
			return false;
	}
	r = row;
	c = col;

	for (int f = 0; f < 8 && validMove(board, --r, ++c); f++)
	{
		if (board[r][c] == 'Q')
			return false;
	}
	r = row;
	c = col;

	for (int g = 0; g < 8 && validMove(board, ++r, --c); g++)
	{
		if (board[r][c] == 'Q')
			return false;
	}
	r = row;
	c = col;

	for (int f = 0; f < 8 && validMove(board, --r, ++c); f++)
	{
		if (board[r][c] == 'Q')
			return false;
	}
	r = row;
	c = col;

	for (int g = 0; g < 8 && validMove(board, ++r, --c); g++)
	{
		if (board[r][c] == 'Q')
			return false;
	}
	r = row;
	c = col;

	for (int h = 0; h < 8 && validMove(board, ++r, ++c); h++)
	{
		if (board[r][c] == 'Q')
			return false;
	}

	return true;
}

void xDiagonals(char board[][8], int row, int col)
{
	int r = row, c = col;

	for (int a = 0; a < 8 && validMove(board, --r, --c); a++)
		board[r][c] = '*';
	r = row;
	c = col;

	for (int b = 0; b < 8 && validMove(board, --r, ++c); b++)
		board[r][c] = '*';
	r = row;
	c = col;

	for (int d = 0; d < 8 && validMove(board, ++r, --c); d++)
		board[r][c] = '*';
	r = row;
	c = col;

	for (int e = 0; e < 8 && validMove(board, ++r, ++c); e++)
		board[r][c] = '*';
}

void printBoard(const char board[][8])
{
	int queens = 0;
	cout << "   0 1 2 3 4 5 6 7\n";
	for (int r = 0; r < 8; r++)
	{
		cout << setw(2) << r << ' ';

		for (int c = 0; c < 8; c++)
		{
			cout << board[r][c] << ' ';

			if (board[r][c] == 'Q')
				queens++;
		}
		cout << '\n';
	}
	if (queens == 8)
		cout << "\nEight Queens were placed in the board!" << endl;
	else
		cout << '\n' << queens << " Queens were placed on the board.\n";
}