#include <iostream>
#include <array>
using namespace std;
//����һ��һάarray�������������⡣����20������ÿ������10~100֮�䣨����10��100�����ڶ���ÿ����ʱ��ȷ�����������Ч�ԣ�����������֮ǰ���������һ�����Ͱ����洢��array�����С�
//�������е���֮�󣬽���ʾ�û�����Ĳ�ͬ����ֵ�����衰���������������20����������ͬ���뾡������С��array������������⡣
int main()
{
	const int arraySize = 20;
	array<int, arraySize> t = {};		//��������t���ҳ�ʼ����Ԫ��Ϊ0
	int subscript = 0;	//�룺�±����
	int duplicate;		//�룺��������
	int value;			//�룺�����ֵ

	cout << "Enter 20 integers between 10 and 100:\n";

	for (int i=0;i<arraySize; )			//���������ʽ������ʱ����������Ϊ�档��Ҳ��������һ����ʼֵ���������ʽ������һ������£�C++ ����Աƫ����ʹ�� for(;;) �ṹ����ʾһ������ѭ����
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