/*

！！！正着算时间复杂度高，而且还要用map（因为nxn的矩阵放不下）
不如倒着算（矩阵的乘法结合律）
倒着算先得出的是一个dxd的矩阵
这下就不用开map了，而且乘法的时间复杂度大大减小

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d;
ll Q[10000 + 10][21];
ll K[21][10000 + 10];
ll V[10000 + 10][21];
ll W[10000 + 10];

int main()
{
    cin >> n >> d;
    ll m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> m;
            Q[i][j] = m;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> m;
            K[j][i] = m;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> m;
            V[i][j] = m;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
    }
    ll res[21][21];
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int z = 1; z <= n; z++)
            {
                res[i][j] += K[i][z] * V[z][j];
            }
        }
    }
    ll res2[10010][21];
    memset(res2, 0, sizeof(res2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int z = 1; z <= d; z++)
            {
                res2[i][j] += Q[i][z] * res[z][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            res2[i][j] *= W[i];
            cout << res2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
