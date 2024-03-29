#include <iostream>
using namespace std;



  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 


class Solution
{

public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && slow->next != NULL)
        {
            if (fast->next->next == NULL || slow->next == NULL) 
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

	system("pause");

	return 0;
}