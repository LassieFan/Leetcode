#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		ListNode* pReserveHead = NULL;
		ListNode* pNode = pHead;
		ListNode* pPre = NULL;
		while (pNode != NULL)
		{
			ListNode* pNext = pNode->next;
			if (pNext == NULL)
				pReserveHead = pNode;
			pNode->next = pPre;
			pPre = pNode;
			pNode = pNext;
		}
		return pReserveHead;
	}
};

int main()
{
	ListNode* LHead1 = new ListNode(0);
	ListNode* l1 = LHead1;

	for (int i = 0; i < 10; i++)
	{
		l1->next = new ListNode(i+1);
		l1 = l1->next;
	}

	Solution *s = new Solution();
	ListNode *endhead = s->ReverseList(LHead1);
	
	while (endhead != NULL)
	{
		cout << endhead->val << " ";
		endhead = endhead->next;
	}
}