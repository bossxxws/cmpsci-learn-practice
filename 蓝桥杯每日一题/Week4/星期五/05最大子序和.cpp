#include<bits/stdc++.h>

using namespace std;

const int N=300000+10;

int n,m; 

long long  s[N];

int q[N],hh=-1,tt;

int main()
{
	cin>>n>>m;
	
	//前缀和 
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]+=s[i-1];
	}
	
	long long res=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		//判断是否滑出窗口 
		if(hh<=tt && q[hh]<=i-m-1)hh++;
		
		res=max(res,s[i]-s[q[hh]]);
		
		//s[q[tt]] 即将被减去，当然是越小越好 
		//如果s[i](前i个数的和)小于s[q[tt]](前面的前缀和)
		//那么s[i]更适合被减去来求后面的前缀和 
		while(hh<=tt && s[q[tt]]>=s[i])tt--;
		
		//当前点入队 
		q[++tt]=i;
				
	}
	cout<<res;
	return 0;
} 
