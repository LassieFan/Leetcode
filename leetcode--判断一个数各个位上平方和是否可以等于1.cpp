#include <iostream>
using namespace std;

/*
	������,����λƽ�����Ƿ����1�������ѭ�������false����֮Ϊ1���true
	���ƿ���ָ�룬�����ѭ�����϶���������һ����
	�����1���Ҳ��������1�������������д
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