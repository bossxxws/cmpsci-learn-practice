#include<bits/stdc++.h>

using namespace std;

const int N=12,M=17;

int n,m;//公司数量和机器数量

int g[N][M];

int f[N][M];



int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);//读入数据矩阵
        }

    //每个公司可以看作一个组，从每一组中选一个

    for(int i=1;i<=n;i++)//从前i组里面选
    {
        for(int j=1;j<=m;j++)//枚举体积(总共m台机器)
        {
            for(int k = 0;k <= j;k ++)
            {
                f[i][j]=max(f[i][j],f[i-1][j]);
                f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k]);
                //g[i][k]可以解读为体积为k，价值为g[i][k]
            }
        }
    }

    cout<<f[n][m]<<endl;


}
