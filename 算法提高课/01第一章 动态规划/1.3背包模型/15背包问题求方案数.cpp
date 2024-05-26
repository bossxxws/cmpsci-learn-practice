#include<bits/stdc++.h>

using namespace std;

//01背包问题求方案数
//f[i]存储体积为i的时候的最高价值
//cnt[i]存储体积为i的时候的最高价值(f[i])对应的方案数

const int N=1003;

int f[N];
int cnt[N];

int v[N],w[N];

int mod=1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <= m; i ++)  cnt[i] = 1;//初始值全部设置为1
    //因为最高价值都可以为0，方案就可以有一种
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    for(int i=1;i<=n;i++)
    for(int j=m;j>=v[i];j--)
        {
            int value=f[j-v[i]]+w[i];
            if(value>f[j])//找到价值更高的方案
            {
                f[j]=value;
                cnt[j]=cnt[j-v[i]];
            }
            else if(value==f[j])
            {
                cnt[j]=(cnt[j]+cnt[j-v[i]])%mod;
            }
        }
    cout<<cnt[m];
    return 0;
}

