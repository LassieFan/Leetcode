/*
	����һ������X���������rev(X)Ϊ��X����λ��ת����������ȥ����ǰ��0������:
	��� X = 123����rev(X) = 321;
	��� X = 100����rev(X) = 1.
	���ڸ�������x��y,Ҫ��rev(rev(x) + rev(y))Ϊ���٣�
*/

#include<iostream>
using namespace std;
int Overturn(int n)
{
	int sum = 0;
	int m = n % 10;
	while ((n /= 10) != 0)
	{
		sum += m;
		sum *= 10;
		m = n % 10;
	}
	sum += m;
	return sum;
}
int End(int n, int m)
{
	if (n < 1 || m < 1 || n>1000 || m>1000)
		throw "error";
	return Overturn(Overturn(n) + Overturn(m));
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	cout << End(n, m);
	return 0;
}
