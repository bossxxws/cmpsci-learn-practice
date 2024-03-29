#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

//答案对1e9+7取模，所以说答案应该比较大，用long long
typedef long long LL;

int main()
{
	
	int n;
	cin>>n;
	
	unordered_map<int,int> primes;
	
	while(n--)
	{
		int x;
		cin>>x;
		
		for(int i=2;i<=x/i;i++)
		{
			while(x%i==0)
			{
				x/=i;
				primes[i]++;
			}
		}
		if(x>1)primes[x]++;
	}
	
	
	LL res=1;
	for(auto prime :primes)
	{
		int p=prime.first;
		int a=prime.second;

		
		/*
		自己写的 
		LL t=0;
		for(int i=0;i<=a;i++)
		{
			int tmp=p;
			while(i>0)
			{
				tmp*=tmp;
				i--;
			}
			t+=tmp;
		}
		t++;//0次方总是1，这里选择最后加上 
		res*=t;
		*/
		
		LL t=1;
		while(a--)t=(t*p+1)%mod;//这里就要mod防止溢出
		res=res*t%mod;//这里也要mod防止溢出
	}
	cout<<res<<endl;
	
	return 0;
}
