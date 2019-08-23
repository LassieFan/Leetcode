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
	//�ж������Ƿ��л����ҽ����е�һ���ڵ㷵��
	ListNode* Meeting(ListNode* pHead)
	{
		
		ListNode* slow = pHead;
		if (slow->next == NULL)       //һ�����ǵ����ڵ��жϣ���һ����Ϊ�˸�ֵ����ָ��
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

	//�󻷵���ڣ����������С��һ��ָ�����߻���С����Ȼ������һ��ָ����һ���ߣ������㼴��ڵ�
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* meet = Meeting(pHead);

		if (NULL == meet)
			return NULL;

		int count = 1;
		ListNode* m = meet;
		while (m->next != meet)    //���㻷�нڵ���
		{
			count++;
			m = m->next;
		}
		
		ListNode* pAhead = pHead;
		ListNode* pBefore = pHead;
		while (count != 0)         //��һ��ָ�����߻��нڵ�count��
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

	//���ü��㳤�ȣ�ֱ�Ӵ������㣬�����ߣ�ֱ������������ڣ���ѧ���������
	ListNode* EntryNodeOfLoop2(ListNode* pHead)
	{
		ListNode* meet = Meeting(pHead);

		if (NULL == meet)
			return NULL;

		ListNode* pAhead = pHead;
		
		while (meet->next != pAhead)     //ע��߽��ж�
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

