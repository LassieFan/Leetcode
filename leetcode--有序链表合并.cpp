#include<iostream>
using namespace std;


//将两个有序链表合并称一个链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode* head = NULL;
		if (pHead1->val < pHead2->val)
		{
			head = pHead1;
			head->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			head = pHead2;
			head->next = Merge(pHead1, pHead2->next);
		}
		return head;
	}


	//非递归版本
	ListNode* NotReIntMerge(ListNode* pHead1, ListNode* pHead2)    
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		ListNode* head = NULL;
		ListNode* current = NULL;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val <= pHead2->val)
			{
				if (head == NULL)
					head = current = pHead1;
				else
				{
					current->next = pHead1;
					current = current->next;
				}
				pHead1 = pHead1->next;
			}
			else
			{
				if (head == NULL)
					head = current = pHead2;
				else
				{
					current->next = pHead2;
					current = current->next;
				}
				pHead2 = pHead2->next;
			}
		}
		if (pHead1 == NULL)
			current->next = pHead2;
		else
			current->next = pHead1;
		return head;
	}
};

int main()
{
	ListNode* LHead1 = new ListNode(1);
	ListNode* LHead2 = new ListNode(2);
	ListNode* l1 = LHead1;
	ListNode* l2 = LHead2;
	for (int i = 0; i < 10; i++)
	{
		l1->next = new ListNode(i * 2 + 1);
		l1 = l1->next;
	}
	for (int i = 0; i < 10; i++)
	{
		l2->next = new ListNode(i * 3 + 2);
		l2 = l2->next;
	}
	Solution *s = new Solution();
	ListNode *endhead =s->Merge(LHead1, LHead2);
	//ListNode *endhead = s->NotReIntMerge(LHead1, LHead2);
	while (endhead != NULL)
	{
		cout << endhead->val << " ";
		endhead = endhead->next;
	}
}