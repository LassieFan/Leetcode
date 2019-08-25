#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

/*
	定义栈的结构，在该栈中可以实现调用min找到最小值，时间复杂度O(1)
	定义辅助栈，每次push时，和之前最小值进行比较，如果比之前最小值小，就将当前值压入辅助栈中，反之压入最小值
	不能直接用一个最小变量，因为当最小值出栈后，次小值没有办法获取到了
*/

class Solution {
public:
	void push(int value) {
		s_data.push(value);
		if (m_data.empty())
			m_data.push(value);
		else
		{
			if (m_data.top() < value)
				m_data.push(m_data.top());
			else
				m_data.push(value);
		}
	}
	void pop() {
		if (!s_data.empty() && !m_data.empty())
		{
			s_data.pop();
			m_data.pop();
		}
	}
	int top() {
		if (!s_data.empty() && !m_data.empty())
			return s_data.top();
	}
	int min() {
		if (!s_data.empty() && !m_data.empty())
			return m_data.top();
	}
	stack<int> s_data;      //数据栈
	stack<int> m_data;      //辅助栈
};

int main()
{
	Solution *s = new Solution();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		s->push(tmp);
		cout << tmp << "  ";
	}
	cout << endl;
	cout<<s->min() << endl;
	for (int i = 0; i < 3; i++)
		s->pop();
	cout<<s->min()<<endl;
}