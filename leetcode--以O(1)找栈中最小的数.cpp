#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

/*
	����ջ�Ľṹ���ڸ�ջ�п���ʵ�ֵ���min�ҵ���Сֵ��ʱ�临�Ӷ�O(1)
	���帨��ջ��ÿ��pushʱ����֮ǰ��Сֵ���бȽϣ������֮ǰ��СֵС���ͽ���ǰֵѹ�븨��ջ�У���֮ѹ����Сֵ
	����ֱ����һ����С��������Ϊ����Сֵ��ջ�󣬴�Сֵû�а취��ȡ����
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
	stack<int> s_data;      //����ջ
	stack<int> m_data;      //����ջ
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