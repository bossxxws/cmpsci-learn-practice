#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1003;

char a[N],b[N];

int f[N][N]; 

int main()
{
	cin>>n>>m;
	
	int res=-1;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=m;i++)cin>>b[i];
	//for(int i=1;i<=m;i++)cout<<b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);//这两个都算过了 
			if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			res=max(res,f[i][j]);
		}
	cout<<res;
	return 0; 
}
