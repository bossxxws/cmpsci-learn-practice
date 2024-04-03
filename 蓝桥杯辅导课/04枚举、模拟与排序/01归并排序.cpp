#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n;

int a[N];
int tmp[N];


void mergesort(int l,int r)
{
	if(l>=r)return ;
	int mid =l+r>>1;
	int i=l,j=mid+1,k=0;
	mergesort(l,mid),mergesort(mid+1,r);
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j])
		{
			tmp[k++]=a[i++];	
		} 
		else
		{
			tmp[k++]=a[j++]; 
		}
	}
	while(i<=mid)
	{
		tmp[k++]=a[i++];
	}
	while(j<=r)
	{
		tmp[k++]=a[j++];
	}
	for(int i=l,j=0;j<k;j++,i++)
	{
		a[i]=tmp[j];	
	} 
}

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	mergesort(1,n);
	
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	
	return 0;
}
