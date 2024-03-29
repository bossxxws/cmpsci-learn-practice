#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1e5+5;

int a[N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a+1,a+n+1,greater<int>());
	
	int h=0;
	
	for(int i=1,j=n;i<=n;i++)
	{
		while(j && a[j]<i)j--;
		if(a[i]>=i-1 && i-j<=m)
		{
			h=i;
		}		
	}
	
	cout<<h;
	
	return 0;
}
