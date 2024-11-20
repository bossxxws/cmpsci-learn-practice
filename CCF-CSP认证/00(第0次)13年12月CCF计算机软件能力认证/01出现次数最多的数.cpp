#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5+3;

int v[N];

int main()
{
	cin>>n;
	int minv=1e5;
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v[x]++;
	}
	
	int time=0;
	
	for(int i=1;i<=N;i++)
	{
		if(v[i]!=0 && v[i]>time)
		{
			minv=i;
			time=v[i];
		}
		else if(v[i]!=0 && v[i]==time && i<minv)
		{
			minv=i;
			time=v[i];
		}
	}
	
	cout<<minv;
	return 0;
} 
