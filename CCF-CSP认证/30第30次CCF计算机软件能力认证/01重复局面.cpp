#include <iostream>

using namespace std;

const int N = 101;

char g[N][10][10];

int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            for (int k = 1; k <= 8; k++)
            {
                cin >> g[i][j][k]; // 读入成功
            }
        }
        // 开始处理
        int r = i;
        int cnt = 1; // 自己不判定了

        for (int l = 1; l <= r - 1; l++)
        {
            bool flag = true;
            // 开始判定l步图和i是否一样
            for (int di = 1; di <= 8; di++)
            {
                if (!flag)
                    break;
                for (int dj = 1; dj <= 8; dj++)
                {
                    if (g[l][di][dj] != g[i][di][dj])
                        flag = false;
                }
            }
            if (flag)
                cnt++;
        }
        cout << cnt << endl;
    }
    // 图没问题
    //  for (int i = 1; i <= n; i++)
    //  {
    //      cout << "第" << i << "步" << endl;

    //     for (int j = 1; j <= 8; j++)
    //     {
    //         for (int k = 1; k <= 8; k++)
    //         {
    //             cout << g[i][j][k];
    //         }
    //         cout << endl;
    //     }
    // }

    // cout << 1 << endl;
    return 0;
}