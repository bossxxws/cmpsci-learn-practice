#include<bits/stdc++.h>

using namespace std;

int n,m,k;

//如何表示当前状态： 
//皮卡丘的体力和精灵球的个数可以表示当前的状态（也许吧） 

const int K=103;

const int N=1003,M=503;

int c[K],h[K];//收服精灵需要的精灵球的数量以及皮卡丘受到的伤害

int f[K][N][M];//f[k][i][j]表示捕捉k个精灵、精灵球个数为i，皮卡丘体力为j的情况下能收服的精灵的最大数量

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&c[i],&h[i]);
	}
	//cout<<1; 
	//发现也是个01背包问题，只不过集合的属性是收服的精灵的数量的最大值
	//并且有两个限制：精灵球和体力值
	//之前只有一个限制那就是背包容积 
	
	int res=-1,t=1e9;
		
	for(int l=1;l<=k;l++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
			{
				f[l][i][j]=f[l-1][i][j];				
				if(i>=c[l] && j>=h[l])f[l][i][j]=max(f[l][i][j],f[l-1][i-c[l]][j-h[l]]+1);
				if(f[l][i][j]>res || (f[l][i][j]==res && j<t))
				{
					res=f[l][i][j];
					t=j;
				}				
			} 

//	for(int l=1;l<=k;l++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;i<=m;j++)
//			{
//				cout<<1;
//
//			}
			
	cout<<res<<" "<<m-t;
	return 0;
}
