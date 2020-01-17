#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
//对一维数组进行由大到小（或者由小到达）冒泡排序
int main()
{
	/*		第一种排序法，
	const int arraySize = 10;
	array <int, arraySize> a = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	int hold;

	cout << "Data items in original order\n";

	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

	for (int pass = 0;pass<arraySize-1;pass++)
	{
		for (int j=0;j<arraySize-1;j++)
		{
			if (a[j]>a[j+1])		// a[j]<a[j+1]  如果是要由小到大的排序，就用小于号
			{
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
	cout << "\nData items in ascending order\n";

	for (int k = 0; k < arraySize; k++)
		cout << setw(4) << a[k];

	cout << endl;
	return 0;
	*/


	/*
	//第二种排序法，每次排序都会减少掉最大值，下次排序就不需要让本次排出的最大值参与，所以相比第一种排序法效率更高
	const int arraySize = 10;
	array<int, arraySize> b = { 2,6,4,8,10,12,89,68,45,37 };
	int hold;
	int numberOfComp = 0;
	int comp;

	cout << "Data items in original order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << b[i];
	cout << "\n\n";

	for (int pass = 1; pass < arraySize; pass ++ )
	{
		cout << "After pass " << pass - 1 << ": ";
		for (comp = 0; comp < arraySize - pass; comp++)
		{
			numberOfComp++;
			if (b[comp] > b[comp + 1])
			{
				hold = b[comp];
				b[comp] = b[comp + 1];
				b[comp + 1] = hold;
			}
			cout << setw(3) << b[comp];
		}
		cout << setw(3) << b[comp] << '\n';
	}
	cout << "\nData items in ascending order\n";
	for (int j = 0; j < arraySize; j++)
		cout << setw(4) << b[j];

	cout << "\nNumber of comparisons = " << numberOfComp << endl;
	return 0;
	*/


	//第三种排序法，判断两个数是否相等，如果相等就不需要调换
	const int arraySize = 10;
	array<int, arraySize> c = { 6,4,2,8,10,12,37,45,68,89 };
	int hold;
	int numberOfComp = 0;
	int comp = 0;
	bool swapCheck = true;

	cout << "Data items in original order\n";

	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << c[i];

	cout << "\n\n";

	for (int pass = 1; pass < arraySize - 1 && swapCheck == true; pass++)
	{
		cout << "After pass " << pass - 1 << ": ";
		swapCheck = false;

		for (int comp = 0; comp < arraySize - pass; comp++)
		{
			numberOfComp++;
			if (c[comp] > c[comp + 1])
			{
				hold = c[comp];
				c[comp] = c[comp + 1];
				c[comp + 1] = hold;
				swapCheck = true;		//这里是关键！判断两个相邻的数是否相等
			}
			cout << setw(3) << c[comp];
		}
		cout << setw(3) << c[comp] << '\n';
	}
	cout << "\nData items in ascending order\n";

	for (int q = 0; q < arraySize; q++)
		cout << setw(4) << c[q];

	cout << "\nNumber of comparisons = " << numberOfComp << endl;
	return 0;
}