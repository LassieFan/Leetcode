/*
	Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
	����һ��N�����������Ϊһ��Fibonacci����
	ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
	eg��3--��0
		4--��1
		12--��1
		15--��2
*/

#include<iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n < 1 || n>1000000)
		throw "error";
	int x = 0;
	int y = 1;
	int z;
	int min = 1;
	int max = 1;
	while (y < n)
	{
		z = x + y;
		x = y;
		min = y;
		y = z;
		max = z;
	}
	int p = n - min;
	int q = max - n;
	if (p < q)
		return p;
	else
		return q;
}
int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n);
	return 0;
}
