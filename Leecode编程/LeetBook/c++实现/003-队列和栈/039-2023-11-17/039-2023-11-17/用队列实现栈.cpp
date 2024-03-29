#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class MyStack 
{
private:
    queue<int>q;
    int res;
public:

    MyStack() 
    {
        
    }

    void push(int x) 
    {
        q.push(x);
    }

    int pop() {
        int ret = q.back();
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();

        return ret;
    }



    int top()
    {
        return q.back();
    }

    bool empty() 
    {
        return q.empty();
    }
};
int main() 
{
	return 0;
}