#include <iostream>
using namespace std;

/*
	快乐数,各个位平方和是否等于1，如果死循环就输出false，反之为1输出true
	类似快慢指针，如果死循环最后肯定会相遇到一个数
	如果是1最后也会相遇到1，根据这个特性写
*/

int Sum(int m) {
	int m_sum = 0;
	while (m != 0) {
		m_sum += (m % 10)*(m % 10);
		m /= 10;
	}
	return m_sum;
}

bool Judge(int n)
{
	int fast = n;
	int slow = n;
	do {
		slow = Sum(slow);
		fast = Sum(fast);
		fast = Sum(fast);
	} while (slow != fast);

	if (fast == 1)
		return true;
	else return false;
}


int main()
{
	int m;
	int tmp;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (Judge(tmp))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}