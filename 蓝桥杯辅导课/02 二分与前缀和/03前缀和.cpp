#include<bits/stdc++.h>

using namespace std;

const int N=100000+10;

int n,m; 
int a[N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)a[i]+=a[i-1]; 
	
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		
		cout<<a[r]-a[l-1]<<endl; 
		
		
	}
	return 0;
} 
