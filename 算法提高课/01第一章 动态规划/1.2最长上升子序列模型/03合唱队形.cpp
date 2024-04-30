#include<bits/stdc++.h>

using namespace std;

const int N=103;

int n;

int a[N]; 

int f[N];
int g[N]; 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	//至少需要几位同学出列，组成合唱队形？
	//合唱队形要求从前往后有上升子序列，从后往前有上升子序列	
	
	//那就是和登山差不多，求最高上升和下降-1，就是合唱队形最长的长度
	//然后用n减去就是要求的结果
	
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j])f[i]=max(f[i],f[j]+1);
		}
	}
	
	for(int j=n;j>=0;j--)
	{
		g[j]=1;;
		for(int i=n;i>j;i--)
		{
			if(a[j]>a[i])g[j]=max(g[j],g[i]+1);	
		}
		
	}

	int res=0;
	
	for(int i=1;i<=n;i++)res=max(res,f[i]+g[i]-1);
	
	cout<<n-res;
	
	return 0;
}
