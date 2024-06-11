#include <bits/stdc++.h>
// 也还是01背包问题，只不过有二个限制维度，一个价值维度
using namespace std;

// v和m的限制
// 目标：使得w最大

// f[i][j][k]表示选前i个物品，体积不超过j，重量不超过k的价值的状态的集合
// 属性：最大值

const int N = 1003;

const int M = 103;

int v[N], m[N]; // 体积和重量

int w[N]; // 价值

int f[N][M][M];

int main()
{
    int n, V, M;
    cin >> n >> V >> M;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &v[i], &m[i], &w[i]);
    }

    for (int i = 1; i <= n; i++) // 枚举第i个物品
    {
        for (int j = 0; j <= V; j++)
        {
            for (int k = 0; k <= M; k++)
            {
                f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
                if (j >= v[i] && k >= m[i])
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    cout << f[n][V][M];
    return 0;
}
