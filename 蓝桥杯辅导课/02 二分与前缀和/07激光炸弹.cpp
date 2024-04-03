#include<bits/stdc++.h>

using namespace std;

const int N=5004;

int g[N][N];
 
int res=0;

//以x1 y1 这个块为左上角，以x2 y2 这个块为右下角的 一个子矩阵内部的总和
int getas(int x1,int y1,int x2,int y2)
{
	//求前缀和区域：小的坐标的减一
	//求差分： 大的坐标的加一 
	return g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];	
} 

int main()
{
	int n,r;
	cin>>n>>r;
	r=min(r,5002);//边长最大才是N，所以爆炸区域取一个min 
	//读入地雷
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		g[x+1][y+1]+=w;

	}	
	for(int x=1;x<N;x++)
		for(int y=1;y<N;y++)
		{
			//cout<<x<<endl;
			//求前缀和：减一 
			g[x][y]+=g[x-1][y]+g[x][y-1]-g[x-1][y-1];
		}
	//枚举区域 
	//固定左界 
	for(int i=1;i<N-r;i++)
		for(int l=1;l<N-r;l++)//固定上界 
		{
            //窗口形成，左上角为i-r l-r 右下角为i，l
			res=max(res,getas(i,l,i+r-1,l+r-1));//r=1时相当于求他自己的矩阵前缀和
		}
	cout<<res;
	return 0;
}
