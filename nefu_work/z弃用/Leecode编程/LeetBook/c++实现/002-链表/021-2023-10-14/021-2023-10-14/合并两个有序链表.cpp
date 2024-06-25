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
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return !l1 ? l2 : l1;
        ListNode* head = l1->val < l2->val ? l1 : l2;
        head->next = head == l1 ? mergeTwoLists(head->next, l2) : mergeTwoLists(head->next, l1);
        return head;
    }
};



int main()
{

	system("pause");

	return 0;
}