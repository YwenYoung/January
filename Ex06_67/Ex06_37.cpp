#include <iostream>
using namespace std;

int fibonacci(int);

int main()
{
	for (int counter = 0; counter <= 10; counter++)
		cout << "fibonacci( " << counter << " ) = " << fibonacci(counter) << endl;

	cout << "fibonacci(20) = " << fibonacci(20) << endl;
	return 0;
}

int fibonacci(int n)
{
	int fib0 = 0;
	int fib1 = 1;
	int temp;

	if (n == 0)
		return 0;

	for (int i = 2; i <= n; i++)
	{
		temp = fib1;
		fib1 = fib0 + fib1;
		fib0 = temp;
	}
	return fib1;
}