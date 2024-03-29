#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1e5+5;

int a[N],b[N];

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	
	//a是不是b的子序列
	int ans=0;int j=0;
	for(int i=0;i<m;i++)
	{
		while(a[j]!=b[i] && i<m)
		{
			i++;
		}
		if(j<n && i<m && a[j]==b[i])
		{
		    //cout<<i<<endl;
			ans++;
			j++;
		}
	} 
	/*
		或者这样写： 
		for(int i=0;i<m;i++)
		{
			if(j<n&&a[j]==b[i])j++;
		}
		if(j==n)cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	*/
	
	//cout<<ans;
	if(ans==n)cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	
	return 0;
} 
