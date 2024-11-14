#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int a[N];
int n; 

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int smx=0,smn=0;
	int last=a[1];
	bool f;
	for(int i=1;i<=n;i++)
	{

		//最大值的情况
		smx+=max(a[i],last);
		
		//最小值的情况 
		if(a[i]>last || i==1)
		{
			smn+=a[i]; 
		}
		last=max(last,a[i]);
	} 
	cout<<smx;
	cout<<endl<<smn;
	return 0;
}
