#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head)
    {
        if (head == NULL) 
        {
            return NULL;
        }
        Node* ptr = head, * nptr, * cptr;
        while (ptr != NULL) 
        {
            if (ptr->child != NULL) 
            {
                nptr = ptr->next;
                cptr = ptr->child;
                ptr->child = NULL;
                cptr->prev = ptr;
                ptr->next = cptr;
                while (cptr->next != NULL) 
                {
                    cptr = cptr->next;
                }
                cptr->next = nptr;
                if (nptr != NULL) 
                {
                    nptr->prev = cptr;
                }
            }
            ptr = ptr->next;//������չ���ں��棬����������������֮���ptr�ƶ�������Ҳ�ᱻ������
        }
        return head;
    }
};
int main()
{

	system("pause");

	return 0;
}