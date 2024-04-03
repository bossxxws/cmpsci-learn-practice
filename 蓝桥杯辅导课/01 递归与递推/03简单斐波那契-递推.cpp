#include<bits/stdc++.h>

using namespace std;

int f[47];

int main()
{
	int n;
	cin>>n;
	f[1]=1,f[2]=1;
	for(int i=3;i<n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}
