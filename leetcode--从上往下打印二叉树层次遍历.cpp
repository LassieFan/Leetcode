#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
	��α���
	���۹�ȱ���������ͼ�������õĶ���
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	
	//��α�����
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> vec;
		if (NULL == root)
			return vec;

		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			if (que.front() != NULL)
			{
				vec.push_back(que.front()->val);
				que.push(que.front()->left);
				que.push(que.front()->right);
			}
			que.pop();
		}
		return vec;
	}

	//���д�ӡ���ڵ㣬ÿ��ڵ������ͬһ��
	void Print(TreeNode* root)
	{
		if (NULL == root)
			return;
		queue<TreeNode*> que;
		que.push(root);
		int result = 1;    //��¼һ������ĸ���
		int behind = 0;    //��¼��һ�еĸ���
		while (!que.empty())
		{
			while (result != 0)
			{
				if (que.front() != NULL)
					cout << que.front()->val << " ";

				if (que.front()->left != NULL)
				{
					behind++;
					que.push(que.front()->left);
				}

				if (que.front()->right != NULL)
				{
					behind++;
					que.push(que.front()->right);
				}
				que.pop();
				result--;
			}
			cout << endl;
			result = behind;
			behind = 0;
		}
	}

	//���ա�֮�������������һ��ڵ��������������ڶ���ڵ���������������������������������������
	//����ջ����ӡ�����㣬���ȱ������ӽڵ��ڱ����ҽڵ㵽��һ��ջ�У�����ӡ����ż���㣬�ȱ����Һ����ٱ������ӽڵ㵽�ڶ���ջ��
	void PrintZhi(TreeNode* root)
	{
		if (root == NULL)
			return;
		stack<TreeNode*> sleft;
		stack<TreeNode*> sright;
		
		cout << root->val << endl;
		if(root->left!=NULL)
			sleft.push(root->left);
		if (root->right != NULL)
			sleft.push(root->right);
		int i = 1;
		while (!sleft.empty() || !sright.empty())
		{
			if (i % 2 != 0)
			{
				while (!sleft.empty())
				{
					cout << sleft.top()->val << " ";
					if (sleft.top()->right)
						sright.push(sleft.top()->right);
					if(sleft.top()->left)
						sright.push(sleft.top()->left);
					sleft.pop();
				}
				cout << endl;
			}
			else
			{
				while (!sright.empty())
				{
					cout << sright.top()->val << " ";
					if (sright.top()->left)
						sleft.push(sright.top()->left);
					if (sright.top()->right)
						sleft.push(sright.top()->right);
					sright.pop();
				}
				cout << endl;
			}
			i++;
		}
	}
};


int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	//root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	root->right->left->left = new TreeNode(12);
	root->right->right->left = new TreeNode(14);

	Solution* s = new Solution();
	s->Print(root);
	s->PrintZhi(root);
}