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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        if (head == NULL) return head;
        Node* p = head, * q, * r;
        while (p != NULL)
        {
            if (p->child != NULL) 
            {
                q = p->next;
                r = p->child;
                p->child = NULL;
                p->next = r;
                r->prev = p;
                while (r->next != NULL) r = r->next;
                r->next = q;
                if (q != NULL) q->prev = r;
            }
            p = p->next;
        }
        return head;
    }
};


int main()
{

	system("pause");

	return 0;
}