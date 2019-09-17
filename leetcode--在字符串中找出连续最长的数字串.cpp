#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <limits>
using namespace std;

//找出字符串中连续最长的数字串
//遍历一遍即可

string find_longest_num_str(string input) {
	string x = "";
	string y = "";
	int count = 0;
	int tmpcount = 0;
	bool flag = false;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 48 && input[i] <= 57 && flag == false)
		{
			y += input[i];
			tmpcount++;
			flag = true;
		}
		else if (input[i] >= 48 && input[i] <= 57)
		{
			y += input[i];
			tmpcount++;
		}
		else if ((input[i] < 48 || input[i]>57) && flag == true)
		{
			if (count < tmpcount)
			{
				x = y;
				count = tmpcount;
			}
			flag = false;
			y = "";
			tmpcount = 0;
		}
	}
	return x;
}


int main() {
	string res;

	string _input;
	getline(cin, _input);

	res = find_longest_num_str(_input);
	cout << res.size() << "/" << res << endl;

	return 0;

}
