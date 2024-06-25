#include <iostream>
using namespace std;
class MyLinkedList {
private:
    struct node {
        int val;
        node* pre;
        node* next;
        node(int _val) {
            val = _val;
            pre = NULL;
            next = NULL;
        }
    };
    int size;
    node* head;
public:
    MyLinkedList() {
        size = 0;
        head = new node(0);
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        node* cur = head->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        node* newnode = new node(val);
        if (head->next)
            head->next->pre = newnode;
        newnode->next = head->next;
        newnode->pre = head;
        head->next = newnode;
        size++;
    }

    void addAtTail(int val) {
        node* cur = head;
        node* newnode = new node(val);
        while (cur->next)
            cur = cur->next;
        cur->next = newnode;
        newnode->pre = cur;
        newnode->next = NULL;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else if (index > size)
            return;
        else {
            node* cur = head->next;
            node* newnode = new node(val);
            while (index--)
                cur = cur->next;
            newnode->next = cur;
            newnode->pre = cur->pre;
            cur->pre->next = newnode;
            cur->pre = newnode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        node* cur = head->next;
        while (index--)
            cur = cur->next;
        if (cur->next) {
            cur->next->pre = cur->pre;
            cur->pre->next = cur->next;
        }
        else {
            cur->pre->next = NULL;
        }
        delete cur;
        size--;
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