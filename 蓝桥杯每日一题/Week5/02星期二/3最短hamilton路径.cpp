#include<bits/stdc++.h>

using namespace std;

const int N=20,M=1<<20;

int n;

int w[N][N];

int f[M][N];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	//状态压缩dp 
	memset(f,0x3f,sizeof f);
	//初始为0
	f[1][0]=0;//i==1表示第一个点已经走了，j==0表示目前在第一个点 
	//从0000.。。1开始 
	for(int i=1;i<1<<n;i++)
	{
		//从起点0开始 
		for(int j=0;j<n;j++)
		{
			//只有i包含j这个点，才能从i这个状态转移到终点为j的状态 
			if(i>>j&1)
			{
				//f[i][k]---k-j
				for(int k=0;k<n;k++)
				{
					if((i-(1<<j))>>k&1)
					{
						//(用不包含j点的状态来转移)
						f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
					}
				}
			}
		}
	}
	
	int res=1<<31-1;
	
	//for(int i=1;i<n;i++)
	//{
	//	res=min(res,f[(1<<n)-1][i]);
	//}
	
	//cout<<res<<endl;
	
	//标明了终点是n-1，所以说直接选终点是n-1的情况 
	cout<<f[(1<<n)-1][n-1];
	return 0;
}
