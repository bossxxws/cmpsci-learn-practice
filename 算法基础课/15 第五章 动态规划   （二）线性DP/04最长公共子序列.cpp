#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int q[N];

int a[N]; 

int n;
/*

7
3 1 2 1 8 5 6

4

*/
int main()
{
	cin>>n;	
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	q[0]=2e9;
	int l,r;
	int len=0;
	for(int i=0;i<n;i++)
	{
		
		l=0,r=len;
		//二分模板 
		
		//二分出队列中能插入的最小的位置 
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(q[mid]<a[i])l=mid;
			else r=mid-1; 
		}
		//cout<<q[r]<<endl;
		q[r+1]=a[i];

		len=max(len,r+1);
		//for(int i=1;i<=len;i++)cout<<q[i]<<" ";
		//cout<<endl;
	}
	
	cout<<len;
	
	return 0;
 } 
