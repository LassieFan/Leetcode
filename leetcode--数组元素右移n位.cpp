#include<iostream>
#include<vector>

void Move(std::vector<int>& vec,int k)
{
	k = k % vec.size();
	std::reverse(vec.begin(),vec.end());
	std::reverse(vec.begin(),vec.begin()+k-1);
	std::reverse(vec.begin() + k, vec.end());
}

int main()
{
	int n,k;
	std::cin >> n;     //Ԫ�ظ���
	std::cin >> k;	   //����λ��
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		vec.push_back(x);
	}

	Move(vec, k);
	for (int i = 0; i < n; i++)
		std::cout << vec[i] << " ";
}