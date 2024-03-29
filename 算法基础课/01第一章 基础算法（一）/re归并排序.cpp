#include<iostream>
using namespace std;
const int N=1000010;
int tmp[N];
void mergesort(int q[],int l,int r)
{
	if(l>=r)return;
	int mid=(l+r)>>1;
	mergesort(q,l,mid),mergesort(q,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j])tmp[k++]=q[i++];
		else tmp[k++]=q[j++];
	}
	while(i<=mid)tmp[k++]=q[i++];
	while(j<=r)tmp[k++]=q[j++];
	for(int i=l,j=0;i<r;i++,j++)
	{
		q[i]=tmp[j];
	}
}
int main()
{
	int k[]={3213,76556765,452435,987,432,867,8,768,645};
	int n=sizeof(k)/sizeof(k[0]);
	mergesort(k,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<k[i]<<" ";
	}
	return 0;
}
