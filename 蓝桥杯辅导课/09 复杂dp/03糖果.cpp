#include<bits/stdc++.h>

using namespace std;

const int N=103;

int f[N][N];//选择i种类，且j=总价值%MOD的集合中的最大值 

int a[N];

int n;
int MOD;

int main()
{
	
	scanf("%d%d",&n,&MOD);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	memset(f,-0x3f,sizeof f);
	
    f[0][0]=0;//0没有倍数，所以初始状态为0
	
	for(int i=1;i<=n;i++)
	{
	    
		for(int k=0;k<=MOD-1;k++)
		{
			f[i][k]=f[i-1][k];
			f[i][k]=max(f[i][k],f[i-1][((k-a[i])%MOD+MOD)%MOD]+a[i]);
		}
		
	}
	
	cout<<f[n][0]<<endl;
	//cout<<f[n][7]<<endl;
	return 0;
}
