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
	//ö����ߵ�һ�������λ���������õĸ����ٵ���߽� 
	stk[++tt]=0;//����߽�ӽ�ȥ 
	for(int i=1;i<=m;i++)
	{
		while(a[i]<=a[stk[tt]])tt--;//ջ��Ԫ�ش��ڵ��ڵ�ǰԪ�صĻ�����ջ�� 
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
		
		g[r][c]=1;//���Ϊ�ƻ� 
		
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==0)
			{
				h[i][j]=h[i-1][j]+1;
			}
		}//��¼��һλ���������õĸ����Ƕ��� 
	
	int res=0;
	
	for(int i=1;i<=n;i++)
	{
		res=max(res,work(h[i]));
	}
	cout<<res;
	return 0;
} 
