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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL) 
        {
            return list2;
        }
        else if (list2 == NULL) 
        {
            return list1;
        }
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dum = new ListNode(-1);
        ListNode *pre = dum;
        if (l1->val <= l2->val)
        {
            dum->next = l1;
        }
        else
        {
            dum->next = l2;
        }
        while (l1 && l2) 
        {
            if (l1->val <= l2->val)
            {
                pre->next = l1;
                pre = pre->next;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                pre = pre->next;
                l2 = l2->next;
            }
        }
        pre->next = l1 == nullptr ? l2 : l1;
        return dum->next;
    }
};
int main()
{

	system("pause");

	return 0;
}