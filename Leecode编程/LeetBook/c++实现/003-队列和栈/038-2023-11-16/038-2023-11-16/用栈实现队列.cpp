#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        n = s1.size();
        for (int i = 0; i < n; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        a = s2.top();
        s2.pop();
        n = s2.size();
        for (int i = 0; i < n; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }

    int peek() {
        n = s1.size();
        for (int i = 0; i < n; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        a = s2.top();
        n = s2.size();
        for (int i = 0; i < n; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }

    bool empty() {
        if (s1.empty())
            return true;
        return false;
    }
private:
    stack<int>s1, s2;
    int n; int a;
};

int main() 
{
	return 0;
}