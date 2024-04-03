#include<bits/stdc++.h>

using namespace std;

const int N=1005;

int a[N][N];
int b[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
	//求前缀和区域：小的坐标的减一
	//求差分： 大的坐标的加一 
	b[x1][y1]+=c;
	b[x2+1][y1]-=c;
	b[x1][y2+1]-=c;
	b[x2+1][y2+1]+=c;
}

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			insert(i,j,i,j,a[i][j]);//构建差分矩阵
			
	while(q--)
	{
		int x1,y1,x2,y2,c;
		cin>>x1>>y1>>x2>>y2>>c;
		
		insert(x1,y1,x2,y2,c);	
	} 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
