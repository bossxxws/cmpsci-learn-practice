#include<bits/stdc++.h>

using namespace std;

const int N=503;

int w[N];

int v[N];

int s[N];

const int M=6003;

long long  f[N][M];

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    //多重背包问题，每个物品的个数是有限的

    for(int i=1;i<=n;i++)
    {

        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    }


    for(int i=1;i<=n;i++)//枚举种类
    {

        for(int j=0;j<=m;j++)//枚举体积
        {

            for(int k=0;k<=s[i];k++)//枚举该物品购买的数量，购买的个数必须小于当前物品的数量
            {
                f[i][j]=max(f[i][j],f[i-1][j]);//这句话没必要，因为f[i][j]必然大于f[i][j-1]

                //因为在下面枚举k=0的时候，f[i-1][j-k*v[i]]+k*w[i]==f[i-1][j]
                //则下面的f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i])转化为f[i][j]=max(f[i][j],f[i-1][j])
                //已经包括了：f[i][j]=max(f[i][j],f[i-1][j])这个状态

                if(k*v[i]<=j)f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);

            }
        }
    }


    cout<<f[n][m];
    return 0;
}
