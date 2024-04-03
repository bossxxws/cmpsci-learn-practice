	#include<bits/stdc++.h>
	
	using namespace std;
	
	int p,q;
	
	int dfs(int m,int p,int q)
	{
		
		if(!m)return true;
		if(m>=p && dfs(m-p,p,q))return true;
		if(m>=q && dfs(m-q,p,q))return true;
		
		return false;
	}
	
	int main()
	{
		cin>>p>>q;
		
	
		int t=0;
		for(int i=1;i<10000;i++)
		{
			if(!dfs(i,p,q))t=i;
		}
		cout<<t;
		return 0;
	}
