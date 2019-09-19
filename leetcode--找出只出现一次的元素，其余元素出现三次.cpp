#include <iostream>
#include <vector>
using namespace std;
/*
	����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/


//һ��������λֻ�ܱ�ʾ0����1��Ҳ�����������Լ�¼һ����������һ�λ������Σ�������Ҫ����������λ
//���������ͬ��Ԫ������ֵΪ0   00->01->10->00 ����������յĴ���00����
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
	�������е�ÿһ��Ԫ�ذ���ÿһλ��֣�����Ԫ�ص�ÿһλ֮�Ϳ϶���3N����3N+1
	����3N����֤��Ψһ���Ǹ�Ԫ����һλ��0����֮��һλ��1����¼����
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
		if (cnt % 3 != 0)		//�������4�����4ȡ��
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