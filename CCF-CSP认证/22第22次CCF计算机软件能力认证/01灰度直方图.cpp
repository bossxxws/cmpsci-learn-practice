#include <bits/stdc++.h>

using namespace std;

int n, m;

const int N = 503;

int g[N][N];

int h[257];
int L;

int main()
{
    cin >> n >> m >> L;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];

            h[g[i][j]]++;
        }
    }

    for (int i = 0; i < L; i++)
    {
        cout << h[i] << " ";
    }

    return 0;
}