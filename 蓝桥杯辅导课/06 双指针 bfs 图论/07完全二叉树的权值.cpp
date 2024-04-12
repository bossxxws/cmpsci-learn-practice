#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

//int h[N],e[N],ne[N],idx; 

int n;

typedef long long LL; 

LL a[N];

LL quickmi(LL x,LL k)
{
	LL res=1;
	while(k)
	{
		if(k&1)res=res*x;
		x=x*x;
		k>>=1;
	}
	return res;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	
	int res=-1;
	LL mv=-2e9;
	for(LL i=0;quickmi(2,i)<=n;i++)
	{
		LL j=i+1;
		LL s=quickmi(2,i);
		LL f=quickmi(2,j)-1;
		if(f>n)f=n;
		LL t=a[f]-a[s-1];
		if(t>mv)
		{
			mv=t;
			res=j;
		}
	
	}
	
	cout<<res;
	//cout<<quickmi(2,5)<<endl;
	return 0;
}
