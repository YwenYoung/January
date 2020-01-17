#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const long ROLLS = 36000;
	const int SIZE = 13;

	int expected[SIZE] = { 0,0,1,2,3,4,5,6,5,4,3,2,1 };		//这个数组里的0和1应该是无效的，因为两个骰子之和最小应该也是2
	int x, y;
	int sum[SIZE] = { 0 };

	srand(time(0));
	for (long i = 0; i < ROLLS; i++)
	{
		x = 1 + rand() % 6;
		y = 1 + rand() % 6;
		sum[x + y]++;
	}
		cout << setw(10) << "Sum" << setw(10) << "Total" << setw(10) << "Expected" << setw(10) << "Actual\n" << fixed << showpoint;

		for (int j = 2; j < SIZE; j++)
			cout << setw(10) << j << setw(10) << sum[j] << setprecision(3) << setw(9)
			<< 100.0 * expected[j] / 36 << "%" << setprecision(3) << setw(9)
			<< 100.0 * sum[j] / 36000 << "%\n";
		return 0;
}