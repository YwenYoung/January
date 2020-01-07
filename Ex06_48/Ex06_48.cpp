#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Status {WON, LOST, CONTINUE};		//enum 就是枚举，返回Status类型，并且返回的结果只能是{···}中的某一个

int rollDice(void);
Status craps(void);		//Status 就是 int （别名）
void chatter(void);

int main()
{
	Status result;
	int wager = 0;
	int bankBalance = 1000;
	char playAgain;

	srand(time(0));

	do {
		cout << "You have $" << bankBalance << " in the bank.\nPlace your wager: ";
		cin >> wager;

		while (wager<=0||wager>bankBalance)
		{
			cout << "Please bet a valid amount.\n";
			cin >> wager;
		}

		result = craps();

		if (result == LOST)
		{
			bankBalance -= wager;
			cout << "Your new bank balance is $" << bankBalance << "\n";

			if (bankBalance == 0)
			{
				cout << "Sorry. You Busted! Thank You For Playing.\n";
				break;
			}
		}
		else
		{
			bankBalance += wager;
			cout << "Your new bank balance is $" << bankBalance << "\n";
		}
		cout << "Would you like to try your luck again (y/n)?";
		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
	cout << endl;
	return 0;
}

int rollDice(void)
{
	int die1;
	int die2;
	int workSum;

	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	workSum = die1 + die2;

	cout << "Player rolled " << die1 << " + " << die2 << " = " << workSum << endl;
	return workSum;
}

Status craps(void)
{
	int sum;
	int myPoint;
	Status gameStatus;

	sum = rollDice();

	switch (sum)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;
		myPoint = sum;
		cout << "Point is " << myPoint << "\n";
		break;
	}

	while (gameStatus == CONTINUE)
	{
		chatter();
		sum = rollDice();

		if (sum==myPoint)
			gameStatus = WON;
		else
		{
			if (sum == 7)
				gameStatus = LOST;
		}
	}

	if (gameStatus == WON)
	{
		cout << "Player wins" << endl;
		return WON;
	} 
	else
	{
		cout << "Player loses" << endl;
		return LOST;
	}
}

void chatter()
{
	switch (rand()%9)
	{
	case 0:
		cout << "Oh, you're going for broke, huh?";
		break;
	case 1:
		cout << "Aw cmon, take a chance!";
		break;
	case 2:
		cout << "Hey, I think this guy is going to break the bank!!";
		break;
	case 3:
		cout << "You're up big. Now's the time to cash in your chips!";
		break;
	case 4:
		cout << "Way too lucky! Those dice have to be loaded!";
		break;
	case 5:
		cout << "Bet it all! Bet it all!";
		break;
	case 6:
		cout << "Can I borrow a chip?";
		break;
	case 7:
		cout << "Let's try our luck at another table.";
		break;
	case 8:
		cout << "You're a cheat! It is just a matter of time"<<"\nbefore I catch you!!!";
		break;
	}
	cout << endl;
}