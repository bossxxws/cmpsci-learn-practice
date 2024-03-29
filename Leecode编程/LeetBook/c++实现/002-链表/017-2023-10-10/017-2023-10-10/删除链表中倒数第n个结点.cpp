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
             count++;//��¼����node����
         }
         int m = count;
         int k = m - n;
         for (int j = 0; j < k; j++)
         {
             cur = cur->next;
         }
         cur->next = cur->next->next;
         ListNode* ans = dummy->next;//��������ΪҲҪ�á�ͷ��㡱ָ�������ط�������������ͷ�ڵ���ֵ������Ҫ�涨һ���ƽ�������
         return ans;
     }
 };

int main()
{

	system("pause");

	return 0;
}