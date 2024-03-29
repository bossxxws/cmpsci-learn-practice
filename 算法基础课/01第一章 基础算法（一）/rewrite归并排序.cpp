#include<iostream>
using namespace std;
const int N=1000010;
int tmp[N];
void quicksort(int q[],int l,int r)
{
	if(l>=r)return;
	int i=l-1;
	int j=r+1;
	int x=q[(l+r)>>1];
	while(i<j)
	{
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}

void mergesort(int q[],int l,int r)
{
	if(l>=r)
	{
		return ;
	}
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
	for(int i=l,j=0;i<=r;i++,j++)
	{
		q[i]=tmp[j];
	}	
}
int main()
{
	int q[]={2323,323,111,321,3333};
	int n=sizeof(q)/sizeof(q[0]);
	quicksort(q,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
	cout<<q[-255];
	return 0;
}
