#include <vector>
#include <iostream>
using namespace std;

/*
	合并两个内容流，实现隔4个插入1个，若合并完还有剩下，则加到内容流的尾部
	eg：1 2 3 4 5 6 7 8 9
		a b c
  输出：1 2 3 4 a 5 6 7 8 b 9 c
*/

void Merge(vector<char> vec1, vector<char> vec2)
{
	int len1 = vec1.size();
	int len2 = vec2.size();
	vector<char> vec3(len1 + len2);
	vector<char>::iterator it1 = vec1.begin();
	vector<char>::iterator it2 = vec2.begin();
	vector<char>::iterator it3 = vec3.begin();

	int count = 0;

	while (it1 != vec1.end() && it2 != vec2.end())
	{
		if (count != 4)
		{
			*it3 = *it1;
			it1++;
			it3++;
			count++;
		}
		else
		{
			*it3 = *it2;
			it2++;
			it3++;
			count = 0;
		}
	}

	while (it1 != vec1.end())
	{
		*it3 = *it1;
		it1++;
		it3++;
	}

	while (it2 != vec2.end())
	{
		*it3 = *it2;
		it2++;
		it3++;
	}
	it3 = vec3.begin();

	while (it3 != vec3.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;
}

int main()
{
	vector<char> vec1;
	vector<char> vec2;
	char ch;
	char nc;
	while ((cin >> ch).get(nc))
	{
		vec1.push_back(ch);
		if (nc == '\n')
			break;
	}
	while ((cin >> ch).get(nc))
	{
		vec2.push_back(ch);
		if (nc == '\n')
			break;
	}
	Merge(vec1, vec2);
	return 0;
}