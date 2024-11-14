#include <iostream>

using namespace std;

int n, m, k;

const int N = 1e5 + 3;

int t[N], c[N], q[N];

int a[N], b[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i]; // 表示一项出行计划 ti时刻需要ci时间内的结果
        a[i] = t[i] - k;
        b[i] = t[i] - c[i] - k + 1;
        // cout<<a[i]<<" "<<b[i]<<endl;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> q[i]; // 查询q时刻能满足多少项出行
                     // 处理每一个查询
                     // cout<<q[i]<<"ooo"<<endl;
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (q[i] <= a[j] && q[i] >= b[j])
            {
                // cout<<"!!"<<q[i]<<" "<<a[i]<< endl;
                // cout<<i<<endl;
                cnt++;
            }
            // cout<<i<<endl;
        }
        cout << cnt << endl;
    }

    return 0;
}