#include<bits/stdc++.h>

using namespace std;

const int N=53;

int f[N][N];

int ne[N];//next数组 

char str[N];//字串 

const int mod=1e9+7;

int main()
{
	int n,m;
	
	cin>>n>>str+1;
	
	m=strlen(str+1);
	
	//kmp求next表模板
	for(int i=2,j=0;i<=m;i++)
	{
		//不匹配的情况 
		while(j && str[j+1]!=str[i])
		{
			j=ne[j]; 
		}
		 
		//匹配的话则最大公共前后缀+1
		if(str[j+1]==str[i])j++;
		
		//给next表赋值 
		ne[i]=j; 
	} 
	
	//dp+状态机 
	f[0][0]=1;//已经匹配了0位，且匹配到的字符串位置（状态）是0的方案数
	
	for(int i=0;i<n;i++)//枚举密码位 
	{
		for(int j=0;j<m;j++)//枚举第i位密码在模板串中的位置	
		{
			for(int k='a';k<='z';k++)//枚举第i+1位的字符
			{
				//匹配过程:寻找当第i+1的位置是k时,并且密码已经生成了第i位,已经匹配的子串的位置是j时,能跳到哪个位置
				int u=j;
				while(u && str[u+1]!=k)u=ne[u];		
				
				if(str[u+1]==k)u++;
				if(u<m)f[i+1][u]=(f[i+1][u]+f[i][j])%mod;//因为不能包含字串，所以不能等于m
			} 
		} 
	} 
	
	int res=0;
	for(int i=0;i<m;i++) res=(res+f[n][i])%mod;
    //将所有的方案数加起来即为总方案数
    printf("%d",res);
	
	return 0;
}
