#include<bits/stdc++.h>

using namespace std;
int res;
int n,k; 

const int N=1003;
int a[N];
int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		t+=a[i];
		if(t>=k)
		{
			res++;
			t=0;
		}
	}
	
	if(t!=0)res++;
	
	cout<<res;
	
	return 0;
} 
