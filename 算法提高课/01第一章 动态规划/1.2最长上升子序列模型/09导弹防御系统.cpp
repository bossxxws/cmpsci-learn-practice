#include<bits/stdc++.h>

using namespace std;

int a[N];


int DFS(int depth,)
{
	
}

int main()
{
	int n;
	
	while(cin>>n && n!=0)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		
		//由于情况比较复杂，状态难以表示（不重不漏地表示每一个状态） 
		//所以说使用DFS爆搜来包含每一种情况 
		
		//迭代加深||全局变量 
		
		int depth=0;
		
		while(!DFS(depth,0,0))depth++; 
		
		
		cout<<depth;
	} 
	return 0;
} 
