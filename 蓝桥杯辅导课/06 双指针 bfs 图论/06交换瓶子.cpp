#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5;

int a[N];

int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]==a[j])
				{
					swap(a[i],a[j]);
					res++;
				}
			}
		}
	}
	cout<<res;
	return 0;
}
