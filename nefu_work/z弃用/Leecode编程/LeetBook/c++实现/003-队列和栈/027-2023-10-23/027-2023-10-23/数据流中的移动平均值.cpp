#include <iostream>
using namespace std;
#include<queue>
//���廬�����ڵĴ�С��ÿ�����valֵ������ڴ��ڴ�С�Ǿ��϶����ȹ���ȥ
//�϶�������ȥ֮�������ƶ�ƽ��ֵ
class MovingAverage 
{
private:
    int size;
    queue<int>q;
    double sum;
public:
    MovingAverage(int size)
    {
        this->size = size;
        this->sum = 0.0;
    }

    double next(int val) 
    {
        if (q.size() == size) 
        {
            sum = sum - q.front();
            q.pop();
        }
        q.emplace(val);
        sum = sum + val;
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
int main()
{

	system("pause");

	return 0;
}