#include<bits/stdc++.h>

using namespace std;

const int N=32010; 

int n;

int g[N][N];

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x][y]=1;
	}
	
	
	
	return 0;
} 
