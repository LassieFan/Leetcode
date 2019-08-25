#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	给定两个版本号，只有右边版本号比左边版本号更高是才能升级成功
	版本号中只有数和.    一个版本最多有三个.
	eg：6.6.6  6.6.7     true
	eg：1 1.0   false    两个数一样大
*/

bool JudgeUp(string left, string right)
{
	vector<int>leftvec;
	vector<int>rightvec;

	int tmp = 0;
	for (int i = 0; i < left.length(); i++) 
	{
		if (left[i] == '.') 
		{
			leftvec.push_back(tmp);
			tmp = 0;
			continue;
		}
		tmp = 10 * tmp + (left[i] - '0');
	}
	leftvec.push_back(tmp);

	tmp = 0;
	for (int i = 0; i < right.length(); i++) 
	{
		if (right[i] == '.') {
			rightvec.push_back(tmp);
			tmp = 0;
			continue;
		}
		tmp = 10 * tmp + right[i] - '0';
	}
	rightvec.push_back(tmp);

	int leftlen = leftvec.size();
	int rightlen = rightvec.size();

	for (int i = 0; i < 3; i++) 
	{
		if (leftlen > i&&rightlen > i)     //判断是否小数点后还有数据，等于的到下一次循环去
		{
			if (leftvec[i] < rightvec[i]) 
			{
				return true;
			}
			if (leftvec[i] > rightvec[i]) 
			{
				return false;
			}
		}
		else if (leftlen > i) 
		{
			if (leftvec[i] > 0) 
			{
				return false;
			}
		}
		else if (rightlen > i)    //之前的数和left一样，后面只要数据有且不为0即可升级
		{
			if (rightvec[i] > 0)
			{
				return true;
			}
		}
	}
	return false;
}


int main()
{
	int n;
	cin >> n;
	string left; 
	string right;
	for (int i = 0; i < n; i++) 
	{
		cin >> left >> right;
		bool result = JudgeUp(left, right);
		if (result)
			cout << "true"<<endl;
		else
			cout << "false"<<endl;
	}
	return 0;
}
