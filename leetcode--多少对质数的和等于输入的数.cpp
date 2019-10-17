/*
	����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
	�磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10,�ֱ�Ϊ(5,5),(3,7)��
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

//ֱ�Ӵ�n-1��n/2ȥ�ж��Ƿ�����������
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