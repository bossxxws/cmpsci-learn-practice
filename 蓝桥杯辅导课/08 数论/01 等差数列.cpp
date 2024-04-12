#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define x first
#define y second

const int N=100000+5;

LL res;

int gcd(int a,int b)
{
	return b?gcd(a%b,a):a;//任何数除0都是0，a和0的最大公约数就是a本身 
	//a=a%b
	//b=a
}

int a[N];
int n;
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//cout<<a[i]<<endl;
	}
	
	sort(a+1,a+n+1);
	
	int d=0;//求最大公约数，就是最大的d 
	
	
	//d=0的时候，res=n
	//d！=0，res=（末项-首项）/d +1 
	for(int i=1;i<=n;i++)d=gcd(d,a[i]-a[1]); 
/*
for(int i=2;i<=n;i++)
{
	if(a[i]-a[i-1]!=d)
	{
		int l=(a[i]-a[i-1])/d-1;

		res+=l;
	}
}
*/	
	if(d==0)res=n; 
	else
	{
		res=(a[n]-a[1])/d+1;
	}
	cout<<res;
	return 0;
}

