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
	//判断链表是否有环，且将环中的一个节点返回
	ListNode* Meeting(ListNode* pHead)
	{
		
		ListNode* slow = pHead;
		if (slow->next == NULL)       //一方面是单独节点判断，另一方面为了赋值给快指针
			return NULL;

		ListNode* fast = slow->next;

		while (slow != NULL && fast != NULL)
		{
			if (slow == fast)
				return slow;

			slow = slow->next;
			fast = fast->next;
			if (fast != NULL)
				fast = fast->next;
		}
		return NULL;
	}

	//求环的入口，计算出环大小，一个指针先走环大小步，然后与另一个指针再一起走，相遇点即入口点
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* meet = Meeting(pHead);

		if (NULL == meet)
			return NULL;

		int count = 1;
		ListNode* m = meet;
		while (m->next != meet)    //计算环中节点数
		{
			count++;
			m = m->next;
		}
		
		ListNode* pAhead = pHead;
		ListNode* pBefore = pHead;
		while (count != 0)         //让一个指针先走环中节点count步
		{
			pAhead = pAhead->next;
			count--;
		}
		while (pBefore != pAhead)
		{
			pBefore = pBefore->next;
			pAhead = pAhead->next;
		}
		return pBefore;
	}

	//不用计算长度，直接从相遇点，往后走，直到遇到就是入口，数学计算出来的
	ListNode* EntryNodeOfLoop2(ListNode* pHead)
	{
		ListNode* meet = Meeting(pHead);

		if (NULL == meet)
			return NULL;

		ListNode* pAhead = pHead;
		
		while (meet->next != pAhead)     //注意边界判断
		{
			meet = meet->next;
			pAhead = pAhead->next;
		}
		return pAhead;
	}
};

int main()
{
	ListNode* LHead1 = new ListNode(0);
	ListNode* l1 = LHead1;
	ListNode* circlehead = NULL;

	for (int i = 0; i < 5; i++)
	{
		l1->next = new ListNode(i + 1);
		l1 = l1->next;
		if (i == 2)
			circlehead = l1;	
	}
	l1->next = circlehead;

	Solution *s = new Solution();
	ListNode *endhead = s->EntryNodeOfLoop(LHead1);
	ListNode *endhead2 = s->EntryNodeOfLoop2(LHead1);
	
	cout << endhead->val << endl;
	cout << endhead2->val << endl;
}

