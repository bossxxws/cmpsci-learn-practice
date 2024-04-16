#include<bits/stdc++.h>

using namespace std;

const int N=200000+5;

typedef long long LL;

int a[N];

int main()
{
	int n;
	cin>>n;
	
	LL sum=0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=(LL)a[i];
	}
	
	LL res=0;
	
	//每个数乘这个数以外的所有数字的和 
	
	for(int i=0;i<n;i++)
	{
		res+=(LL)a[i]*(sum-a[i]);
	}
	
	//每个数都被乘了两次
	
	cout<<res/2; 
	
	return 0;
} 
