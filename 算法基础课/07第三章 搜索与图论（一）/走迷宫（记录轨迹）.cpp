//最短路问题（只有边权都是1的时候，才能用bfs（时间复杂度比较高）） 
//最短路问题包含DP问题 
//DP问题是一个没有环存在的最短路问题
 
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
const int N=101;
int n,m;
int g[N][N];//地图 
int d[N][N];//起点到终点的距离 
PII q[N*N],Prev[N][N];//坐标、记录之前的位置 

int bfs()
{
	int hh=0,tt=0;
	q[0]={0,0};
	memset(d,-1,sizeof d);//-1代表没有走过 
	d[0][0]=0; 
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(hh<=tt)
	{
		auto t=q[hh++];//每次取出队头 
		for(int i=0;i<4;i++)
		{
			int x=t.first+dx[i],y=t.second+dy[i];//走下一步
			if(x>=0 && x<n && y<m && y>=0 && g[x][y]==0 && d[x][y]==-1)//不越界、可以走、并且没有走过
			{
				d[x][y]=d[t.first][t.second]+1;
				Prev[x][y]=t;//x、y是已经走过的t，所以说t是x、y之前的状态 
				q[++tt]={x,y};//存进去当前走过的坐标
			}
		}	
	}
	int x=n-1,y=m-1;
	while(x || y)
	{
		cout<<x<<" "<<y<<endl;
		auto t=Prev[x][y];
		x=t.first,y=t.second;
	}
	return d[n-1][m-1];
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
			
	cout<<bfs()<<endl;
	return 0;
}
