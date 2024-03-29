//暴力做法
/*
int res=0;
for(int i=0;i<n;i++)//枚举第一个数
    for(int j=0;j<i;j++)//枚举第二个数
    {
        res=max(res,a[i]^a[j]);
    }
*/
#include<bits/stdc++.h>;

using namespace std;

int n;
const int N=1e5+10,M=N*30;
int a[N];
int son[M][2],idx=0;

void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
}

int  query(int x)
{
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(son[p][!u])
        {
            res=res*2+1;
            p=son[p][!u];
        }
        else
        {
            res=res*2+0;
            p=son[p][u];
        }

    }
    return res;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,query(a[i]));
    }
    cout<<res;
    return 0;
}
