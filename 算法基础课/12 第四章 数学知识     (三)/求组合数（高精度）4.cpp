//高精度组合数
//可以直接用高精度运算（大数运算） 
//但效率比较低
 
//我们采用分解质因数

/*
思路：
1、分解（该组合数的）质因数，转化为相乘的形式 
2、写一个高精度乘法
3、 运算 
*/ 

//求a！中 质数p的个数 ，每个被分解出来的素数都要求 
//res（a！）=[a/p]+[a/p**2]+........    一直加到p的若干次方比a大为止（【】表示向下取整） 

//1、筛质数，把5000以内的质数筛出来
//2、求每个质数的次数
//3、用高精度乘法把每个质因子相乘

#include<bits/stdc++.h>

using namespace std;

const int N=5010;

//筛质数模块
int primes[N],cnt;
bool st[N];

int sum[N];

void get_primes(int n)
{
    for(int i=2;i<=n;i++)//筛选n以内的质数
    {
        if(!st[i])primes[cnt++]=i;//存到质数表里
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j] == 0)break;
        }
    }
}


//求n！的阶乘中素数p的个数
int get(int n,int p)
{
    int res=0;
    while(n)//如果n为0则表示p的若干次方已经比n大
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

vector<int> mul(vector<int> a,int b)
{
    vector<int> c;
    int t=0;//表示进位的数
    for(int i=0;i<a.size();i++)//从个位开始做,前面存的是低位
    {
        t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    
    while(t)
    {
        c.push_back(t%10);
        t/=10;
    }
    
    return c;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    get_primes(a);
    
    //求每一个质数的次数
    for(int i=0;i<cnt;i++)
    {
        int p=primes[i];
        sum[i]=get(a,p)  -  (get(b,p)  +  get(a-b,p));//存一下当前这个数里面的p的次数是多少
        //这里因为得到的是次方数，又因为公式我们知道这是相除的，所以减去次方数即可
    }
    
    //用高精度乘法把每个质因子乘起来
    //tip：任何一个数可以表示为质数的次数相加，我们求出了该组合数中所有质数p的次数
    //     把这些次数相加即可，但由于数字太大，用高精度乘法
    
    vector<int>res;
    res.push_back(1);
    
    for(int i=0;i<cnt;i++)//从前往后枚举所有的质数
        for(int j=0;j<sum[i];j++)//枚举当前质数的次数（当前质数的次数是sum【i】）
            res=mul(res,primes[i]);//高精度乘法
            
    for(int i=res.size()-1;i>=0;i--)printf("%d",res[i]);//注意用正确格式输出答案，从后往前
    
    return 0;
}
