//完全背包问题，每样东西不只是可以取一次了
//可以取无数次 

//01背包  ：f[i,j]=max(f[i-1,j], **f[i-1,j-v]** +w])
//完全背包：f[i,j]=max(f[i-1,j], ** f[i,j-v] ** +w) 
//只有一点不一样

#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1010;

int f[N],v[N],w[N];

int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    //--------------------------------------------------------------------------
    //设第i个物品选了k个
    //f[i,j]=f[i-1,j-v[i]*k]+w[i]*k
    /*
    
    时间复杂度：O（n*v**2）
    朴素写法，会超时
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k*v[i]<=j;k++)
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
    
    cout<<f[n][m]<<endl;
    
    //--------------------------------------------------------------------------
    */
    
    
    //优化版
    //f[i,j]=Max(f[i-1,j],**f[i-1,j-v]+w,f[i-1,j-2v]+2w  .....,f[i-1,j-kv]+k*w[i]**)    
    //f[i,j-v]=Max(     **f[i-1,j-v]  ,f[i-1,j-2v]+ w, ..... f[i-1,j-kv]+(k-1)*w[i]**)
    //星号中的式子只相差一个w,直接替换
    //所以f[i][j]=Max(f[i-1][j],f[i][j-v]+w]
    
    
    /*
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    cout<<f[n][m]<<'\n';
    */
    
    //--------------------------------------------------------------------------
    //也可以优化为一维
    
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    cout<<f[m]<<"\n" ;
}
