#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
	层次遍历
	不论广度遍历树还是图，都是用的队列
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
	
	//层次遍历树
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

	//分行打印树节点，每层节点输出到同一行
	void Print(TreeNode* root)
	{
		if (NULL == root)
			return;
		queue<TreeNode*> que;
		que.push(root);
		int result = 1;    //记录一行输出的个数
		int behind = 0;    //记录下一行的个数
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

	//按照“之”字形输出，第一层节点从左往右输出，第二层节点从右往左输出，第三层从左往右输出。。。。。
	//两个栈，打印奇数层，则先保存左子节点在保存右节点到第一个栈中，若打印的是偶数层，先保存右孩子再保存左子节点到第二个栈中
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