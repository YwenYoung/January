#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice();

int main()
{
	enum Outcome { CONTINUE, WIN, LOSE };

	const int SIZE = 22;
	const int ROLLS = 10000;
	int gameStatus, sum, myPoint, roll;
	int length = 0;
	int wins[SIZE] = { 0 };
	int losses[SIZE] = { 0 };
	int winSum = 0;
	int loseSum = 0;

	srand(time(0));

	for (int i = 1; i <= ROLLS; i++)
	{
		sum = rollDice();
		roll = 1;

		switch (sum)
		{
		case 7: case 11:
			gameStatus = WIN;
			break;
		case 2:case 3: case 12:
			gameStatus = LOSE;
			break;
		default:
			gameStatus = CONTINUE;
			myPoint = sum;
			break;
		}

		while (gameStatus == CONTINUE)
		{
			sum = rollDice();
			roll++;
			if (sum == myPoint)
				gameStatus = WIN;
			else if (sum == 7)
				gameStatus = LOSE;
		}

		if (roll > 21)
			roll = 21;

		if (gameStatus == WIN)
		{
			wins[roll]++;
			winSum++;
		}
		else
		{
			losses[roll]++;
			loseSum++;
		}
	}

	cout << "Games won or lost after the 20th roll" << "\nare displayed as the 21st roll.\n\n";

	for (int z = 1; z <= 21; z++)
		cout << setw(3) << wins[z] << " games won and " << setw(3) << losses[z] << " games lost on roll " << z << '\n';

	cout << fixed << showpoint << "\nThe chances of winning are " << winSum << " / " << winSum + loseSum << " = " << setprecision(2) << 100.0*winSum / (winSum + loseSum) << "%\n";

	for (int k = 1; k <= 21; k++)
		length += wins[k] * k + losses[k] * k;

	cout << "The average game length is " << setprecision(2) << length / 10000.0 << " rolls." << endl;

	return 0;
}

int rollDice()
{
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	return die1 + die2;
}