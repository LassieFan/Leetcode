#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//找到数组中所有三个数之和是0的不重复的组合
//先将数组排序，二个指针第一个指针固定往后遍历

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;     //存放结果的vector
		std::sort(nums.begin(),nums.end());
		if (nums.empty() || nums.front() > 0 || nums.back() < 0)
			return {};

		for (int i = 0; i < nums.size(); i++)
		{
			int fix = nums[i];
			if (fix > 0) break;
			if (i > 0 && fix == nums[i - 1]) continue;    //两个数相同，去除重复
			int l = i + 1;       //i数组元素的后绪指针，第二个加数
			int r = nums.size()-1;       //数组尾指针，第三个加数
			while (l < r)
			{
				if (nums[l] + nums[r] == -fix)    //和为0
				{
					if (l == i + 1 || r == nums.size() - 1)
					{
						res.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
						l++;
						r--;
					}
					else if (nums[l] == nums[l - 1])   //跳过重复的
						l++;
					else if (nums[r] == nums[r + 1])
						r--;
					else
					{
						res.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
						l++;
						r--;
					}
				}
				else if (nums[l] + nums[r] < -fix)      //三数之和小于0，l右移
					l++;
				else      //三数之和大于0，r左移
					r--;
			}
		}
		return res;
	}
};
