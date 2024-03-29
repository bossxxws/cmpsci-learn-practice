//一开始没想到可以天气坏那边画哪边，不相信是[n/2]上取整的子数组中的最大值就是答案
#include<bits/stdc++.h>

using namespace std;

int t,n;

const int N=5*1e6+5;

char a[N];
int s[N];

int main()
{
	cin>>t;
	int c=1;
	while(t--)
	{
		
		//cout<<"-------"<<endl;
		
		int m;
		cin>>m;
		
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		
		//cout<<"-------"<<endl;
		
		for(int i=1;i<=m;i++)
		{
			s[i]=s[i-1]+(a[i]-'0');
		}
		
		int cnt=(m+1)/2;
		int maxs=-1;
		
		for(int i=1;i<=m-cnt+1;i++)
		{
			//计算i到j的区间壁画合 
			int j=i+cnt-1;//注意要减去1，因为直接加上会导致多一块壁画 
			maxs=max(maxs,s[j]-s[i-1]);
		}
		cout<<"Case #"<<c<<": "<<maxs<<endl;
		c++;
	}
	
	return 0;
}
