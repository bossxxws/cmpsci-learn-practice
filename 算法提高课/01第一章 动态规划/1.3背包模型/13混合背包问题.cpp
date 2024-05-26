#include<bits/stdc++.h>

using namespace std;

const int N=100010;

int v[N],w[N],s[N];
int chmodv[N];
int chmodw[N];
int f[N];

//将完全背包转化为多重背包（能取无数次相当于有背包体积/v个物品）
//-1 01 0 完全 >0 多重

int n,m;//m是背包容积
int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {

        cin>>v[i]>>w[i]>>s[i];
        if(s[i]==-1)s[i]=1;//01背包转化为多重背包
        else if(s[i]==0)s[i]=m/v[i];//完全背包转化为多重背包

    }

    //二进制优化(朴素写法要三重循环，在第三重循环枚举s[i])
    //二进制优化后，多个物品被打包，相当于01背包问题
    //所以只需要01背包的做法（二重循环）
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int k=1;//用来二进制打包
        while(k<=s[i])
        {
            chmodv[cnt]=v[i]*k;
            chmodw[cnt]=w[i]*k;
            s[i]-=k;
            k*=2;
            cnt++;
        }
        if(s[i]>0)
        {
            chmodv[cnt]=s[i]*v[i];
            chmodw[cnt]=s[i]*w[i];
            cnt++;
        }
    }///二进制优化完成

//    朴素写法
//    for(int i=1;i<=cnt;i++)//这时候是多个物品打包在一起，做法和01背包一样
//    {
//        for(int j=0;j<=m;j++)
//        {
//            f[i][j]=f[i-1][j];
//            if(j>=chmodv[i])f[i][j]=max(f[i][j],f[i-1][j-chmodv[i]]+chmodw[i]);
//        }
//
//    }

//  滚动数组写法(可以储存更多的状态，如果是二维存储的状态不够用)

    for(int i=1;i<=cnt;i++)
    {
        for(int j=m;j>=chmodv[i];j--)
        {
            f[j]=max(f[j],f[j-chmodv[i]]+chmodw[i]);
        }
    }


    cout<<f[m];

    return 0;
}
