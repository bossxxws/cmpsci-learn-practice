#include<bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

const int N=52;

typedef long long LL; 

int n,m,k;

int a[N][N];
int f[N][N][N][N];

LL ans=0; 

//首先确定维度 通过dfs可以知道一个状态可以由四个维度表示：
//坐标x 和 y 目前的宝贝最大值maxvalue 还有目前的宝贝数量cnt
//确定各自的范围：
//cnt==k的时候截止
//x=n && y=m 的时候截止 
//开始的状态是x==1 y==1 maxvalue==-1(因为刚开始手上没有宝贝，而有的宝贝价值为0，可以选可以不选) cnt==0 
//x [1 -- n]
//y [1 -- m] 
//maxvalue[-1 -- 12](取最大值)
//cnt[1 -- k] 


/*
（1）dp表的维度：即状态由几个变量唯一确定。
（2）确定表的各个维度的取值范围。
（3）确定目标值在dp表中的位置。
（4）根据递归终止条件，确定dp表的初始状态。
（5）确定dp表中任意一个位置的值与表中其他位置的依赖关系，即状态转移方程。
*/

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]++;
		}
	//f表示在i j这个位置，最大值为maxvalue，取到宝贝数为k的方案数 
	f[1][1][0][0]=1;//第一个位置不拿的方案数为1 
	f[1][1][a[1][1]][1]=1;//第一个位置拿的方案数为1 

	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			for(int maxvalue=0;maxvalue<=13;maxvalue++)//由于-1没有索引，所以说要从0开始，所有的宝贝价值+1 
				for(int cnt=0;cnt<=k;cnt++)
				{
					//可以取可以不取的情况 
					if(cnt>0 && maxvalue==a[i][j])//cnt>0表示取
					//当前这一步求的是f[i][j][maxvalue][cnt]中取了[i,j]位置宝物之后的状态，要保证a[i][j]==maxvalue，f[i][j][maxvalue][cnt]
					//取玩变成maxvalue的方案 
					{
						 
						//不取的时候能转移到 f[i][j][maxvalue][cnt]，说明上一个状态的最大值也是maxvalue 
						
						//取的时候，上一个状态的最大值一定小于maxvalue，并且可以直接转移到maxvalue 
						//我们把最大宝贝值小于maxvalue的、宝贝数为cnt-1的方案数遍历累加一遍
						//转移到最大宝贝值等于maxvalue、宝贝数为cnt的状态 
						for(int s=0;s<maxvalue;s++)
						{
							f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i][j-1][s][cnt-1])%MOD;
							f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i-1][j][s][cnt-1])%MOD;
						}
						
					}
					
					//不取的情况 
					f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i][j-1][maxvalue][cnt])%MOD; 
					f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i-1][j][maxvalue][cnt])%MOD;

				}
	LL res=0;
	for(int i=0;i<=13;i++)
	{
		res=(res+f[n][m][i][k])%MOD;
	} 
	cout<<res;
	return 0;
};
/*
2 2 2
1 2
2 1

2

2 3 2
1 2 3
2 1 5


14

*/


/*
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		cout<<a[i][j]<<" ";
	} 
	cout<<endl;
}
*/

