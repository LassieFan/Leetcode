#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	�ܹ���num���⣬ÿ�����Ӧ�����Լ�ÿ����������ʱ�䣬������ʱ��sumtime�п��Ի�ȡ������߷�
	��̬�滮
*/

/*
	5               ����
	5 4 3 5 2       ÿ����ķ�ֵ
	2 2 3 5 1		ÿ�����ʱ��
	10				����ʱ��
*/


//��ά���ǵ�ǰ�ж���ʱ�䣬����ĳһ����ҵ�����±�����½ǿ�ʼ��䣬һ��һ����
int MostHighScore(int num, vector<int> score, vector<int> time, int sumtime)
{
	vector<vector<int>> dp(num, vector<int>(sumtime + 1, 0));
	for (int j = 1; j <= sumtime; j++)        //�Ƚ��������һ�����꣬�ȷ����һ����ҵ���ж������Ǹ�ʱ�����Լ��������
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
