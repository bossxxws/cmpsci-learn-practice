#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int w[N];

int n,m;

int f[N][3];

int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	
	//dp
	int res=0;
	memset(f,-0x3f,sizeof f);
	
	
	f[0][2]=0;
	
	for(int i=1;i<=n;i++)
	{
		
		//空仓一天的情况
		f[i][1]=f[i-1][0]+w[i];//上一支股票的持仓状态卖出  
		
		//空仓二天以及以上的情况 
		f[i][2]=max(f[i-1][2],f[i-1][1]);
		
		//持仓的情况 
		f[i][0]=max(f[i-1][0],f[i-1][2]-w[i]);
		
		//cout<<f[i][0]<<" "<<f[i][2]<<" "<<f[i][1]<<endl;
		
		//res=max(f[i][2],f[i][1]);
		
	}
	
	cout<<max(f[n][2],f[n][1]);

	//cout<<res;
	return 0;
}  
