/*
	���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
	������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
	�ݹ飬����ſ�ȼ�2������ſ�ȼ�1
*/

#include<iostream>
using namespace std;
int MethodCount(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
		return MethodCount(n - 1) + MethodCount(n - 2);
}
int main()
{
	int n;	//����εĿ�
	cin >> n;
	cout << MethodCount(n) << endl;
	return 0;
}