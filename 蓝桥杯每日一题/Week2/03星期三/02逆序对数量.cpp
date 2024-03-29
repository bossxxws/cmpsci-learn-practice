#include<bits/stdc++.h>

using namespace std;

const int N =1e5+5;

int q[N],tmp[N];

typedef long long LL;

LL mergesort(int q[],int l,int r)
{
	if(r<=l)return 0;
	LL res=0;
	int mid=(l+r)>>1;
	res+=mergesort(q,l,mid)+mergesort(q,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(q[i]<=q[j])tmp[k++]=q[j];
		else
		{
		    tmp[k++]=q[i];
		    res+=mid-i+1;
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
	
	for(int i=l,j=0;i<=r;i++,j++)
	{
		q[i]=tmp[j];
	}
	return res;
}
int main()
{
    int n;
    cin>>n;
   
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    
    LL res=mergesort(q,0,n-1);
    
    cout<<res;
    
    
    return 0;
}
