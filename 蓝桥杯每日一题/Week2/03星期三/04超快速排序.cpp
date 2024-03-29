#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=5e5+5;

LL n,m;
LL q[N],tmp[N];

LL merge(int l,int r)
{
	if(r<=l)return 0;
	LL res=0;
	LL mid=(l+r)>>1;
	res+=merge(l,mid);res+=merge(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(q[i]<=q[j])tmp[k++]=q[i++];
		else
		{
			tmp[k++]=q[j++];
			res+=(LL)mid-i+1;
		}
	}
	
	while(i<=mid)
	{
		tmp[k++]=q[i++];
	}
	
	while(j<=r)
	{
		tmp[k++]=q[j++];	
	}
	
	for(int i=l,j=0;i<=r;j++,i++)
	{
		q[i]=tmp[j];
	}
	return res;
	
}

int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)cin>>q[i];
		LL res=0;
		res+=merge(0,n-1);
		
		cout<<res<<endl;
	}
	
	return 0;
}
