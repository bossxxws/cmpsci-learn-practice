#include<iostream>

using namespace std;

typedef long long LL;

const int N=1e6+10;

int primes[N],cnt;

int phi[N];//存储欧拉函数 

bool st[N];


//线性筛法 
LL get_eulers(int n)
{
	phi[1]=1;// 从定义出发，1-1中和1互质的数只有1自己 
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
        	primes[cnt++]=i;
        	//如果这个数是质数，这个数的欧拉函数？ 
			//such as p，p就有p-1个互质的数（1-（p-1）） 
			//所以p的欧拉函数就是p-1 
        	phi[i]=i-1; 
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
        	st[primes[j]*i]=true;
        	if(i%primes[j]==0)
        	{
        		//此时pj*i的欧拉函数是什么？
				//此时pj是i的一个质因子
				//所以pj*i的所有质因子就是i的所有质因子
				//这时可以推出来（pj*i）的欧拉函数就是pj*（i的欧拉函数） 
				phi[primes[j]*i]=primes[j]*phi[i];
				break; 
        	}
        	//i%primes[j]!=0时
			//pj是i*pj的最小质因子
			//能得出（pj*i）的欧拉函数是i的欧拉函数*（pj-1） 
			phi[primes[j]*i]=phi[i]*(primes[j]-1);
        }
    }
    LL res=0;
    for(int i=1;i<=n;i++)res+=phi[i];
    return res;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<get_eulers(n);
}
