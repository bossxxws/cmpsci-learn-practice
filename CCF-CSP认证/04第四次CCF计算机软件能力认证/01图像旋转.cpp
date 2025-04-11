#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1003;
int a[N][N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
