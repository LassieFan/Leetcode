#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

//从小到大排序找间隔最小的连续两组，case 10%  
double Cal(int a, int b, int c)
{
	double ave = (double)(a + b + c) / 3.0;
	double sum = (a - ave)*(a - ave) + (b - ave)*(b - ave) + (c - ave)*(c - ave);
	return sum / 3;
}

void Judge(vector<int>& vec)
{
	if (vec.size() == 3)
	{
		printf("%.2f\n", Cal(vec[0], vec[1], vec[2]));
		//cout << Cal(vec[0], vec[1], vec[2]) << endl;
		return;
	}

	sort(vec.begin(), vec.end());
	int len = vec.size();
	int min = 3000;
	vector<int> val;
	vector<int> minode;   //记录下标
	int n = 0;
	for (int i = 1; i < len; i++)
	{
		int tmp = vec[i] - vec[i - 1];
		if (tmp < 0)
			tmp = 0 - tmp;
		val.push_back(tmp);
		
		if (min >= tmp)
		{
			min = tmp;
			minode.push_back(i);
		}
	}
	
	int mlen = minode.size();
	int sum = 0;
	int summin = 3000;
	int inode = -1;
	bool p;
	for (int i = 0; i < mlen; i++)
	{
		sum = 0;
		sum += min;
		if (minode[i] == len - 1)   //最后一个
		{
			sum += val[len - 3];
			p = true;
		}
		else if (minode[i] == 1)   //第一个
		{
			sum += val[1];
			p = false;
		}
		else
		{
			p = true;    //取前面的
			int x=sum + val[minode[i]-2];     //前一个
			int y = sum + val[minode[i]];
			if (x < y)
				sum = x;
			else
			{
				sum = y;
				p = false;     //取后面的值
			}
		}

		if (sum <= summin)
		{
			inode = minode[i];
		}
	}

	if (p == true)
	{
		printf("%.2f\n", Cal(vec[inode-2], vec[inode-1], vec[inode]));
	}
	else
		printf("%.2f\n", Cal(vec[inode - 1], vec[inode], vec[inode+1]));
}

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	Judge(vec);
	return 0;
}


#if 0
double Cal(int a,int b,int c)
{
	double ave = (double)(a + b + c) / 3.0;
	double sum = (a - ave)*(a - ave) + (b - ave)*(b - ave) + (c - ave)*(c - ave);
	return sum / 3;
}

void Judge(vector<int>& vec)
{
	if (vec.empty() || vec.size() < 3)
		return;
	if (vec.size() == 3)
	{
		printf("%.2f\n", Cal(vec[0], vec[1], vec[2]));
		//cout << Cal(vec[0], vec[1], vec[2]) << endl;
		return;
	}

	double val = 3000; 
	int len = vec.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				double x = Cal(vec[i], vec[j], vec[k]);
				if (x < val)
					val = x;
			}
		}
	}
	printf("%.2f\n", val);
	//cout << val << endl;
}



int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	Judge(vec);
	return 0;
}

#endif