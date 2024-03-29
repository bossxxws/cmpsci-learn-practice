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
            ptr = ptr->next;//子链会展开在后面，所以子链的子链在之后的ptr移动过程中也会被遍历到
        }
        return head;
    }
};
int main()
{

	system("pause");

	return 0;
}