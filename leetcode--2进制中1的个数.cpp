/*
	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
#include<iostream>
using namespace std;

//直接用每一位和1与
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

//用n和n-1与
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