#include <iostream>
using namespace std;
#include<queue>
//定义滑动窗口的大小，每次添加val值如果大于窗口大小那就老东西先滚出去
//老东西滚出去之后再算移动平均值
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