#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//�ҵ�����������������֮����0�Ĳ��ظ������
//�Ƚ��������򣬶���ָ���һ��ָ��̶��������

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;     //��Ž����vector
		std::sort(nums.begin(),nums.end());
		if (nums.empty() || nums.front() > 0 || nums.back() < 0)
			return {};

		for (int i = 0; i < nums.size(); i++)
		{
			int fix = nums[i];
			if (fix > 0) break;
			if (i > 0 && fix == nums[i - 1]) continue;    //��������ͬ��ȥ���ظ�
			int l = i + 1;       //i����Ԫ�صĺ���ָ�룬�ڶ�������
			int r = nums.size()-1;       //����βָ�룬����������
			while (l < r)
			{
				if (nums[l] + nums[r] == -fix)    //��Ϊ0
				{
					if (l == i + 1 || r == nums.size() - 1)
					{
						res.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
						l++;
						r--;
					}
					else if (nums[l] == nums[l - 1])   //�����ظ���
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
				else if (nums[l] + nums[r] < -fix)      //����֮��С��0��l����
					l++;
				else      //����֮�ʹ���0��r����
					r--;
			}
		}
		return res;
	}
};
