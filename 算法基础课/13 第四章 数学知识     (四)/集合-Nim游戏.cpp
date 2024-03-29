#include<bits/stdc++.h>

using namespace std;

const int N=110,M=10010;

int s[N],f[M];

int n,m;

int sg(int x)//记忆化搜索
{
    if(f[x]!=-1)return f[x];
    
    unordered_set<int> S;//存储当前所有可以到的局面
    for(int i=0;i<m;i++)
    {
        int sum=s[i];//一下取多少
        if(x>=sum)S.insert(sg(x-sum));//当前可以到哪里
    }
    
    for(int i=0;;i++)
    {
        if(!S.count(i))return f[x]=i;//将i赋给fx然后返回
    }
}

int main()
{
    cin>>m;
    for(int i=0;i<m;i++)cin>>s[i];
    cin>>n;
    memset(f,-1,sizeof f);
    
    int res=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        res^=sg(x);
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
}
