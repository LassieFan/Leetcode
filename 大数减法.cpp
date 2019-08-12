#include <iostream>
#include <vector>
#include <string>
using namespace std;

//大数减法，数组中找到相邻绝对值最小的那一对数

string Sub(string big, string small)
{
	vector<int> tb;
	vector<int> ts;
	vector<int> res;
	int n = big.length();
	int m = small.length();
	int j = 0;
	for (int i = n - 1; i >= 0; i--)
		tb.push_back(big[i] - '0');
	for (int i = m - 1; i >= 0; i--)
		ts.push_back(small[i] - '0');

	for (int i = 0; i < n; i++)
	{
		if (i >= m)
		{
			for (int k = i; k < n; k++)
				res.push_back(tb[k]);
			break;
		}
		if (tb[i] >= ts[i])
			res.push_back(tb[i] - ts[i]);
		else
		{
			res.push_back(tb[i] + 10 - ts[i]);
			tb[i + 1] = tb[i + 1] - 1;
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		if (res[i] == 0)
			n--;
		else
			break;
	}
	string order = "";
	for (int i = n - 1; i >= 0; i--)
	{
		string tmp = std::to_string(res[i]);
		order += tmp;
	}
	return order;
}

bool JudgeBig(string a, string b)
{
	if (a.size() > b.size())
		return true;
	else if (a.size() < b.size())
		return false;
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				continue;
			if (a[i] > b[i])
				return true;
			if (a[i] < b[i])
				return false;
		}
		return true;
	}
}

string Judge(string a, string b)
{
	if (JudgeBig(a, b))
		return Sub(a, b);
	else
		return Sub(b, a);
}

int main()
{
	int n;
	int min = 0;
	cin >> n;
	vector<string> vec(n);
	string end = "10000000000000000";
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		vec[i] = x;
	}

	for (int i = 0; i < n - 1; i++)
	{
		string tmp = Judge(vec[i], vec[i + 1]);
		if (JudgeBig(tmp, end)) {}   //tmp>end
		else
		{
			end = "";
			end = tmp;
			min = i;
		}
	}

	cout << vec[min] << endl;
	cout << vec[min + 1] << endl;
	return 0;
}