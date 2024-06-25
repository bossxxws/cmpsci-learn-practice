#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 class Solution {
 public:
     ListNode* removeNthFromEnd(ListNode* head, int n)
     {
         int count = 0;
         ListNode* ptr = head;
         ListNode* dummy = new ListNode(0, head);
         ListNode* cur = dummy;
         while (ptr != nullptr)
         {
             ptr = ptr->next;
             count++;//记录的是node个数
         }
         int m = count;
         int k = m - n;
         for (int j = 0; j < k; j++)
         {
             cur = cur->next;
         }
         cur->next = cur->next->next;
         ListNode* ans = dummy->next;//这里是因为也要让“头结点”指向其他地方，这个链表里的头节点有值，所以要规定一个哑结点操作他
         return ans;
     }
 };

int main()
{

	system("pause");

	return 0;
}