#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m; 

int a[N];

int q[N];

int hh,tt=-1;

//dp
int f[N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	//前0个烽火台的最小代价是0 
	f[++tt]=0;
	int res=1e9;
	for(int i=1;i<=n;i++)
	{
		//f[i]表示第i个烽火台点燃需要的最小代价
		//超出i-m范围则不合法 
		if(q[hh]<i-m)hh++;
		f[i]=f[q[hh]]+a[i];
		//维护单调性
		
		while(hh<=tt && f[i]<=f[q[tt]])tt--;
		q[++tt]=i; 
	}

	for(int i=n-m+1;i<=n;i++)res=min(res,f[i]);
	cout<<res;
	return 0;
} 
/*
5 3
1 2 5 6 2

4


*/
