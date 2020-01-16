#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
//对一维数组进行由大到小（或者由小到达）冒泡排序
int main()
{
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
}