#include<bits/stdc++.h>

using namespace std;

int n,k;

const int N=1e5+5;

int a[N];
int s[N];

int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	
	//开始处理区间
	int res=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]-s[i-1])%k==0)res++;
		}
	} 
	cout<<res<<endl;
	return 0;
} 
