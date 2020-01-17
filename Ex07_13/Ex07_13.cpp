#include <iostream>
#include <array>
using namespace std;
//利用一个一维array对象解决以下问题。读入20个数，每个数在10~100之间（包括10和100）。在读入每个数时，确认这个数的有效性，并且若他和之前读入的数不一样，就把它存储到array对象中。
//读完所有的数之后，仅显示用户输入的不同的数值。假设“最糟糕的情况”是这20个数都不相同。请尽量用最小的array对象解决这个问题。
int main()
{
	const int arraySize = 20;
	array<int, arraySize> t = {};		//定义数组t并且初始化各元素为0
	int subscript = 0;	//译：下标参数
	int duplicate;		//译：副本参数
	int value;			//译：输入的值

	cout << "Enter 20 integers between 10 and 100:\n";

	for (int i=0;i<arraySize; )			//当条件表达式不存在时，它被假设为真。您也可以设置一个初始值和增量表达式，但是一般情况下，C++ 程序员偏向于使用 for(;;) 结构来表示一个无限循环。
	{
		duplicate = 0;
		cin >> value;
		
		if (value >= 10 && value <= 100)
		{
			for (int j = 0; j < subscript; j++)
			{
				if (value == t[j])
				{
					duplicate = 1;
					break;
				}
			}
			if (!duplicate)
			{
				t[subscript++] = value;
				i++;
			}
			else
				cout << "Duplicate number.\n";
		}
		else
			cout << "Invalid number.\n";
	}
	cout << "\nThe nonduplicate values are:\n";

	for (int i = 0; i < arraySize; i++)
		cout << t[i] << ' ';

	cout << endl;
	return 0;
}