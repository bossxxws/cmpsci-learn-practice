#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;

int n,m;

char a[N],b[N];

int f[N][N];//从a【i】变到b【j】所需要编辑的次数 
/*
10
AGTCTGACGC
11
AGTAAGTAGGC

4
*/
int main()
{

	scanf("%d%s%d%s",&n,a+1,&m,b+1);
	
	for(int i=0;i<=n;i++)f[i][0]=i;//删
	for(int i=0;i<=m;i++)f[0][i]=i;//增

    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{

			//无非是三种状态取最小值
			//改的时候要特判，如果结尾一样就不需要操作了
			//不一样则操作步骤+1 
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);//增、删 
			
			if(a[i]==b[j])f[i][j]=min(f[i][j],f[i-1][j-1]);
			else f[i][j]=min(f[i][j],f[i-1][j-1]+1);//改 
			
		}
		 
	cout<<f[n][m];
	
	return 0;	
} 
