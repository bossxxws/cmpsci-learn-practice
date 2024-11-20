#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char ch, p;
        stack<char> op;
        stack<int> num;
        cin >> ch;
        num.push(ch - '0');
        for (int i = 1; i <= 3; i++)
        {
            cin >> p >> ch;
            if (p == '+' || p == '-') op.push(p), num.push(ch - '0');
            else
            {
                int t = num.top();
                num.pop();
                if (p == 'x') t *= (ch - '0');
                else t /= (ch - '0');
                num.push(t);
            }
        }
        int res = 0;
        while (!op.empty())
        {
            ch = op.top();
            op.pop();
            int a = num.top(); num.pop();
            if (ch == '+') res += a;
            else res -= a;
        }
        if (res + num.top() == 24) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

