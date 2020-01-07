#include <iostream>
using namespace std;

template <class T>				//函数模板的作用：1、一种特殊的函数可用不同类型进行调用 ！  2、看起来和普通函数很相似，区别是类型可被参数化 ！
T min(T value1, T value2)		//T就是被参数化了的类型，在后面可以用各种不同的类型直接替换T ！
{
	if (value1 < value2)
		return value1;
	else
		return value2;
}

int main()
{
	int int1;
	int int2;

	cout << "Input two integer values: ";
	cin >> int1 >> int2;
	cout << "The smaller integer value is: " << min(int1, int2);

	char char1;
	char char2;

	cout << "\n\nInput two characters: ";
	cin >> char1 >> char2;
	cout << "The smaller character value is: " << min(char1, char2);

	double double1;
	double double2;

	cout << "\n\nInput two double values: ";
	cin >> double1 >> double2;
	cout << "The smaller double value is: " << min(double1, double2) << endl;

	return 0;
}