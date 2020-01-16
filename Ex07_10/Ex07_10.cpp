#include <iostream>
#include <iomanip>
using namespace std;

void wages(int[]);			//����ԭ��function prototype
void display(const int[]);	//����ԭ��function prototype��Ϊʲô�����������Ҫ��const������

int main()
{
	int salaries[11] = {};
	cout << fixed << showpoint;
	wages(salaries);
	return 0;
}

void wages(int money[])
{
	double sales;
	double i = 0.09;
	cout << "Enter employee gross sales (-1 to end): ";
	cin >> sales;

	while (sales != -1)
	{
		double salary = 200.0 + sales * i;
		cout << setprecision(2) << "Employee Commission is $" << salary << '\n';
		int x = static_cast<int>(salary) / 100;
		money[(x < 10 ? x : 10)]++;			//��¼�˲�ͬ����ȼ��ĸ���
		cout << "\nEnter employee gross sales (-1 to end): ";
		cin >> sales;
	}
}

void display(const int dollars[])
{
	cout << "Employee in the range: ";

	for (int n = 2; n < 10; n++)
		cout << "\n$" << n << "00-$" << n << "99 : " << dollars[n];

	cout << "\nOver $1000: " << dollars[10] << endl;
}