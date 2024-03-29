#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int q[N],tmp[N];

void mergesort(int q[],int l,int r)
{
	if(r<=l)return;
	int mid=(l+r)>>1;
	mergesort(q,l,mid);mergesort(q,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(q[i]<=q[j])tmp[k++]=q[j++];
		else tmp[k++]=q[i++];
	}
	while(i<=mid)
	{
		tmp[k++]=q[i++];
	}
	while(j<=r)
	{
		tmp[k++]=q[j++];
	}
	//cout<<"yes"<<endl;
	for(int i=l,j=0;i<=r;i++,j++)
	{
	    //cout<<q[i]<<endl;
		q[i]=tmp[j];//q不一定是从0开始的（但一定是从l），tmp一定是从0开始的 
	}
}


int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&q[i]);
	}
	
	mergesort(q,0,n-1);
	
	for(int i=n-1;i>=0;i--)printf("%d ",q[i]);
	
	return 0;
}
