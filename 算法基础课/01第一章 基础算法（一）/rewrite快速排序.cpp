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

int cnt;

void quicksort(int q[],int l,int r)
{
	if(l>=r)return;
	int x=q[l+r>>1];
	int i=l-1;
	int j=r+1;
	while(i<j)
	{
		do i++,cnt++;while(q[i]<x);
		do j--,cnt++;while(q[j]>x);
		cnt-=2;
		if(i<j)swap(q[i],q[j]);
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}

int main()
{
	//int k[]={4,1,2,3,5,6,7,8};
    //int k[]={4,2,1,3,6,5,7,8};
    
	//int k[]={8,7,6,5,4,3,2,1};
	//int k[]={1,2,3,4,5,6,7,8};
	
	int n=sizeof(k)/sizeof(k[0]);
	quicksort(k,0,n-1);
	
	//cout<<"int k[]={4,1,2,3,5,6,7,8}的比较次数： "<<cnt<<endl;
	//cout<<"int k[]={4,2,1,3,6,5,7,8}的比较次数： "<<cnt<<endl;
	
	//cout<<"int k[]={8,7,6,5,4,3,2,1}的比较次数： "<<cnt<<endl;
	//cout<<"int k[]={1,2,3,4,5,6,7,8}的比较次数： "<<cnt<<endl;
	for (int i = 0; i < n; i++) 
	{
		cout << k[i] << " ";
	}
	return 0;
}
