/*
	我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
	请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
	递归，横向放宽度减2，纵向放宽度减1
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
	int n;	//大矩形的宽
	cin >> n;
	cout << MethodCount(n) << endl;
	return 0;
}