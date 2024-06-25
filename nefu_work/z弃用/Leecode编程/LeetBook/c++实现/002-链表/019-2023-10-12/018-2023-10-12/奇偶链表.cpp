#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* oddEvenList(ListNode* head)
	{
		if (head == NULL) 
		{
			return NULL;
		}
		ListNode* odd = head;
		ListNode* evenhead = head->next;
		ListNode* even = evenhead;
		while (even->next != NULL && odd->next != NULL) 
		{
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
		return head;
	}
	
};
int main()
{

	system("pause");

	return 0;
}