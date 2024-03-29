#include<bits/stdc++.h>

using namespace std;

const int MOD=9901;

typedef long long LL;

LL a,b;
LL res=0;

unordered_map<int,int>primes;

LL quickmi(LL a,LL b)
{
	LL res=1;
	while(b)
	{
		if(b&1)res=res*a%MOD;
		a=a*a%MOD;
		b=b>>1;
	}
	return res%MOD;
}

void divide(LL x)
{
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		{
		    while(x%i==0)
		    {
		        primes[i]++;
		        x/=i;
		    }
		}
	}
	if(x>1)primes[x]++;
}

//求p0+....pk-1 
LL sum(LL p,LL k)
{
	if(k==1)return 1;
	if(k%2==0)return (LL)(quickmi(p,k/2)+1)*sum(p,k/2)%MOD;
	return (LL)(quickmi(p,k-1)+sum(p,k-1))%MOD;
}

int main()
{
	cin>>a>>b;
	
	divide(a);
	
	LL res=1;
	
	for(auto prime :primes)
	{
		int p=prime.first;
		int k=prime.second*b;//p的次数 

		res=(LL)res*sum(p,k+1)%MOD;//求约数之和 
	}
	if(!a)res=0;
	cout<<res<<endl; 
	
	return 0;
}
