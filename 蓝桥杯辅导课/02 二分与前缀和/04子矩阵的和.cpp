#include<bits/stdc++.h>

using namespace std;

const int N=1002;

int a[N][N];

//int s[N][N];

int n,m,q;

int main()
{
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
			
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		cout<<a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]<<endl;
	}
	
	return 0;
}
