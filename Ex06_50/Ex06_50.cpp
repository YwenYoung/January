//按值传递与按引用传递的区别

#include <iostream>
using namespace std;

int tripleByValue(int);
void tripleByReference(int &);

int main()
{
	int count;
	cout << "Enter a value for count: ";
	cin >> count;

	cout << "\nValue of count before call to tripleByValue() is: "
		<< count << "\nValue returned from tripleByValue() is: "
		<< tripleByValue(count)
		<< "\nValue of count (in main) after tripleCallByValue() is: "
		<< count;
	cout << "\n\nValue of count before call to tripleByReference() is: "
		<< count << endl;
	tripleByReference(count);
	cout<<"Value of count (in main) after call to "
		<< "tripleByReference() is: " << count << endl;
	system ("PAUSE");
	return 0;
}

int tripleByValue(int value)
{
	return value *= 3;
}

void tripleByReference(int &valueRef)
{
	valueRef *= 3;
}
//引用传递会改变值本身，而按值传递仅仅是拷贝一个值的副本，不会对值本身进行修改！！！