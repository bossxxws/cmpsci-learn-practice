#include <iostream>
using namespace std;
#include<vector>

class MyCircularQueue 
{
private:
    vector<int> queue;
    int size;
    int head;
    int tail;
public:
    MyCircularQueue(int k) 
    {
        queue.reserve(k);//����k����
        size = k;//������С
        head = -1;//���ƽ�㡱
        tail = -1;//���ƽ�㡱
    }

    bool enQueue(int value)
    {
        if (isEmpty()) 
        {
            head++;
            tail++;
            queue[tail] = value;
            return true;
        }//���Ϊ�ճ�ʼ������
        else if (isFull()) return false;//�����޷����
        tail = (tail + 1) % size;//��������tail�ڳ���size��ʱ��䵽��һ��
        queue[tail] = value;
        return true;
    }

    bool deQueue() 
    {
        if (isEmpty()) return false;
        if (head == tail) 
        {
            head = -1;
            tail = -1;
            return true;//����������ǿյĻ���ֻ��һ�����Ǿ����
        }
        head = (head + 1) % size;//head��ǰ�ƶ�������ԭ����headָ�����ֵ���ܿ��ˣ�
        return true;
    }

    int Front() 
    {
        if (isEmpty()) return -1;
        return queue[head];
    }

    int Rear() 
    {
        if (isEmpty()) return -1;
        return queue[tail];
    }

    bool isEmpty() 
    {
        if (head == -1 && tail == -1)  return true;
        return false;
    }

    bool isFull()
    {
        if ((tail + 1) % size == head) return true;//tail����׷��head��ʱ��
        return false;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main()
{

	system("pause");

	return 0;
}