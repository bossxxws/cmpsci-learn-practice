#include<bits/stdc++.h>

using namespace std;


//答案对1e9+7取模，所以说答案应该比较大，用long long
typedef long long LL;

const int mod=1e9+7;


int main()
{
	int n;
	cin>>n;
	
	unordered_map<int,int> primes;//存储底数和指数 
	
	while(n--)
	{
		//分解每个数的质因数表达式 
		int x;
		cin>>x;
		
		//分解操作 
		for(int i=2;i<=x/i;i++)
		{
			while(x%i==0)
			{
				x/=i;
				primes[i]++;//i的质因数的指数+1 
			}
		}
		
		if(x>1)primes[x]++;//最后x除完还有就说明x本身是比较大的（也可以说特殊的）质因数，比如 5
		
	}	
	
	LL res=1;
	
	for(auto prime:primes)
	{
		res=res*(prime.second+1)%mod;//prime.second+1是因为n次方其实有n+1种选择（把0次方算上） 
	}
	
	cout<<res<<endl;
	
	return 0;
}
