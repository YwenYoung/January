#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const int SIZE = 1000;
	int array[SIZE];
	int count = 0;

	for (int k = 0; k < SIZE; k++)
		array[k] = 1;

	for (int i = 1; i < SIZE; i++)
	{
		if (array[i] == 1 && i != 1)
		{
			for (int j = i; j <= SIZE; j++)
			{
				if (j%i == 0 && j != i)
					array[i] = 0;
			}
		}
	}
	for (int q = 2; q < SIZE; q++)
	{
		if (array[q] == 1)
		{
			cout << setw(3) << q << " is a prime number.\n";
			count++;
		}
	}

	cout << "A total of " << count << " prime numbers were found." << endl;
	return 0;
}