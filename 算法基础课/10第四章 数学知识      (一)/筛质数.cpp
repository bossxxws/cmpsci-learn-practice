/*
//朴素版写法 
//时间复杂度：O（nlogn） 
#include<bits/stdc++.h>

using namespace std;


const int N=1e6+10;


int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=n;
		}
		for(int j=i+i;j<=n;j+=i)
    	{
    		st[j]=true;
    	}
	}

}
 
int main()
{
    int n;
    cin>>n;
    get_primes(n);
    
    cout<<cnt<<endl;
    return 0;
}

*/

//--------------------------------------------------------------------------------
/*
//优化版
//埃氏筛法 
//时间复杂度：O（nloglogn） 
#include<bits/stdc++.h>

using namespace std;


const int N=1e6+10;


int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=n;
			for(int j=i+i;j<=n;j+=i)
        	{
        		st[j]=true;
        	}
		}

	}

}
 
int main()
{
    int n;
    cin>>n;
    get_primes(n);
    
    cout<<cnt<<endl;
    return 0;
}

*/

//------------------------------------------------------------------------------
//线性筛法  O（n）           1e7级别比埃氏筛法快一倍 
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int primes[N],st[N],cnt;


//合数一定可以被质因子分解 
void get_primes(int n)
{
    for(int i=2;i<=n;i++)//从2开始测试n之前的质数 
    {
        if(!st[i])primes[cnt++]=i;//如果之前没有被筛掉，就存到质数表primes中 
    	for(int j=0;primes[j]<=n/i;j++)//从小到大枚举质数，停止条件是 质数*i小于等于n 
    	{
    		st[primes[j]*i]=true;//标记为是合数，筛掉primes[j]*i（最小质因子是primes[j]） 
    		if(i%primes[j]==0) break;
			//1.i%primes[j]==0,primes[j]一定是i的最小质因子								 
			//  primes[j]一定是primes[j]*i的最小质因子 
			
			
			//2.i%primes[j]！=0，primes[j]一定小于i的最小质因子（因为我们是从小到大枚举的所有质数） 
			//  primes[j]也一定是primes[j]*i的最小质因子 
			//  这种情况下继续，用更大的质因子，直到primes[j]是i的最小质因子 
    	}
    }

}

int main()
{
	int n;
	cin>>n;
	
	get_primes(n);
	
	cout<<cnt<<endl;
	
	return 0;
} 

