/*
	给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
	如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
*/

#include<iostream>
using namespace std;

bool IsPrime(int m)
{
	if (m <= 2)
		return false;
	for (int n = 2; n <= sqrt(m); n++)
	{
		if (m%n == 0)
			return false;
	}
	return true;
}

//直接从n-1到n/2去判断是否是质数即可
int CalCount(int n)
{
	int count = 0;
	int m = n - 1;
	while (m >= n / 2)
	{
		if (IsPrime(m))
		{
			if (IsPrime(n - m))
				count++;
		}
		m--;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << CalCount(n);
	return 0;
}