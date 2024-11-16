#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	
	int sum=0; 
	
	for(int i=1;i<=n;i++)	
	{
		int x,y;
		cin>>x>>y;
		sum+=x*y;
	}
	
	cout<<max(0,sum);
	return 0;
} 
