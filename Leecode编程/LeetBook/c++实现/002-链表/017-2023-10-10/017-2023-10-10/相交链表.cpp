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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* m = headA;
        ListNode* n = headB;
        int change = 0;
        //ֻҪA��Bβ�����룬����������һ����������������ҵ�����
        while (m != nullptr && n!=nullptr)
        {
            if (m == n)
            {
                return m;
            }
            m = m->next;
            n = n->next;
            if (change<2 &&m == nullptr)
            {
                m= headB;//A�������B
                change++;
            }
            if (change < 2 && n == nullptr)
            {
                n = headA;//B�������A
                change++;
            }
        }
        return NULL;
    }
};

int main()
{

	system("pause");

	return 0;
}