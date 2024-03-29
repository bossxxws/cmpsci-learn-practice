#include<bits/stdc++.h>

using namespace std;

const int N=3010;

int n,m,p;

int g[N][N],h[N][N];

int l[N],r[N];

int stk[N];

int work(int a[])
{
	a[0]=-1,a[m+1]=-1;
	int tt=0;
	//枚举左边第一个比这个位置上面能用的格子少的左边界 
	stk[++tt]=0;//把左边界加进去 
	for(int i=1;i<=m;i++)
	{
		while(a[i]<=a[stk[tt]])tt--;//栈顶元素大于等于当前元素的话弹出栈顶 
		l[i]=stk[tt];
		stk[++tt]=i; 
	} 
	
	tt=0;
	stk[++tt]=m+1;
	for(int i=m;i>=1;i--)
	{
		while(a[stk[tt]]>=a[i])tt--;
		
		r[i]=stk[tt];
		
		stk[++tt]=i;
	}
	int res=0;
	
	for(int i=1;i<=m;i++)
	{
		res=max(res,a[i]*(r[i]-l[i]-1));
	}
	return res;
}

int main()
{
	cin>>n>>m>>p;
	
	for(int i=0;i<p;i++)
	{
		int r,c;
		cin>>r>>c;
		
		g[r][c]=1;//标记为破坏 
		
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==0)
			{
				h[i][j]=h[i-1][j]+1;
			}
		}//记录这一位置上面能用的格子是多少 
	
	int res=0;
	
	for(int i=1;i<=n;i++)
	{
		res=max(res,work(h[i]));
	}
	cout<<res;
	return 0;
} 
