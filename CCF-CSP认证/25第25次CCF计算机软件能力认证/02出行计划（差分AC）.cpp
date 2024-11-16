#include <iostream>

using namespace std;

int n, m, k;

const int N = 2e5 + 3;

int t[N], c[N], q[N];

int a[N], b[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i]; // 表示一项出行计划 ti时刻需要ci时间内的结果
        a[i] = max(t[i] - k, 0);
        b[i] = max(t[i] - c[i] - k + 1, 0);
        q[a[i] + 1]--;
        q[b[i]]++;
        // cout<<a[i]<<" "<<b[i]<<endl;
    }
    for (int i = 1; i <= 200002; i++)
        q[i] += q[i - 1];
    for (int i = 1; i <= m; i++)
    {
        int X;
        cin >> X; // 查询q时刻能满足多少项出行
                  // 处理每一个查询
                  // cout<<q[i]<<"ooo"<<endl;

        cout << q[X] << endl;
    }
    // cout<<q[178];

    return 0;
}