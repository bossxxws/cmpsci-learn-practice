#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int n;

int a[N];
int f[N];//以i结尾的子序列的最长长度 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=1;
	}
	int res=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])f[i]=max(f[i],f[j]+1);
			res=max(res,f[i]);
		}
		
	cout<<res;
	return 0;
} 
