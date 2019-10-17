/*
	对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
	如果 X = 123，则rev(X) = 321;
	如果 X = 100，则rev(X) = 1.
	现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？
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
