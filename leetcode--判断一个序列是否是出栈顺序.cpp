#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
	输入两个整数序列，第一个序列表示栈的压入顺序，判断第二个序列是否可能为该栈的弹出顺序。
	用一个辅助栈，根据出栈序列元素，先将入栈序列的出栈元素之前的入到辅助栈中，然后出栈，再去找出栈序列的之后的元素，继续入栈
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
				if (j == len)    //所要出栈的可能已经在栈中了，但是不在栈顶，就无法读取到，要将后续一直放入
					break;
				s.push(pushV[j++]);
			}
			if (s.top() != popV[i])     //输入完了，都没有输出的元素,对应j=len
				return false;
			s.pop();
			i++;
		}
		if (s.empty() && i == len)
			return true;
		return false;
	}
};