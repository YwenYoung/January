#include <iostream>
#include <iomanip>
using namespace std;

void wages(int[]);			//函数原型function prototype
void display(const int[]);	//函数原型function prototype

int main()
{
	int salaries[11] = {};
	cout << fixed << showpoint;
	wages(salaries);
	display(salaries);
	return 0;
}

void wages(int money[])
{
	double sales;
	double i = 0.09;
	cout << "Enter employee gross sales (-1 to end): ";
	cin >> sales;
}