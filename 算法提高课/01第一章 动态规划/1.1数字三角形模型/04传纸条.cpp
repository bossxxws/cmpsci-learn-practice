#include<bits/stdc++.h>

using namespace std;

const int N=12;

int a[N][N];

int f[N*2][N][N]; 

int main()
{
	//只能向右下角行走
	
	int n;
	cin>>n;
	
	int r,c,v;
	
	while(cin>>r>>c>>v && (r || c ||v))
	{
		
		a[r][c]=v;//行和列编号从1开始 
		
	} 


	//两条路径一共走了k步，i1是第一条路径的横坐标，i2是第二条路径的横坐标 
	//通过i1、i2和k可以推出各自的纵坐标
	//共有四种情况：
	//1:1从左边来，2从左边来
	//2:1从左边来，2从上面来
	//3:1从上面来，2从左边来
	//4:1从上面来，2从上面来 
	for(int k=2;k<=2*n;k++)
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++)
			{
				int j1=k-i1,j2=k-i2;
				
				if(j1>=1 && j2>=1 && j1<=n && j2<=n)
				{
					int t=a[i1][j1];
					if(i1!=i2)t+=a[i2][j2];
					int &x=f[k][i1][i2];
					
					//1
					x=max(x,f[k-1][i1-1][i2-1]+t);
					//2
					x=max(x,f[k-1][i1-1][i2]+t);
					//3
					x=max(x,f[k-1][i1][i2-1]+t);
					//4:都从上面来j1-1  j2-1 
					x=max(x,f[k-1][i1][i2]+t);
					
				}
			}

	
	cout<<f[2*n][n][n];
	
	return 0;
	
}
