/*
	Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
	给你一个N，你想让其变为一个Fibonacci数，
	每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
	eg：3--》0
		4--》1
		12--》1
		15--》2
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
