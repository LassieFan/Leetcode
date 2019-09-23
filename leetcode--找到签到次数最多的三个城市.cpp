#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

//34839946-beijing 34839946-shanghai 42342124-hongkong 42342124-guilin 42342124-guilin 12312344-shanghai 12312344-shanghai 22341234-nanjing
/*
	输出前三热门城市，用户id与城市相同的不重复记录
	输出：	shanghai 2
			beijing  1
			hongkong 1
*/
void GetHotCity(set<string> myset)
{
	map<string, int> mmap;
	for(auto j:myset)
	{
		string tmp = "";
		int i = 0;
		for (; i < j.size(); i++)
		{
			if (j[0] == '-')
			{
				i+=1;
				break;
			}
		}
		while (j[i] != ' ')
			tmp += j[i++];
		if (mmap.find(tmp) == mmap.end()) mmap[tmp] = 1;
		else mmap[tmp] += 1;
	}
	vector<string> vec;
	vector<int> count;
	for (auto x : mmap)
	{
		vec.push_back(x.first);
		count.push_back(x.second);
	}
	for (int i = 0; i < 3; i++)
	{
		auto it1 = count.begin();
		auto it2 = vec.begin();
		int m = count[0];
		int flagm = 0;
		int j = 0;
		for (; j < count.size(); j++)
		{
			if (count[j] > m)
				flagm = j;
		}
		cout << vec[j] << " " << count[j] << endl;
		count.erase(it1+j);
		vec.erase(it2 + j);
	}
}

int main()
{
	set<string> myset;
	string tmp;
	cin >> tmp;
	myset.insert(tmp);
	while (cin.get() != '\n')
	{
		cin >> tmp;
		myset.insert(tmp);
	}
	GetHotCity(myset);
	return 0;
}