#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=1003;

int a[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	//统计连续段的个数
	int cnt=0;
	for(int i=1;i+1<=n;i++)
	{
		if(a[i]!=a[i+1])cnt++;	
	} 
	
	cout<<cnt+1;
	return 0; 
} 
