#include<iostream>
using namespace std;
//array's name is already the address of array
//so we do not need to use &
//if we use &,there will be error(because that will be address's address)

void quick_sort(int q[],int l,int r)
{
	if (l >= r)return;
	int i=l-1;
	int j=r+1;
	int x=q[l];

	while(i<j)
	{
		//do i++¡¡first 
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]); 
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}
/*
void quick_sort(int q[],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	int x=q[(l+r)>>1];
	int i=l-1;
	int j=r+1;
	while(i<j)
	{
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}
*/ 
int main()
{
	int k[]={2,3,3,4,1,26,3213213,4443,54,33,43};
	int n=sizeof(k)/sizeof(k[0]);
	quick_sort(k,0,n-1);
	for (int i = 0; i < n; i++) 
	{
		cout << k[i] << " ";
	}
	return 0;
}
