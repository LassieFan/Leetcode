/*
	����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
#include<iostream>
using namespace std;

//ֱ����ÿһλ��1��
int GetNum1(int n)
{
	int sum = 0;
	int i = 0;
	while (i != 32)
	{
		if ((n&(1 << i) )!= 0)
			sum++;
		i++;
	}
	return sum;
}

//��n��n-1��
int GetNum2(int n)
{
	int sum = 0;
	while (n != 0)
	{
		n &= (n - 1);
		sum++;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	cout << GetNum1(n) << endl;
	cout << GetNum2(n) << endl;
	
	system("pause");
	return 0;
}