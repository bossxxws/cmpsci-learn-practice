#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=1e5+3;

int a[N];

int main()
{
	cin>>n;
	
	double mid;
	int b;
	int maxn=-1,minn=1e9;
	
	int l1,l2,l;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	maxn=a[n];
	minn=a[1];
	int sum;
	if(n%2==0)
	{
		l1=n/2;
		l2=n/2+1;
		sum=a[l1]+a[l2];
		if(sum%2!=0)mid=(double)(a[l1]+a[l2])/2;
		else b=(a[l1]+a[l2])/2;
	}
	else
	{
		l=n/2+1;
		b=a[l];
	}
	
	cout<<maxn<<" ";
	if(sum%2)printf("%.1f",mid);
	else cout<<b;
	cout<<" "<<minn;
	
	return 0;
} 
