#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int a[N];

int f[N];

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=a[i];
	}
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j])f[i]=max(f[i],f[j]+a[i]);
		}
	
	int res=-1;
	
	for(int i=1;i<=n;i++)res=max(res,f[i]);
	
	cout<<res;
	
	return 0;
}
