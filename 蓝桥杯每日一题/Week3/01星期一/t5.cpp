#include<bits/stdc++.h>

using namespace std;

const int N=1e5;

int a[N];

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n,greater<int>());
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "; 
	}
	
	return 0;
}
