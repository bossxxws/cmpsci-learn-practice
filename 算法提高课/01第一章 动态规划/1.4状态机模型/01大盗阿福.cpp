#include<bits/stdc++.h>

using namespace std;

int t;

int n;

const int N=1e5+5,INF=0x3f3f3f3f;

int a[N];

int f[N][2];//f[i][j]中，i代表前i个金店的方案，j为1表示偷，j为0表示不偷

//转移方程：
//fi,1=fi−1,0+wi
//fi,0=max(fi−1,1,fi−1,0)

int main()
{
    cin>>t;

    while(t--)
    {
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];//输入每家金店的现金数量
        }

        //dp
        f[0][0]=0;
        f[0][1]=0;

        for(int i=1;i<=n;i++)
        {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            f[i][1] = f[i - 1][0] + a[i];
        }

         cout << max(f[n][0], f[n][1]) << endl;
    }




    return 0;
}
