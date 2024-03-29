//dfs超出内存了 
#include<bits/stdc++.h>

using namespace std; 

const int N=1000;

int g[N][N];

int st[N][N];

int dx[]={-1,1,0,0,1,1,-1,-1};
int dy[]={0,0,-1,1,1,-1,-1,1};//八个方向（新增左上左下右上右下）
int n;

void dfs(int x,int y,bool &h,bool &l)//这里必须引用！
{
	st[x][y]=1;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<n)
		{
			if(g[nx][ny]<g[x][y])l=true;//有比他更低的
			else if(g[nx][ny]>g[x][y])h=true;//有比他更高的
			else if(g[nx][ny]==g[x][y]  && !st[nx][ny])
			{
				dfs(nx,ny,h,l);
			}
		}

	}
		
}

int main()
{
	cin>>n;
	int peak=0,valley=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);	
		}	
		
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(!st[i][j])
			{
				bool h=false;
				bool l=false;
				dfs(i,j,h,l);
				if(!h)peak++;//cout<<i<<""<<j<<endl;
				if(!l)valley++;//cout<<i<<""<<j<<endl;
			}
		}
	cout<<peak<<" "<<valley;
	return 0;
}
