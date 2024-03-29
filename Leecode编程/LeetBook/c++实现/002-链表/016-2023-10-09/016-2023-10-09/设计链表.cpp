#include <iostream>
using namespace std;
#include<vector>
class MyLinkedList {
    struct L
    {
        int val;
        L* next;
        L(int x) :val(x), next(nullptr) {}
    };
    L* head;
    int l;
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new L(0);
        l = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= l || index < 0)
            return -1;
        L* ptr = head;
        for (int i = 0; i <= index; i++)//照这样说，head组是第-1个组，索引返回对应索引的组，2返回2组的值，0返回0组的值（实际上是第一个组）
        {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        L* ptr = new L(val);
        ptr->next = head->next;
        head->next = ptr;
        l++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        L* ptr = new L(val);
        L* n = head;
        for (int i = 0; i < l; i++)
        {
            n = n->next;
        }
        n->next = ptr;
        l++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index<0 || index>l)
            return;
        L* ptr = head;
        L* ins = new L(val);
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ins->next = ptr->next;
        ptr->next = ins;
        l++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= l)
            return;
        L* ptr = head;
        L* del;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        del = ptr->next;
        ptr->next = del->next;
        delete del;
        l--;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{

	system("pause");

	return 0;
}