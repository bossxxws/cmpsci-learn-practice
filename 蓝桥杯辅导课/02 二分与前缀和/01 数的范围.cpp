#include<bits/stdc++.h>

using namespace std;

const int N=100000+10;

int a[N];

int n,q; 

int main()
{
	cin>>n>>q;
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	while(q--)
	{
		int x;
		cin>>x;
		
		//二分开搜！ 
		int l=0,r=n-1;
		//先求左边界 
		while(l<r)
		{
			int mid=l+r>>1;
			if(a[mid]>=x)r=mid;
			else l=mid+1;
		}
		if(a[r]==x)
		{
			cout<<r<<" ";
			l=0,r=n-1;
			while(l<r)
			{
				int mid=l+r+1>>1;
				if(a[mid]<=x)l=mid;
				else r=mid-1;
			}
			cout<<r<<endl;
		}
		else cout<<-1<<" "<<-1<<endl;
		
	}
	return 0;
}
