#include<iostream>
using namespace std;
const int N=1000010;
int tem[N];
void mergesort(int q[],int l,int r)
{
	if(l>=r)return;
	int mid = (l+r)>>1;
	mergesort(q,l,mid),mergesort(q,mid+1,r);
	int k = 0,i = l,j = mid+1;
	while(i<=mid && j<=r)
	{
		if(q[i]<=q[j])tem[k++]=q[i++];
		else tem[k++]=q[j++];
	}
	while(i<=mid)
	{
		tem[k++]=q[i++];
	}
	while(j<=r)
	{
		tem[k++]=q[j++];
	}
	for(int i=l,j=0;i<=r;i++,j++)
	{
		q[i]=tem[j];
	}
}
int main()
{
	int q[]={2,3,3,4,1,26,3213213,4443,54,1111136543,43};
	int n=sizeof(q)/sizeof(q[0]);
	mergesort(q,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<q[i]<<" ";
	}
	return 0;
}
