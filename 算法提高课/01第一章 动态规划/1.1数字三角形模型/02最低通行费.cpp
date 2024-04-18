#include<bits/stdc++.h>

using namespace std;

//状态表示：f[i][j]，表示走到i和j的最低费用

const int N=103;

int a[N][N];

int f[N][N];

int main()
{
	int n;
	
	cin >>n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	memset(f,0x3f,sizeof f);
	//在2n-1个时间出去，那就多一个维度表示时间
	
	//先初始化第一个需要的，可以避免初始化 
	f[0][0]=0;
	f[0][1]=0;
	f[1][0]=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j] = min({f[i][j], f[i][j - 1] + a[i][j], f[i - 1][j] + a[i][j]});
		}
	
	cout<<f[n][n];
	
	return 0;
}
