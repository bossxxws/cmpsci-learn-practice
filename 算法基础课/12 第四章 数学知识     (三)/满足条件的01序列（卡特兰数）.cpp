//比如说长度为12的01序列

//画一个二维表格

//0：向右走一格
//1：向上走一格

//y>=x

//不能碰到再往上一单位的线

//终点为（6，6）
//一共会往上走6步，往右走6步
//从12步里面挑6步向上 C 12 6

//踩红线
//轴对称一定是（5，7）
//一共会走12步，一定会往右走五步，往上走七步
//所以从12步里面挑5步，或者七步（C 12 5 ||  C 12 7 ）

//总数-不合法的路径

//C 12 6  -  C 12 5

//C 2n n  -  C 2n n-1

//整理后可以转化为 C 2n n / （n+1）     “这个问题被称为卡特兰数”


//*******        C 2n n / （n+1)       *******

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod=1e9+7;//这个是质数

//取模的数是质数，所以求逆元可以用费马小定理，不然只能用扩展欧几里得
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%p;
        a=(LL)a*a%p;
        k>>=1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    
    int a=2*n;
    int b=n;
    
    int res=1;
    
    int t=qmi(n+1,mod-2,mod);
    
    for(int i=a,j=1;j<=b;i--,j++)res=(LL)res *  i  %mod;//分子
    for(int i=b;i>=1;i--)res=(LL)res*  qmi(i,mod-2,mod)  %mod;//分母的逆元
    
    res=(LL)res*qmi(n+1,mod-2,mod)%mod;
    
    cout<<res;
    
    return 0;
}
