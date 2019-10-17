/*
	����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
	���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
	�������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
	{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� 
	{2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxWindowSize(vector<int> vec, vector<int> &res, int winsize)
{
	//˫�˶��н��O(N)
	deque<int> d;
	for (int i = 0; i < vec.size(); i++)
	{
		while (d.size() && vec[d.back()] <= vec[i])  //��֮ǰβ�����Ԫ�رȽϣ���β��Ľ�β��ŵĳ���
			d.pop_back();
		if (d.size() && i - d.front() >= winsize)   //������һ��Ķ����еĴ�������
			d.pop_front();		//�����ͷ����ͷ��������ʧЧ�ģ���֮β�����˺�ͷ�Ŀ��ܲ�ʧЧ��
		d.push_back(i);
		if (winsize&&i + 1 >= winsize)
			res.push_back(vec[d.front()]);
	}
}

int main()
{
	int windowsize = 3;
	vector<int> vec(8);
	vector<int> res;
	vec[0] = 2;
	vec[1] = 3;
	vec[2] = 4;
	vec[3] = 2;
	vec[4] = 6;
	vec[5] = 2;
	vec[6] = 5;
	vec[7] = 1;
	maxWindowSize(vec, res, windowsize);
	//����ҵ���ÿһ������ֵ
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}