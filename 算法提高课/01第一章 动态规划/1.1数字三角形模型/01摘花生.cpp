#include<bits/stdc++.h>

using namespace std;

int t;

int r,c; 

const int N=103;

int a[N][N];

int f[N][N];//表示走到i j的时候摘得花生的最多值 

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				scanf("%d",&a[i][j]);
			}
		
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				
				f[i][j]=max(f[i][j],max(f[i-1][j]+a[i][j],f[i][j-1]+a[i][j]));
			}
		cout<<f[r][c]<<endl;
	}
	return 0;
}
