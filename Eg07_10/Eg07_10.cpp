/*
//��array����Ԫ�ص���������ʹ��

#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int>randomInt(1, 6);

	const size_t arraySize = 7;
	array<unsigned int, arraySize> frequency = {};

	for (unsigned int roll = 0; roll < 6000000; ++roll)
		++frequency[randomInt(engine)];

	cout << "Face" << setw(13) << "Frequency" << endl;

	for (size_t face = 1; face < frequency.size(); ++face)
		cout << setw(4) << face << setw(13) << frequency[face] << endl;
}
*/

//��һ�����ԣ����ֻ��ڼ����������ĸ�ֵ�ͻ��ڷ�Χ�����ĸ�ֵ
#include <iostream>
#include <array>
using namespace std;

int main()
{
	const int i = 2;
	const int j = 3;

	array<array<int, j>, i> t = {};

	for (int m = 0; m < i; m++)
	{
		for (int n = 0; n < 3; n++)
		{
			t[m][n] = 1;

			cout << t[m][n] << ' ';
		}
		cout << '\n';
	}

	for (auto &row : t)
	{
		for (auto &column : row)
		{
			column = 2;

			cout << column << ' ';
		}
		cout << '\n';
	}

	for (int m = 0; m < i; m++)
	{
		for (int n = 0; n < 3; n++)
		{
			cout << t[m][n] << ' ';
		}
		cout << '\n';
	}

}