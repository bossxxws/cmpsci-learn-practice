#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=20,M=1<<20;

int w[N][N];

int f[M][N];//M表示状态的压缩，N代表最后到哪一个城市了 

int main()
{
	cin>>n;
	memset(f,0x3f,sizeof f);//每个状态为正无穷，表示还没取min 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	f[1][0]=0;//初始的状态（需要费用为0） 
	//从1开始表示北京已经去过了 （二进制表示为000.....1） 
	for(int i=1;i<1<<n;i++)//（1<<n）-1就是111....1
	//例如n==5的时候，1<<5就是100000,减去1就是11111 
	{
		for(int j=0;j<n;j++)//北京开始 
		{
			//这个状态下（终点为j,状态为i） 
			if(i>>j&1)//（i>>j表示要到第j个城市，这个状态的j位就要是1（否则到不了）） 
			{
				for(int k=0;k<n;k++)//从第k个城市转移过来
				{
					if((i-(1<<j))>>k&1)//i中减去第j个城市后还包含k
					//说明这个状态到过k，可以从k转移过来
					f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]); 
				} 
			}
		}
	}
	int res=1<<31-1;
	for(int i=1;i<n;i++)
	{
		res=min(res,f[(1<<n)-1][i]+w[i][0]);
	}
	cout<<res;
	return 0;
} 
