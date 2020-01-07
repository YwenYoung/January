//注明的汉诺塔问题，Tower of Hanoi
#include <iostream>
using namespace std;

void towers(int, int, int, int);

int main()
{
	int nDisks;

	cout << "Enter the starting number of disks: ";
	cin >> nDisks;

	towers(nDisks, 1, 3, 2);
	return 0;
}

void towers(int disks, int start, int end, int temp)
{
	if (disks == 1)
		cout << start << " --> " << end << '\n';
	else
	{
		towers(disks - 1, start, temp, end);
		cout << start << " --> " << end << '\n';
		towers(disks - 1, temp, end, start);
	}
}