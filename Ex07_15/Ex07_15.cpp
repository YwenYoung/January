#include <iostream>
#include <array>
using namespace std;

int main()
{
	const int column = 5;
	const int row = 3;
	array<array<int, column>, row> t = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	for (size_t row = 0; row < t.size(); ++row)
		for (size_t column = 0; column < t[row].size(); ++column)
		{
			//t[row][column] = 0;
			cout << t[row][column] << endl;
		}
}