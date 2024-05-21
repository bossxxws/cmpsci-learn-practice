#include<bits/stdc++.h>

using namespace std;

const int N=28;

int v[N],w[N];

const int M=30003;

int f[N][M];

//01背包问题，状态集合存储的是w[i]*v[i]的值的和

int main()
{
    int t,m;

    cin>>t>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i];
    }


    for(int i=1;i<=m;i++)//枚举物品个数
        for(int j=0;j<=t;j++)
        {
            f[i][j]=max(f[i][j],f[i-1][j]);

            if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]*v[i]);
        }

    cout<<f[m][t];
    return 0;
}
