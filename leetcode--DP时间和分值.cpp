#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	总共有num道题，每道题对应分数以及每道题所花费时间，在有限时间sumtime中可以获取到的最高分
	动态规划
*/

/*
	5               题数
	5 4 3 5 2       每道题的分值
	2 2 3 5 1		每道题的时间
	10				有限时间
*/


//二维列是当前有多少时间，行是某一个作业序列下标从左下角开始填充，一行一行填
int MostHighScore(int num, vector<int> score, vector<int> time, int sumtime)
{
	vector<vector<int>> dp(num, vector<int>(sumtime + 1, 0));
	for (int j = 1; j <= sumtime; j++)        //先将数组最后一行填完，先放最后一个作业，判断其在那个时间点可以加上其分数
	{
		if (time[num - 1] > j)
			dp[num - 1][j] = 0;
		else
			dp[num - 1][j] = score[num - 1];
	}
	for (int i = num - 2; i >= 0; i--)
	{
		for (int j = 1; j <= sumtime; j++)
		{
			if (time[i] > j)
				dp[i][j] = dp[i + 1][j];
			else
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - time[i]] + score[i]);
		}
	}
	return dp[0][sumtime];
}

int main()
{
	int num;
	vector<int> score;
	vector<int> time;
	int sumtime;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		score.push_back(tmp);
	}
	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		time.push_back(tmp);
	}
	cin >> sumtime;

	cout << MostHighScore(num, score, time, sumtime) << endl;
}
