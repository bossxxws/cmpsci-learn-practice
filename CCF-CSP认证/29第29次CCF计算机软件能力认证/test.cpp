#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> a;
    pair<int, int> b(1, 5);
    pair<int, int> d(1, 2);
    pair<int, int> c(6, 1);

    a.push(d);
    a.push(c);
    a.push(b);

    while (!a.empty())
    {
        cout << a.top().first << " " << a.top().second << endl;
        a.pop();
    }

    return 0;
}