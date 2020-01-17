#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
//��һά��������ɴ�С��������С���ð������
int main()
{
	/*		��һ�����򷨣�
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
			if (a[j]>a[j+1])		// a[j]<a[j+1]  �����Ҫ��С��������򣬾���С�ں�
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
	//�ڶ������򷨣�ÿ�����򶼻���ٵ����ֵ���´�����Ͳ���Ҫ�ñ����ų������ֵ���룬������ȵ�һ������Ч�ʸ���
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


	//���������򷨣��ж��������Ƿ���ȣ������ȾͲ���Ҫ����
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
				swapCheck = true;		//�����ǹؼ����ж��������ڵ����Ƿ����
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