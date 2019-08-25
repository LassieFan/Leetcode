#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
	���������������У���һ�����б�ʾջ��ѹ��˳���жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
	��һ������ջ�����ݳ�ջ����Ԫ�أ��Ƚ���ջ���еĳ�ջԪ��֮ǰ���뵽����ջ�У�Ȼ���ջ����ȥ�ҳ�ջ���е�֮���Ԫ�أ�������ջ
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		
		int len = pushV.size();
		if (len == 0)
			return false;

		stack<int> s;
		int i = 0;
		int j = 0;
		while (i<len)
		{
			while (s.empty() || s.top() != popV[i])
			{
				if (j == len)    //��Ҫ��ջ�Ŀ����Ѿ���ջ���ˣ����ǲ���ջ�������޷���ȡ����Ҫ������һֱ����
					break;
				s.push(pushV[j++]);
			}
			if (s.top() != popV[i])     //�������ˣ���û�������Ԫ��,��Ӧj=len
				return false;
			s.pop();
			i++;
		}
		if (s.empty() && i == len)
			return true;
		return false;
	}
};