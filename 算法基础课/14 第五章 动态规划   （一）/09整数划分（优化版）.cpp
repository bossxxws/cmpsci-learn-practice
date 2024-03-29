//-------------------------------------------------
//完全背包直接删 一 维即可完 成二维 变 一维 的优化
//-------------------------------------------------
#include<bits/stdc++.h>

using namespace std;

const int N=1010;

const int MOD=1e9+7;

int f[N];//属性是数量 

int a[N][N];

int n;
//从1~i中选数字，总和为j的选法的数量 
int main()
{
	cin>>n;
	
	//总和为0的时候方案数为1
	
	for(int i=0;i<=n;i++)f[0]=1; 
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			//f[j]=[j]%MOD;
			
			if(j>=i)f[j]=(f[j]+f[j-i])%MOD;//f[i-1][j]表示不选i，总体积为i的方法
			//f[i][j-1]表示选i，总体积为j-i的方法（实际上是最后一步选i，j-i加上i等于j） 
			//也就是f[i][j-1]表示选i，总体积为i的个数（f[i][j]包含了f[i][j-1]这种状态） 
		}	
	
	cout<<f[n];
	
	return 0;
} 
