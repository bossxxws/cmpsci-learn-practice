#include <iostream>

using namespace std;

int n, m;

const int N = 1003;

int d[N][13], father[N];
bool st[N];

int main()
{
    cin >> n >> m;

    // 读入仓库的数据
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j]; // 第i个仓库的编号范围是1~m
        }
    }
    // 枚举每一个仓库
    for (int i = 1; i <= n; i++)
    {
        int mini = 1e7;
        for (int em = 1; em <= n; em++)
        {
            bool flag = true;
            for (int k = 1; k <= m; k++)
            {
                // if(i==2)cout<<d[i][k]<<" "<<d[em][k]<<endl;
                if (d[i][k] >= d[em][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                mini = min(mini, em);
                st[i] = true;
                father[i] = mini;
            }
        }
        if (st[i])
            cout << father[i] << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}