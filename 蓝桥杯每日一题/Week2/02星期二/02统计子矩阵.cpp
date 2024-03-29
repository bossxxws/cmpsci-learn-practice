#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=502;

int a[N][N],s[N][N];

int n,m,k;


int main()
{
	cin>>n>>m>>k;
	
	LL res=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			//S F 检查半天！！！！ 
			//debug发现这里多输入一个%d,改完后成功AC 
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
		
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
		{
			for(int l=1,f=1;f<=n;f++)
			{
				while((s[f][j]-s[l-1][j]-s[f][i-1]+s[l-1][i-1])>k)
				{
					l++;
				}
				res+=f-l+1;
			}
		}	
	cout<<res;
	return 0;
} 
