#include<bits/stdc++.h>

using namespace std;

int n,m; 

const int N=33;
int g[N][N];
int a[N][N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	memcpy(a,g,sizeof a);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			if(i+2<=m && j+2<=m)
//			{
//				if(g[i][j]==g[i+1][j]==g[i+2][j] &&
//				   g[i][j]==g[i][j+1]==g[i][j+2]  )
//				   {
//				   		g[i][j]=g[i+1][j]=g[i+2][j]
//				   		=g[i][j]=g[i][j+1]=g[i][j+2]=0;
//				   }
//			}
//			else if(i+2<=m)
//			{
//				if(g[i][j]==g[i+1][j]==g[i+2][j])
//				{
//					
//				}
//			}
			int ix=0;
			bool fx=false;
//			cout<<"_____"<<endl;
			while(i+ix<=n && a[i][j]==a[i+ix][j])//������ͬ
			{
				ix++;
			} 
//			cout<<"_____"<<endl;
			if(ix>=3)
			{
				fx=true;
				int xx=i+ix-1;
				for(int l=i+1;l<=xx;l++)//ԭλ�������ţ������� 
				{
					g[l][j]=0;
				}
			}
			
			int jy=0;
			bool fy=false;
			
			while(j+jy<=m && a[i][j]==a[i][j+jy])//������ͬ
			{
				jy++;
			} 
			if(jy>=3)
			{
				fy=true;
				int yy=j+jy-1;
				for(int l=j+1;l<=yy;l++)//ԭλ�������ţ������� 
				{
					g[i][l]=0;
				}
			}
			
			if(fx || fy)g[i][j]=0;
			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
