#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;

int n,k;

int tt=-1,hh;
int dq[N],a[N];

int main()
{
	cin>>n>>k;
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	//求窗口最小值 
	for(int i=0;i<n;i++)
	{
		while(hh<=tt && a[i]<dq[tt])tt--;

		dq[++tt]=a[i];
		
		//
		if(i-k>=0 && dq[hh]==a[i-k])hh++;
		
		//队头一定是最小的
		if(i+1>=k)cout<<dq[hh]<<" "; 
	}	
	cout<<endl;
	
	//求最大值
	tt=-1,hh=0;
	for(int i=0;i<n;i++)
	{
		while(hh<=tt && a[i]>dq[tt])tt--;
		
		dq[++tt]=a[i];
		
		if(i-k>=0 && dq[hh]==a[i-k])hh++;
		
		if(i+1>=k)cout<<dq[hh]<<" ";	
		
	} 
	return 0;
}
