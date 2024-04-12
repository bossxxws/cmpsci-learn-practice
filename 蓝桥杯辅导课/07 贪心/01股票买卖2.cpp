#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int a[N];

typedef long long LL;

int n;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);//这个股票第i天的价格 
	
	//看到第二天涨价就买，把能赚的都赚了
	
	LL res=0;
	
	for(int i=1;i<=n;i++)
	{
		if(i+1<=n)
		{
			int j=i+1;
			if(a[j]>a[i])
			{
				res+=(LL)a[j]-a[i];
			}
		}
		
	}
	cout<<res;
	return 0;
}
