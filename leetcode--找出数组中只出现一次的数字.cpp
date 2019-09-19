#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
	����ĳ��Ԫ��ֻ����һ��(������)���⣬����ÿ��Ԫ�ؾ��������Σ�ż���Σ����ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/

//��hash���ţ���hash��û�����Ԫ�ز��룬�����Ԫ��ɾ�������ʣ�µ���ֻ����һ�ε�
int SingleNum1(vector<int>& vec)
{
	unordered_set<int> bset;
	for (int i = 0; i < vec.size(); i++)
	{
		if (bset.count(vec[i]))		//�ж�set���Ƿ������Ԫ�أ�����0/1
			bset.erase(vec[i]);
		else
			bset.insert(vec[i]);
	}
	return *(bset.begin());
}

//��˫ָ��,�Ƚ�����Ԫ������������һ�𣬱˴˲���ȷ���ǰһ��
int SingleNum2(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	for (int i = 0, j = 1; j < vec.size(); i += 2, j += 2)
	{
		if (vec[i] != vec[j]) return vec[i];
	}
	return vec[vec.size()-1];		//������Ԫ�أ����һ����ƥ�䷵��
}

//��ȫ��������򣬵õ��Ľ������ֻ����һ�ε�
int SingleNum3(vector<int>& vec)
{
	int end = vec[0];
	for (int i = 1; i < vec.size(); i++)
		end ^= vec[i];
	return end;
}


int main()
{
	vector<int> vec(5, 0);
	vec[0] = 4;
	vec[1] = 2;
	vec[2] = 1;
	vec[3] = 1;
	vec[4] = 2;
	cout<<SingleNum1(vec)<<endl;
	cout << SingleNum2(vec) << endl;
	cout << SingleNum3(vec) << endl;
}