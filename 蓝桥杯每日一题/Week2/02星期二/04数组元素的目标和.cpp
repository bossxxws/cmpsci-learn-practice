#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int n,m;
LL x;

int a[N],b[N];

int main()
{
	cin>>n>>m>>x;
	
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<m;i++)cin>>b[i];
	
	int l,r;
	for(int i=0,j=m-1;i<n;i++)
	{
		while((LL)a[i]+b[j]>x)j--;
		if((LL)a[i]+b[j]==x)
		{
			l=i;
			r=j;
		}
	}

	cout<<l<<" "<<r; 
	
	return 0;
} 
