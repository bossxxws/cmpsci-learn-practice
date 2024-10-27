#include <iostream>

#include <unordered_set>

using namespace std;

unordered_set<int> s;

int n;

int main()
{
    int n, k;
    cin >> k >> n;
    s.insert(0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;

        if (s.find(r) == s.end()) // 找不到，就是未初始化
        {
            cnt++;
        }
        s.insert(l);
    }
    cout << cnt;
    return 0;
}