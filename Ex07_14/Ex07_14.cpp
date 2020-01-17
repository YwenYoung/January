/*
��һ���յ�vector����ʼ��ʹ������push_back������ÿ����ͬ��ֵ��ӵ����vector������
�����ҵ����ַ���
*/


//����һ
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int myints[] = { 1, 2, 3, 1, 1 };
	int len = sizeof(myints) / sizeof(int);
	vector<int> vec(myints, myints + len);
	set<int>s(vec.begin(), vec.end());
	vec.assign(s.begin(), s.end());
	for (int x : vec)
		cout << x << ", ";
	return 0;
}




/*
������
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int myints[] = {1,2,3,1,1};
	int len = sizeof(myints) / sizeof(int);
	vector<int> vec(myints, myints + len);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int x : vec)
		cout << x << ", ";
	return 0;
*/