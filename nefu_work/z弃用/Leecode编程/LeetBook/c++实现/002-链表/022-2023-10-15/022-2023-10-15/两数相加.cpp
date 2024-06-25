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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head =new ListNode(0, nullptr);
        ListNode* cur = head;
        int sum = 0;
        while (l1 || l2) 
        {
            if (l1) 
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2) 
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            ListNode* tep = new ListNode(sum%10, nullptr);
            cur->next = tep;
            cur = cur->next;
            sum = sum / 10;
        }
        return head->next;
	}
};
int main()
{

	system("pause");

	return 0;
}