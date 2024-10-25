#include <iostream>

using namespace std;

int n, x;

const int N = 3e5 + 10;

int sum;

int a[33];

int f[33][N];

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int v = sum - x;             // 要使得这个值尽量大
    for (int i = 1; i <= n; i++) // 枚举n本书
    {
        for (int j = 0; j <= v; j++)
        {
            // 不选i的情况
            f[i][j] = f[i - 1][j];
            // 选i的情况
            if (j >= a[i])
                f[i][j] = max(f[i - 1][j - a[i]] + a[i], f[i][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= v; i++)
        res = max(res, f[n][i]);
    // cout<<res<<endl;
    cout << sum - res;
    return 0;
}