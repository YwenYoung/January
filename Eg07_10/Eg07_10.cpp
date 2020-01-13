//用array对象元素当做计数器使用
#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int>randomInt(0, 6);

	const size_t arraySize = 7;
	array<unsigned int, arraySize> frequency = {};

	for (unsigned int roll = 1; roll <= 6000000; ++roll)
		++frequency[randomInt(engine)];

	cout << "Face" << setw(13) << "Frequency" << endl;

	for (size_t face = 0; face < frequency.size(); ++face)
		cout << setw(4) << face << setw(13) << frequency[face] << endl;
}