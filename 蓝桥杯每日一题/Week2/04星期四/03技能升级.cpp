#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

typedef long long LL;

int n,m;

LL a[N],b[N];

bool check(int mid) 
{
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=mid)sum+=(LL)(a[i]-mid)/b[i]+1;
		
	}
	return sum>=m;
}
int main()
{
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	
	LL l=0,r=1e6;
	
	while(l<r)
	{
		LL mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else  r=mid-1;
	}
	
	LL res=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
	    if(a[i]>r)
	    {
	        LL c=(a[i]-r)/b[i]+1;
    		LL ed=a[i]+(-1)*(c-1)*b[i];//an = a1+(n-1)d
    		LL sum=(a[i]+ed)*c/2;
    		res+=(LL)sum;
    		cnt+=c;//加了多少次
	    }
	}
	cout<<res-(cnt-m)*r;
	return 0;
} 
