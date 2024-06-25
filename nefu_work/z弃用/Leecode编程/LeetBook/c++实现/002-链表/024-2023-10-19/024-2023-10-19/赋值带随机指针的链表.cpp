#include <iostream>
using namespace std;
class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if (head == NULL) 
        {
            return NULL;
        }
        for(Node* ptr = head; ptr != NULL;ptr=ptr->next->next) 
        {
            Node* newnode = new Node(ptr->val);
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next->next) 
        {
            Node* newnode = ptr->next;
            newnode->random = (ptr->random != NULL) ? ptr->random->next : NULL;
        }
        Node* newhead = head->next;
        for (Node* ptr=head; ptr != NULL; ptr = ptr->next) 
        {
            Node*node = ptr->next;
            ptr->next = ptr->next->next;
            node->next = (node->next != NULL) ? node->next->next : NULL;
        }
        return newhead;
    }
};
int main()
{

	system("pause");

	return 0;
}