//记忆化搜索
//每一道动态规划的题都可以用递归来写 

//记忆化搜索有一个前提是图是一个拓扑图（图中不存在环）
 
//本题一定不存在环
 
/*
状态表示： 	
	集合：f[N][N]表示所有从i、j开始滑的路径
	属性：最长轨迹MAX
	
状态计算：
	f[i][j]表示的所有的路径可以分为四类：向上滑、向下滑、向左滑、向右滑 
	四类的最大值取max就是f[i][j]的最大值 

*/ 

#include<bits/stdc++.h>

using namespace std;

const int N=302;

int n,m;	

int h[N][N];

int f[N][N];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

//搜索的过程
int dp(int x,int y)
{
	int &v=f[x][y];//引用后，所有写v的地方相当于写f[x][y]
	
	if(v!=-1)return v;//被搜过了直接返回
	
	//最小为1（经过1个区域---当前区域） 
	v=1;
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			//位置合法且高度低于起点 
			if(nx>=1 && ny>=1 && nx<=n && ny<=m && h[nx][ny]<h[x][y])
			{
				v=max(v,dp(nx,ny)+1); 
			}	
		} 
	return v;
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&h[i][j]);
		}
	//一般套路： 
	
	//1、把所有的状态初始化为-1（表示每个状态都没有被算过） 

	memset(f,-1,sizeof f);
	
	int res=0;
	
	//2、开始每个点搜索
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)//从每一个点出发 
		{
			res=max(res,dp(i,j));
		}
	
	cout<<res;
	
	return 0;
}

/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

25

*/
