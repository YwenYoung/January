#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 8;

void clearBoard(int[][SIZE]);
void printBoard(const int[][SIZE]);
bool validMove(int, int, const int[][SIZE]);

int main()
{
	int board[SIZE][SIZE];
	int currentRow, currentColumn, moveNumber = 1;
	int access[SIZE][SIZE] =
	{
		2,3,4,4,4,4,3,2,
		3,4,6,6,6,6,4,3,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		3,4,6,6,6,6,4,3,
		2,3,4,4,4,4,3,2,
	};
	int testRow, testColumn, minRow, minColumn, minAccess = 9, accessNumber;
	int horizontal[SIZE] = { 2,1,-1,-2,-2,-1,1,2 };
	int vertical[SIZE] = { -1,-2,-2,-1,1,2,2,1 };
	bool done;
	srand(time(0));

	clearBoard(board);
	currentRow = rand() % 8;
	currentColumn = rand() % 8;
	board[currentRow][currentColumn] = moveNumber++;
	done = false;

	while (!done)
	{
		accessNumber = minAccess;

		for (int moveType = 0; moveType < SIZE; ++moveType)
		{
			testRow = currentRow + vertical[moveType];
			testColumn = currentColumn + horizontal[moveType];

			if (validMove(testRow, testColumn, board))
			{
				if (access[testRow][testColumn] < accessNumber)
				{
					accessNumber = access[testRow][testColumn];
					minRow = testRow;
					minColumn = testColumn;
				}
				access[testRow][testColumn]--;
			}
		}

		if (accessNumber == minAccess)
			done = true;
		else
		{
			currentRow = minRow;
			currentColumn = minColumn;
			board[currentRow][currentColumn] = moveNumber++;
		}
	}

	cout << "The tour ended with " << moveNumber - 1 << " moves.\n";

	if (moveNumber - 1 == 64)
		cout << "This was a full tour!\n";
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
	cout << "   0  1  2  3  4  5  6  7\n";
	for (int row = 0; row < SIZE; row++)
	{
		cout << row;
		for (int col = 0; col < SIZE; col++)
			cout << setw(3) << workBoard[row][col];

		cout << '\n';
	}
	cout << endl;
}

bool validMove(int row, int column, const int workBoard[][SIZE])
{
	return(row >= 0 && row < SIZE&&column >= 0 && column < SIZE&&workBoard[row][column] == 0);
}