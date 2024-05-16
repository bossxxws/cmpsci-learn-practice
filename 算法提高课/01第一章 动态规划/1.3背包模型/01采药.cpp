//背包问题
//01背包问题 

#include<bits/stdc++.h>

using namespace std;

const int N=103;

int v[N],w[N];//体积v，价值w 

const int T=1010;//背包的最大容积是1000 

int t,m; 

int f[N][T];//注意第二个维度的大小是T 
//f[i][j]表示在挑选种数为i的情况下，总体积不超过j的价值的集合
//属性：max  
int main()
{
	scanf("%d%d",&t,&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
		//cout<<v[i]<<" "<<w[i]<<endl; 
	} 
	
	//开始状态转移 
	
	for(int i=1;i<=m;i++)//从选一种开始枚举 (总共m种)
		for(int j=0;j<=t;j++)//最大体积不能超过t 
		{
			f[i][j]=f[i-1][j];//不选第i个物品 
			
			if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);//选第i个物品 
		}
	
	cout<<f[m][t]<<endl;
	return 0;
} 
