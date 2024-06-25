#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution
{
public:
	ListNode* detectCycle(ListNode* head)
	{
		int index = 0;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != NULL && slow->next != NULL) 
		{
			if (fast->next->next == NULL || slow->next == NULL) 
			{
				return NULL;
			}
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) 
			{
				fast = head;
				while (fast != slow) 
				{
					fast = fast->next;
					slow = slow->next;
					if (slow == fast) 
					{
						return fast;
					}
				}
			}
		}
		return NULL;
	}
};
int main()
{

	system("pause");

	return 0;
}