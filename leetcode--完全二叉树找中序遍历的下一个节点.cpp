#include <iostream>
#include <vector>
using namespace std;

//������ȫ�������Ĳ�α���˳���Լ�����Ҫ��Ѱ�ýڵ�Ԫ��ֵ
//�������ȫ��������Ҫ�ҵýڵ�������������һ���ڵ�
int NextNode(vector<int> vec, int num)
{
	int i = 0;
	for (; i < vec.size(); i++)
	{
		if (vec[i] == num) break;
	}
	return (i * 2 + 2) < vec.size() ? vec[i * 2 + 2] : -1;
}
int main()
{
	vector<int> vec;
	int tmp;
	cin >> tmp;
	vec.push_back(tmp);
	while (cin.get()!='\n')
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	int num;
	cin >> num;
	cout<<NextNode(vec, num);
}