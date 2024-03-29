#include <iostream>
using namespace std;
#include<vector>

struct ListNode 
{
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode *pre = NULL;
		ListNode* now = head;
		while(now!= NULL) 
		{
			ListNode* k = now->next;
			now->next = pre;
			pre = now;
			now = k;

		}
		return head;
	}
};

int main()
{

	system("pause");

	return 0;
}