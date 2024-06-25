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
     ListNode* rotateRight(ListNode* head, int k)
     {
         if (k == 0 || head == nullptr || head->next == nullptr)
         {
             return NULL;
         }
         ListNode* ptr = head;
         int cou = 1;
         ListNode* fi;
         for (ptr->next != NULL; ptr = ptr->next;)
         {
             fi = ptr;
             cou += 1;//记录的是链表的个数
         }
         fi->next = head;
         k = k % cou;
         
         int a = cou - k;
         if (a == cou) 
         {
             return head;
         }
         ListNode* aim = head;
         for (int i = 0; i < a; i++)
         {
             aim = aim->next;
         }
         ListNode* newhead = aim->next;//新的head
         aim->next = NULL;

         return newhead;
     }
 };

int main()
{

	system("pause");

	return 0;
}