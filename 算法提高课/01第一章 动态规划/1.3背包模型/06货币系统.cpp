#include<bits/stdc++.h>

using namespace std;

const int N=18;

int w[N];

long long  f[N][3003];

int main()
{
    int n,m;
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    
    //完全背包问题
    
    //初始化
    
    f[0][0]=1;//0种面值组成0总价值的方案为1
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]+=f[i-1][j];
            if(j>=w[i])f[i][j]+=f[i][j-w[i]];
        }
    
    
    cout<<f[n][m];
    
    return 0;
}
