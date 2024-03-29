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
void quicksort(int q[],int l,int r)
{
	if(l>=r)return;
	int x=q[l+r>>1];
	int i=l-1;
	int j=r+1;
	while(i<j)
	{
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}
int main()
{
	int k[]={2,3,3,4,1,26,3213213,4443,54,1111136543,43};
	int n=sizeof(k)/sizeof(k[0]);
	quicksort(k,0,n-1);
	for (int i = 0; i < n; i++) 
	{
		cout << k[i] << " ";
	}
	return 0;
}
