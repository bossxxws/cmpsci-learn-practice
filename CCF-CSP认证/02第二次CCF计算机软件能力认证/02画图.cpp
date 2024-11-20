#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=103;

int g[N][N];

int cnt;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		
		for(int j=x1;j<x2;j++)
		{
			for(int k=y1;k<y2;k++)
			{
				g[j][k]=1;
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
		    if(g[i][j])cnt++; 
		}
	}
	
	cout<<cnt;
	return 0;
}
