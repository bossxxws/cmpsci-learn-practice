#include<bits/stdc++.h>

using namespace std;

const int N=47;

int n;
int st[N];

int dfs(int n)
{
	
	if(n==1)
	{
		if(!st[1])st[n]=1,cout<<0<<" ";
		return 0;
	}
	
	if(n==2)
	{
		if(!st[2] && !st[1])st[n]=1,st[1]=1,cout<<0<<" "<<1<<" ";
		else if(!st[2])st[2]=1,cout<<1<<" ";
		return 1;
	}
	
	int t= dfs(n-2)+dfs(n-1);
	if(!st[n])st[n]=1,cout<<t<<" ";
	return t;
}

int main()
{
	cin>>n;
	
	dfs(n);
		
	return 0;
 } 
