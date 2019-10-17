/*
	给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
	例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
	针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
	{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
	{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxWindowSize(vector<int> vec, vector<int> &res, int winsize)
{
	//双端队列解决O(N)
	deque<int> d;
	for (int i = 0; i < vec.size(); i++)
	{
		while (d.size() && vec[d.back()] <= vec[i])  //和之前尾插入的元素比较，比尾大的将尾存放的出队
			d.pop_back();
		if (d.size() && i - d.front() >= winsize)   //将不是一组的队列中的大数出队
			d.pop_front();		//必须从头出，头的是最先失效的，反之尾部出了后头的可能不失效了
		d.push_back(i);
		if (winsize&&i + 1 >= winsize)
			res.push_back(vec[d.front()]);
	}
}

int main()
{
	int windowsize = 3;
	vector<int> vec(8);
	vector<int> res;
	vec[0] = 2;
	vec[1] = 3;
	vec[2] = 4;
	vec[3] = 2;
	vec[4] = 6;
	vec[5] = 2;
	vec[6] = 5;
	vec[7] = 1;
	maxWindowSize(vec, res, windowsize);
	//输出找到的每一组的最大值
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}