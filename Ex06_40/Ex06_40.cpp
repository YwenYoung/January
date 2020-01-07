//递归问题可视化处理，Visualizing Recursion

#include <iostream>
using namespace std;
#include <iomanip>

unsigned long factorial(unsigned long);

int main()
{
	for (int i = 0; i <= 10; i++)
		cout << setw(2) << i << "! = " << factorial(i) << endl;
	return 0;
}

unsigned long factorial(unsigned long number)
{
	if (number<=1)
	{
		cout << " Reached base case of 1" << endl;
		return 1;
	}
	else
	{
		cout << setw(number * 3) << "" << "local variable number: " << number << endl;
		cout << setw(number * 3) << "" << "recursively calling factorial( " << number - 1 << " )" << endl << endl;
		return (number*factorial(number - 1));
	}
}