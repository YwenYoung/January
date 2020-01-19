/*

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int SIZE = 8;

void clearBoard(int[][SIZE]);
void printBoard(const int[][SIZE]);
bool validMove(int, int, const int[][SIZE]);

int main()
{
	int board[SIZE][SIZE];
	int horizontal[SIZE] = { 2,1,-1,-2,-2,-1,1,2 };
	int vertical[SIZE] = { -1,-2,-2,-1,1,2,2,1 };
	int currentRow, currentColumn, moveNumber = 1, testRow, testColumn, moveType, done, goodMove;
	srand(time(0));
	clearBoard(board);
	currentRow = rand() % 8;
	currentColumn = rand() % 8;
	board[currentRow][currentColumn] = moveNumber++;
	done = false;

	while (!done)
	{
		moveType = 0;
		testRow = currentRow + vertical[moveType];
		testColumn = currentColumn + horizontal[moveType];
		goodMove = validMove(testRow, testColumn, board);

		if (goodMove)
		{
			currentRow = testRow;
			currentColumn = testColumn;
			board[currentRow][currentColumn] = moveNumber++;
		}
		else
		{
			for (int count = 0; count < SIZE - 1 && !goodMove; count++)
			{
				moveType = ++moveType % SIZE;
				testRow = currentRow + vertical[moveType];
				testColumn = currentColumn + horizontal[moveType];
				goodMove = validMove(testRow, testColumn, board);

				if (goodMove)
				{
					currentRow = testRow;
					currentColumn = testColumn;
					board[currentRow][currentColumn] = moveNumber++;
				}
			}

			if (!goodMove)
				done = true;
		}

		if (moveNumber - 1 == 64)
			done = true;
	}
	cout << "The tour ended with " << moveNumber - 1 << " moves.\n";

	if (moveNumber - 1 == 64)
		cout << "This was a full tour!\n\n";
	else
		cout << "This was not a full tour.\n\n";

	cout << "The board for this test is:\n\n";
	printBoard(board);
	return 0;
}

void clearBoard(int workBoard[][SIZE])
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
			workBoard[row][col] = 0;
	}
}

void printBoard(const int workBoard[][SIZE])
{
	cout << "    0   1   2   3   4   5   6   7\n";

	for (int row = 0; row < SIZE; row++)
	{
		cout << row;
		for (int col = 0; col < SIZE; col++)
			cout << setw(4) << workBoard[row][col];

		cout << '\n';
	}
	cout << endl;
}

bool validMove(int row, int column, const int workBoard[][SIZE])
{
	return (row >= 0 && row < SIZE&&column >= 0 && column < SIZE&&workBoard[row][column] == 0);
}

*/