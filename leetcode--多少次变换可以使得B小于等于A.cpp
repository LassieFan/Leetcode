#include <iostream>
#include <vector>
using namespace std;

/*
	给定数字A,B(A<B)和系数P，Q，每次操作可以A+P或者P变成P*Q，至少几次操作使得B<=A
	2
	1 5 7 2
	3 5 1 2

	输出：
	1
	2
*/
void GetNum(vector<vector<int>> vec)
{
	int len = vec.size();
	vector<int> num;
	for (int i = 0; i < len; i++)
	{
		int count = 0;
		int a = vec[i][0];
		int b = vec[i][1];
		int p = vec[i][2];
		int q = vec[i][3];
		while (a < b)
		{
			if ((a + p) >= b)
				a = a + p;
			else
				p = p * q;
			count++;
		}
		num.push_back(count);
	}
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << endl;
}

int main()
{
	int num;
	cin >> num;
	vector<vector<int>> vec;
	for (int i = 0; i < num; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 4; j++)
		{
			int input;
			cin >> input;
			tmp.push_back(input);
		}
		vec.push_back(tmp);
	}
	GetNum(vec);
	return 0;
}