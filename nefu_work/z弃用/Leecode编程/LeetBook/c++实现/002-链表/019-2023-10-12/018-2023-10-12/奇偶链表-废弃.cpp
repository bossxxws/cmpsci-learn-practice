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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* yum = new ListNode(NULL);
        yum = head;//����
        ListNode* f = new ListNode(NULL);
        f= head->next;//ż��
        ListNode* pf = f;
        ListNode* ya = yum; // �ƽ���൱��ż��
        for (int i = 1; ya->next != NULL &&pf->next!= NULL; i++)
        {
            if (i % 2 != 0) //����
            {
                ya->next = pf->next;
                
            }
            else //ż��
            {
                pf->next = ya->next;
                
            }
            pf = pf->next;
            ya = ya->next;
        }

        ya->next = f->next;

        return head;
    }
};

int main()
{

	system("pause");

	return 0;
}