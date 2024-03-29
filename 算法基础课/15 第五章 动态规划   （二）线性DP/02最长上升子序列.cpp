#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

int n; 

int a[N];
int f[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int res=1;
	
	for(int i=1;i<=n;i++)f[i]=1;
	
	for(int i=0;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[i]>a[j])f[i]=max(f[i],f[j]+1),res=max(res,f[i]);
			
	cout<<res;
	return 0;
}
