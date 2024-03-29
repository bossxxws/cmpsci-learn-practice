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
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* yum = new ListNode(NULL, head);//创建一个新的
		ListNode* ya = yum;

		if (head == NULL)
		{
			return head;
		}
		while (ya->next != NULL)
		{
			if (ya->next->val == val)
			{
				ya->next = ya->next->next;
			}
			else
			{
				ya = ya->next;
			}
		}
		head = yum->next;
		return head;
	}
};

int main()
{
	system("pause");
	return 0;
}