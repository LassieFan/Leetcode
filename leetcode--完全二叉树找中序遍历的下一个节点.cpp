#include <iostream>
#include <vector>
using namespace std;

//输入完全二叉树的层次遍历顺序以及输入要找寻得节点元素值
//输出该完全二叉树所要找得节点的中序遍历的下一个节点
int NextNode(vector<int> vec, int num)
{
	int i = 0;
	for (; i < vec.size(); i++)
	{
		if (vec[i] == num) break;
	}
	return (i * 2 + 2) < vec.size() ? vec[i * 2 + 2] : -1;
}
int main()
{
	vector<int> vec;
	int tmp;
	cin >> tmp;
	vec.push_back(tmp);
	while (cin.get()!='\n')
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	int num;
	cin >> num;
	cout<<NextNode(vec, num);
}