#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
	除了某个元素只出现一次(奇数次)以外，其余每个元素均出现两次（偶数次）。找出那个只出现了一次的元素。
*/

//用hash表存放，若hash中没有这个元素插入，有这个元素删除，最后剩下的是只出现一次的
int SingleNum1(vector<int>& vec)
{
	unordered_set<int> bset;
	for (int i = 0; i < vec.size(); i++)
	{
		if (bset.count(vec[i]))		//判断set中是否有这个元素，返回0/1
			bset.erase(vec[i]);
		else
			bset.insert(vec[i]);
	}
	return *(bset.begin());
}

//用双指针,先将数组元素排序，两两在一起，彼此不相等返回前一个
int SingleNum2(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	for (int i = 0, j = 1; j < vec.size(); i += 2, j += 2)
	{
		if (vec[i] != vec[j]) return vec[i];
	}
	return vec[vec.size()-1];		//奇数个元素，最后一个不匹配返回
}

//将全部数据异或，得到的结果就是只出现一次的
int SingleNum3(vector<int>& vec)
{
	int end = vec[0];
	for (int i = 1; i < vec.size(); i++)
		end ^= vec[i];
	return end;
}


int main()
{
	vector<int> vec(5, 0);
	vec[0] = 4;
	vec[1] = 2;
	vec[2] = 1;
	vec[3] = 1;
	vec[4] = 2;
	cout<<SingleNum1(vec)<<endl;
	cout << SingleNum2(vec) << endl;
	cout << SingleNum3(vec) << endl;
}