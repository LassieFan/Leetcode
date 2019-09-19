#include <iostream>
#include <vector>
using namespace std;
/*
	除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
*/


//一个二进制位只能表示0或者1，也就是天生可以记录一个数出现了一次还是两次，所以需要两个二进制位
//完成三个相同的元素异或的值为0   00->01->10->00 三次异或最终的答案是00即可
int singleNumber1(vector<int>& nums) 
{
	int a = 0;
	int b = 0;
	for (auto i : nums)
	{
		b = (b^i) & (~a);    //0 1 0 0
		a = (a^i) & (~b);	 //0 0 1 0
	}
	return b;
}

/*
	将数组中的每一个元素按照每一位拆分，所有元素的每一位之和肯定是3N或者3N+1
	若是3N，则证明唯一的那个元素这一位是0，反之这一位是1，记录起来
*/
int singleNumber2(vector<int>& nums) 
{
	int ret = 0;
	for (int i = 0; i < 32; i++) 
	{
		int mask = 1 << i;
		int cnt = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if ((nums[j] & mask) != 0) 
				cnt++;	
		}
		if (cnt % 3 != 0)		//如果出现4次则对4取余
		{
			ret |= mask;
		}
	}
	return ret;
}

int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	cout << singleNumber1(vec) << endl;
	cout << singleNumber2(vec) << endl;
}