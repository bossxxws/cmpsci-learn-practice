#include<bits/stdc++.h>

using namespace std;

int n;

const int N=210;

int w[2*N];

int f[2*N][2*N];
int g[2*N][2*N];

int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i+n]=w[i];
	}
	
	//前缀和
	for(int i=1;i<=2*n;i++)
	{
		w[i]+=w[i-1];
	} 
	
	memset(f,-0x3f,sizeof f);
	memset(g, 0x3f,sizeof g);
	
	//区间dp
	for(int len=1;len<=n;len++)//枚举长度 
		for(int l=1;l+len-1<=n*2;l++)//枚举左端点 
		{
			int r=l+len-1;//算出右端点 
			//状态转移
			if(len==1)f[l][r]=g[l][r]=0;
			else
			{
				for(int k=l;k+1<=r;k++)//枚举分开点
				{
					
					f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+w[r]-w[l-1]); 
					g[l][r]=min(g[l][r],g[l][k]+g[k+1][r]+w[r]-w[l-1]);
					//cout<<l<<" "<<r<<" "<<g[l][r]<<endl; 
				} 
			}
		} 
		
    int minv = 0x3f3f3f3f, maxv = -0x3f3f3f3f;
    // cout<<0x3f<<endl;
    //cout<<minv<<endl;
    for (int l = 1; l <= n; ++ l)
    {
        minv = min(minv, g[l][l + n-1]);
        //cout<<g[l][l+n-1]<<endl;
        //cout<<minv<<endl;
        maxv = max(maxv, f[l][l + n-1]);
    }
    cout<<minv<<endl<<maxv<<endl;
    //cout<<g[n][n+3]<<endl;
	return 0;
}
