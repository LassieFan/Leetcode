#include <iostream>
#include <vector>
using namespace std;

//对于n个座位，对应每个人，只有一个人坐对位置，所有的组合数
//可以从反面来求，n个人，所有人坐错的组合数是 S(n) = (n-1)* (F(n-1)+F(n-2));
//那么对于n个人只有一个人坐对，就是n-1个人坐错，总共有n种，所以为 n * S(n-1);


//递归版本
int Judge1(int m)
{
	if (m == 1)       //1个人坐错是0
		return 0;
	if (m == 2)       //2个人坐错是1
		return 1;

	return (m - 1)*(Judge1(m - 1)+ Judge1(m - 2));
}


//非递归版本
int Judge2(int m)
{
	vector<int> vec;
	if (m == 1)
		return 0;
	if (m == 2)
		return 1;
	vec.push_back(0);
	vec.push_back(1);
	int x = m;
	int y = 2;
	int i = 0;
	int j = 1;
	while (x > 3)
	{
		vec.push_back(y*(vec[i++] + vec[j++]));
		x--;
		y++;
	}
	return (m - 1)*(vec[m - 2] + vec[m - 3]);
}

int main()
{
	int m;
	cin >> m;
	cout << m * Judge1(m - 1) << endl;
	cout << m * Judge2(m - 1) << endl;
}
