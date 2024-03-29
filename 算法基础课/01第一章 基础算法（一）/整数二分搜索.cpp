#include<iostream>
using namespace std;
int n,m;
const int N=1000010;
int q[N];
//integer binarysearch template
void binarysearch(int x,int q[],int n)
{
	int l,r;
	//determine the left boundary
	l=0,r=n-1;
	while(l<r)
	{
		int mid =l+r>>1;
		if(q[l]>=x)r=mid;
		else l=mid+1;
	}
	if(q[l]!=x)cout<<"error"<<endl;
	else cout<<l<<" ";
	//determine the right boundary
	l=0,r=n-1;
	while(l<r)
	{
		int mid=l+r+1>>1;//+1 is very important becase of the boundary problem
		if(q[l]<=x)l=mid;
		else r=mid-1;
	}
	if(q[l]==x)cout<<l;
}
int main()
{
	return 0;
}
