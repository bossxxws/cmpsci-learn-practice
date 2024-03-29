#include <iostream>
using namespace std;


struct ListNode
{
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
	  ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution 
{
public:
	bool isPalindrome(ListNode* head)
	{
		ListNode *c =  new ListNode(0, head);
		ListNode* ptr = new ListNode(0, head);
		int coun = 0;
		for (int i = 0; c->next != NULL; ) 
		{
			c = c->next;
			i++;
			coun++;
		}
		int j = coun / 2;//翻转后面的链表，用前面的比较，就算是奇数也是最中间的区块被移到最后面，然后前面的跟后面的比较完刚好不到最后一个
		for (int p = 0; p < j; p++) 
		{
			ptr = ptr->next;
		}
		ListNode* pre = NULL;
		while (ptr != NULL) 
		{
			ListNode* cur = ptr->next;
			ptr->next = pre;
			pre = ptr;
			if (cur != NULL) 
			{
				ptr = cur;
			}
			else 
			{
				break;
			}
		}
		for (int b = 0; b < j; b++) 
		{
			if (ptr->val != head->val) 
			{
				return false;
			}
			ptr = ptr->next;
			head =head->next;
		}
		return true;
	}
};

int main()
{
	ListNode * head= new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	Solution s;
	bool k = s.isPalindrome(head);
	cout << k << endl;
	system("pause");

	return 0;
}