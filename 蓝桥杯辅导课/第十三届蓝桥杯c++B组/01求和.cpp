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
	
	//ÿ�����������������������ֵĺ� 
	
	for(int i=0;i<n;i++)
	{
		res+=(LL)a[i]*(sum-a[i]);
	}
	
	//ÿ����������������
	
	cout<<res/2; 
	
	return 0;
} 
