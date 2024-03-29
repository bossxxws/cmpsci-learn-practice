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
        queue.reserve(k);//增加k容量
        size = k;//容量大小
        head = -1;//“哑结点”
        tail = -1;//“哑结点”
    }

    bool enQueue(int value)
    {
        if (isEmpty()) 
        {
            head++;
            tail++;
            queue[tail] = value;
            return true;
        }//如果为空初始化容器
        else if (isFull()) return false;//满则无法添加
        tail = (tail + 1) % size;//这样会让tail在超过size的时候变到第一个
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
            return true;//如果本来就是空的或者只有一个，那就清空
        }
        head = (head + 1) % size;//head向前移动（等于原来的head指向的数值被架空了）
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
        if ((tail + 1) % size == head) return true;//tail马上追上head的时候
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