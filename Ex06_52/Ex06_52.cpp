#include <iostream>
using namespace std;

template <class T>				//����ģ������ã�1��һ������ĺ������ò�ͬ���ͽ��е��� ��  2������������ͨ���������ƣ����������Ϳɱ������� ��
T min(T value1, T value2)		//T���Ǳ��������˵����ͣ��ں�������ø��ֲ�ͬ������ֱ���滻T ��
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